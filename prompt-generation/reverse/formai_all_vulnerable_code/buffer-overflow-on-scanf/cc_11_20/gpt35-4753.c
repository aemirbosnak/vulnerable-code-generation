//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
/* C Database Simulation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for database entry */
struct Entry {
    char name[50];
    int age;
    double salary;
};

int main() {
    /* Create database of entries */
    struct Entry database[100];
    int numEntries = 0;

    /* Menu loop */
    while (1) {
        printf("1. Add an Entry\n");
        printf("2. Delete an Entry\n");
        printf("3. Print the Database\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        /* Get user input */
        int choice;
        scanf("%d", &choice);

        /* Add an Entry */
        if (choice == 1) {
            struct Entry newEntry;

            printf("\nEnter name: ");
            scanf("%s", newEntry.name);

            printf("Enter age: ");
            scanf("%d", &newEntry.age);

            printf("Enter salary: ");
            scanf("%lf", &newEntry.salary);

            database[numEntries] = newEntry;
            numEntries++;
            printf("Entry added successfully!\n");
        }

        /* Delete an Entry */
        else if (choice == 2) {
            printf("\nEnter name of Entry to delete: ");
            char name[50];
            scanf("%s", name);

            int entryIndex = -1;
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(database[i].name, name) == 0) {
                    entryIndex = i;
                    break;
                }
            }

            if (entryIndex == -1) {
                printf("Entry not found.\n");
            } else {
                for (int i = entryIndex; i < numEntries - 1; i++) {
                    database[i] = database[i+1];
                }
                numEntries--;
                printf("Entry deleted successfully!\n");
            }
        }

        /* Print the Database */
        else if (choice == 3) {
            printf("\nNAME\tAGE\tSALARY\n");
            for (int i = 0; i < numEntries; i++) {
                printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].salary);
            }
        }

        /* Quit */
        else if (choice == 4) {
            printf("\nGoodbye!\n");
            break;
        }

        /* Invalid input */
        else {
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}