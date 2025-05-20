//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print menu options
void print_menu(){
    printf("\n--- C DATABASE SIMULATION ---\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Print All Records\n");
    printf("4. Update Record\n");
    printf("5. Delete Record\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
}

// Define structure for the record
struct Record {
    int id;
    char name[50];
    int age;
    char gender[10];
};

// Declare an array to hold records
struct Record records[100];

// Declare a variable to keep track of number of records
int num_records = 0;

int main() {

    int choice, i, id, flag;
    char name[50], gender[10];
    int age;

    while(1){
        print_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Add Record
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strlen(name)-1] = '\0';
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Gender: ");
                getchar();
                fgets(gender, sizeof(gender), stdin);
                gender[strlen(gender)-1] = '\0';
                records[num_records].id = id;
                strcpy(records[num_records].name, name);
                records[num_records].age = age;
                strcpy(records[num_records].gender, gender);
                num_records++;
                printf("Record Added Successfully!\n");
                break;
            
            case 2:
                // Search Record
                printf("Enter ID to Search: ");
                scanf("%d", &id);
                flag = 0;
                for(i=0;i<num_records;i++){
                    if(records[i].id == id){
                        printf("\nRecord Found\n\n");
                        printf("ID: %d\n", records[i].id);
                        printf("Name: %s\n", records[i].name);
                        printf("Age: %d\n", records[i].age);
                        printf("Gender: %s\n", records[i].gender);
                        flag = 1;
                    }
                }
                if(flag == 0){
                    printf("\nRecord Not Found\n");
                }
                break;

            case 3:
                // Print All Records
                printf("\n---All Records---\n\n");
                printf("ID\tName\tAge\tGender\n");
                for(i=0;i<num_records;i++){
                    printf("%d\t%s\t%d\t%s\n", records[i].id, records[i].name, records[i].age, records[i].gender);
                }
                break;

            case 4:
                // Update Record
                printf("Enter ID to Update: ");
                scanf("%d", &id);
                flag = 0;
                for(i=0;i<num_records;i++){
                    if(records[i].id == id){
                        printf("\nRecord Found\n\n");
                        printf("ID: %d\n", records[i].id);
                        printf("Name: %s\n", records[i].name);
                        printf("Age: %d\n", records[i].age);
                        printf("Gender: %s\n", records[i].gender);
                        printf("\nEnter New Details\n");
                        printf("Enter Name: ");
                        getchar();
                        fgets(name, sizeof(name), stdin);
                        name[strlen(name)-1] = '\0';
                        printf("Enter Age: ");
                        scanf("%d", &age);
                        printf("Enter Gender: ");
                        getchar();
                        fgets(gender, sizeof(gender), stdin);
                        gender[strlen(gender)-1] = '\0';
                        records[i].id = id;
                        strcpy(records[i].name, name);
                        records[i].age = age;
                        strcpy(records[i].gender, gender);
                        printf("\nRecord Updated Successfully!\n");
                        flag = 1;
                    }
                }
                if(flag == 0){
                    printf("\nRecord Not Found\n");
                }
                break;

            case 5:
                // Delete Record
                printf("Enter ID to Delete: ");
                scanf("%d", &id);
                flag = 0;
                for(i=0;i<num_records;i++){
                    if(records[i].id == id){
                        printf("\nRecord Found\n\n");
                        printf("ID: %d\n", records[i].id);
                        printf("Name: %s\n", records[i].name);
                        printf("Age: %d\n", records[i].age);
                        printf("Gender: %s\n", records[i].gender);
                        printf("\nAre you sure you want to delete this record? (y/n) ");
                        char confirm;
                        fflush(stdin);
                        scanf(" %c", &confirm);
                        if(confirm == 'y' || confirm == 'Y'){
                            for(int j=i;j<num_records-1;j++)
                                records[j] = records[j+1];
                            num_records--;
                            printf("\nRecord Deleted Successfully!\n");
                        }
                        else{
                            printf("\nRecord Not Deleted\n");
                        }
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("\nRecord Not Found\n");
                }
                break;

            case 6:
                // Exit
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}