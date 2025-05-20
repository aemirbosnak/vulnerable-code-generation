//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000 //Maximum number of records that can be stored in database

//Structure to store records
typedef struct {
    int id;
    char name[20];
    char address[50];
    float salary;
} Record;

//Structure to store index
typedef struct {
    int id;
    int pos;
} Index;

int main() {

    int num_records = 0; //Counter to keep track of number of records
    Record database[MAX]; //Array to store records
    Index index[MAX]; //Array to store index
    int num_index = 0; //Counter to keep track of number of index entries
    
    int choice = 0; //Variable to store user's choice
    int id = 0; //Variable to store entered ID
    int pos = -1; //Variable to store position of record in database
    
    while(1) {
        printf("\n1. Add Record\n");
        printf("2. Search by ID\n");
        printf("3. Search by Name\n");
        printf("4. Search by Address\n");
        printf("5. Search by Salary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1: //Add Record
                if(num_records == MAX) {
                    printf("\nDatabase is full.\n");
                    break;
                }
                
                printf("\nEnter details of record:\n");
                printf("ID: ");
                scanf("%d", &database[num_records].id);
                printf("Name: ");
                scanf("%s", database[num_records].name);
                printf("Address: ");
                scanf("%s", database[num_records].address);
                printf("Salary: ");
                scanf("%f", &database[num_records].salary);
                
                //Add index entry
                index[num_index].id = database[num_records].id;
                index[num_index].pos = num_records;
                num_index++;
                
                //Sort index by ID
                for(int i=0;i<num_index-1;i++) {
                    for(int j=i+1;j<num_index;j++) {
                        if(index[i].id > index[j].id) {
                            //Swap
                            Index temp = index[i];
                            index[i] = index[j];
                            index[j] = temp;
                        }
                    }
                }
                
                num_records++;
                printf("\nRecord added successfully.\n");
                
                break;
                
            case 2: //Search by ID
                printf("\nEnter ID to search: ");
                scanf("%d", &id);
                
                //Binary search
                int first=0, last=num_index-1, middle=(first+last)/2;
                while(first <= last) {
                    if(index[middle].id == id) {
                        pos = index[middle].pos;
                        break;
                    }
                    else if(index[middle].id < id)
                        first = middle + 1;
                    else
                        last = middle - 1;
                    
                    middle = (first+last)/2;
                }
                
                if(pos == -1)
                    printf("\nRecord not found.\n");
                else {
                    printf("\nRecord found at position %d:\n", pos+1);
                    printf("ID: %d\n", database[pos].id);
                    printf("Name: %s\n", database[pos].name);
                    printf("Address: %s\n", database[pos].address);
                    printf("Salary: %.2f\n", database[pos].salary);
                }
                
                break;
                
            case 3: //Search by Name
                //To be implemented
                break;
                
            case 4: //Search by Address
                //To be implemented
                break;
                
            case 5: //Search by Salary
                //To be implemented
                break;
                
            case 6: //Exit
                exit(0);
                
            default:
                printf("\nInvalid choice.\n");
        }
    }
    
    return 0;
}