//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

int main() {

    Record records[MAX_RECORDS];
    int numRecords = 0;

    while(1) {
        printf("1. Add record\n");
        printf("2. View record\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                Record record;
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter age: ");
                scanf("%d", &record.age);

                // Assign the next available id
                record.id = numRecords + 1;

                // Add the record to the array
                records[numRecords++] = record;

                printf("Record added successfully.\n");
                break;
            }
            case 2: {
                int id;
                printf("Enter id: ");
                scanf("%d", &id);

                // Find the record with the given id
                int index = -1;
                for(int i = 0; i < numRecords; i++) {
                    if(records[i].id == id) {
                        index = i;
                        break;
                    }
                }

                if(index == -1) {
                    printf("Record not found.\n");
                    break;
                }

                // Display the record
                printf("Name: %s\n", records[index].name);
                printf("Age: %d\n", records[index].age);
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                exit(0);
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}