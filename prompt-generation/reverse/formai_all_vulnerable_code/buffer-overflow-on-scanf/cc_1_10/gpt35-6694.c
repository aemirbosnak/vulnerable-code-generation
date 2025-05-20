//FormAI DATASET v1.0 Category: Database simulation ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct{
    int id;
    char name[20];
    int age;
} Record;

int main(){
    Record records[MAX_SIZE];
    int num_records = 0;
    int choice;

    while(1){
        printf("C Database Simulation\n");
        printf("=====================\n");
        printf("Number of records: %d\n", num_records);
        printf("1. Add new record\n");
        printf("2. Search record by ID\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");

        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter record ID: ");
                scanf("%d", &records[num_records].id);

                printf("Enter record name: ");
                scanf("%s", records[num_records].name);

                printf("Enter record age: ");
                scanf("%d", &records[num_records].age);

                printf("Record added successfully!\n\n");
                num_records++;
                break;

            case 2:
                printf("\nEnter record ID to search: ");
                int search_id;
                scanf("%d", &search_id);

                int found = 0;
                for(int i=0; i<num_records; i++){
                    if(records[i].id == search_id){
                        printf("\nRecord found:\n");
                        printf("ID: %d\nName: %s\nAge: %d\n\n", records[i].id, records[i].name, records[i].age);
                        found = 1;
                        break;
                    }
                }

                if(!found){
                    printf("\nRecord with ID %d not found.\n\n", search_id);
                }
                break;

            case 3:
                printf("\nAll records:\n");
                printf("ID\tName\tAge\n");
                for(int i=0; i<num_records; i++){
                    printf("%d\t%s\t%d\n", records[i].id, records[i].name, records[i].age);
                }
                printf("\n");
                break;

            case 4:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }
    return 0;
}