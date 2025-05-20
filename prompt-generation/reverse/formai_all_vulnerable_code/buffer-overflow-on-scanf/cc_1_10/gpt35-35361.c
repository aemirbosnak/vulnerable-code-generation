//FormAI DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Struct for our database entries
typedef struct {
    int id;
    char name[100];
    int age;
    double salary;
} Employee;

int main() {
    Employee database[100];
    int entryCount = 0; // Keeps track of number of entries in database

    int choice = 1;
    while (choice != 0) {
        printf("\n--- Database Menu ---\n");
        printf("1. Add entry\n");
        printf("2. Search by ID\n");
        printf("3. Display all entries\n");
        printf("0. Exit\n");
        printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting program...\n");
                break;

            case 1:
                // Get input from user to create new entry
                printf("\nEnter employee ID: ");
                scanf("%d", &database[entryCount].id);
                printf("Enter employee name: ");
                scanf("%s", database[entryCount].name);
                printf("Enter employee age: ");
                scanf("%d", &database[entryCount].age);
                printf("Enter employee salary: ");
                scanf("%lf", &database[entryCount].salary);

                entryCount++; // Increment entry count
                printf("\nEntry added successfully.\n");
                break;

            case 2:
                // Get input from user to search for an entry by ID
                printf("\nEnter employee ID: ");
                int searchID;
                scanf("%d", &searchID);
                
                // Loop through entries to find matching ID
                for (int i = 0; i < entryCount; i++) {
                    if (database[i].id == searchID) {
                        printf("ID: %d | Name: %s | Age: %d | Salary: $%.2lf\n", database[i].id, database[i].name, database[i].age, database[i].salary);
                        break;
                    } else if (i == entryCount - 1) {
                        printf("No entry found with that ID.\n");
                    }
                }
                break;

            case 3:
                // Loop through all entries and print them
                printf("\nID\tName\tAge\tSalary\n");
                
                for (int i = 0; i < entryCount; i++) {
                    printf("%d\t%s\t%d\t$%.2lf\n", database[i].id, database[i].name, database[i].age, database[i].salary);
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}