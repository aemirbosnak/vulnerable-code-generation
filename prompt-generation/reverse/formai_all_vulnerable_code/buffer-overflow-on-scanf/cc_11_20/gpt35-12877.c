//FormAI DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    Person database[100];
    int num_entries = 0;
    int choice, id, i;

    while (1) {
        printf("\n\nDatabase Simulation\n");
        printf("1) Add Person\n");
        printf("2) Search by ID\n");
        printf("3) Display All Persons\n");
        printf("4) Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries == 100) {
                    printf("Database Full!\n");
                    break;
                }

                printf("\nEnter ID: ");
                scanf("%d", &database[num_entries].id);
                printf("Enter Name: ");
                scanf("%s", database[num_entries].name);
                printf("Enter Age: ");
                scanf("%d", &database[num_entries].age);

                num_entries++;
                printf("\nPerson Added!\n");
                break;

            case 2:
                printf("\nEnter ID: ");
                scanf("%d", &id);

                for (i = 0; i < num_entries; i++) {
                    if (database[i].id == id) {
                        printf("\nID: %d\nName: %s\nAge: %d\n", 
                            database[i].id, database[i].name, database[i].age);
                        break;
                    }
                }

                if (i == num_entries) {
                    printf("\nPerson Not Found!\n");
                }

                break;

            case 3:
                printf("\nAll Persons:\n");

                for (i = 0; i < num_entries; i++) {
                    printf("\nID: %d\nName: %s\nAge: %d\n", 
                        database[i].id, database[i].name, database[i].age);
                }

                break;

            case 4:
                printf("\nExiting Database.........................................\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }

    return 0;
}