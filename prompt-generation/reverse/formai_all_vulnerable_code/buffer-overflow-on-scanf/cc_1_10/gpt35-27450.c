//FormAI DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <string.h>

// define the maximum number of records that can be stored
#define MAX_RECORDS 10

// define a record structure to store data
struct Record {
    int id;
    char name[20];
    int age;
    float salary;
};

// function to print a record
void printRecord(struct Record record) {
    printf("Record ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Salary: $%0.2f\n", record.salary);
}

int main() {
    struct Record database[MAX_RECORDS];
    int numRecords = 0;

    // menu options
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. View Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // add a record
                if (numRecords < MAX_RECORDS) {
                    struct Record newRecord;

                    printf("Enter ID: ");
                    scanf("%d", &newRecord.id);

                    printf("Enter Name: ");
                    scanf("%s", newRecord.name);

                    printf("Enter Age: ");
                    scanf("%d", &newRecord.age);

                    printf("Enter Salary: ");
                    scanf("%f", &newRecord.salary);

                    database[numRecords] = newRecord;
                    numRecords++;
                } else {
                    printf("Error: Database is full\n");
                }
                break;
            case 2:
                // view a record
                if (numRecords > 0) {
                    int id;
                    printf("Enter ID: ");
                    scanf("%d", &id);

                    int found = 0;
                    for (int i = 0; i < numRecords; i++) {
                        if (database[i].id == id) {
                            printRecord(database[i]);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Error: Record not found\n");
                    }
                } else {
                    printf("Error: Database is empty\n");
                }
                break;
            case 3:
                // exit program
                printf("Exiting program...\n");
                break;
            default:
                // invalid choice
                printf("Error: Invalid choice\n");
                break;
        }

    } while (choice != 3);

    return 0;
}