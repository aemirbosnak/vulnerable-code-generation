//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for holding database information
struct Database {
    int id;
    char name[20];
    char address[50];
    float salary;
};

//Function to read database information
void read_database(struct Database *db) {
    printf("Enter employee ID: ");
    scanf("%d", &db->id);
    printf("Enter employee name: ");
    scanf("%s", db->name);
    printf("Enter employee address: ");
    scanf("%s", db->address);
    printf("Enter employee salary: ");
    scanf("%f", &db->salary);
}

//Function to display database information
void display_database(struct Database db) {
    printf("\nEmployee ID: %d", db.id);
    printf("\nEmployee Name: %s", db.name);
    printf("\nEmployee Address: %s", db.address);
    printf("\nEmployee Salary: %.2f", db.salary);
}

//Main function
int main() {
    //Array of database structures
    struct Database db[5];
    int choice, i, id, flag = 0;
    
    while(1) {
        //Options menu
        printf("\n\n--Database Operations--");
        printf("\n1. Add Data");
        printf("\n2. Display Data");
        printf("\n3. Search Data");
        printf("\n4. Delete Data");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: //Adding data
                for(i = 0; i < 5; i++) {
                    if(db[i].id == 0) {
                        read_database(&db[i]);
                        printf("\nData added successfully!");
                        break;
                    }
                }
                if(i == 5) {
                    printf("\nDatabase is full!");
                }
                break;
                
            case 2: //Displaying data
                printf("\n--Database Contents--");
                for(i = 0; i < 5; i++) {
                    if(db[i].id != 0) {
                        display_database(db[i]);
                    }
                }
                break;
            
            case 3: //Searching data
                printf("\nEnter employee ID to search: ");
                scanf("%d", &id);
                for(i = 0; i < 5; i++) {
                    if(db[i].id == id) {
                        display_database(db[i]);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nData not found!");
                }
                break;
                
            case 4: //Deleting data
                printf("\nEnter employee ID to delete: ");
                scanf("%d", &id);
                for(i = 0; i < 5; i++) {
                    if(db[i].id == id) {
                        db[i].id = 0;
                        strcpy(db[i].name, "");
                        strcpy(db[i].address, "");
                        db[i].salary = 0;
                        flag = 1;
                        printf("\nData deleted successfully!");
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nData not found!");
                }
                break;
                
            case 5: //Exiting program
                printf("\nExiting program...");
                exit(0);
                
            default: //Invalid choice
                printf("\nInvalid choice!");
        }
    }
    return 0;
}