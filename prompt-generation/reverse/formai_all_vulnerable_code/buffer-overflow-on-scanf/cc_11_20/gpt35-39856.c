//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_LENGTH 50

typedef struct {
    int id;
    char name[MAX_LENGTH];
    int age;
    char address[MAX_LENGTH];
} Person;

int main() {
    Person database[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        printf("DATABASE SIMULATION\n");
        printf("--------------------\n");
        printf("1. Add a person\n");
        printf("2. Search for a person\n");
        printf("3. Display all people in database\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (count == MAX_RECORDS) {
                    printf("Database is full.\n");
                    break;
                }

                Person person;
                printf("Enter name: ");
                scanf("%s", person.name);
                printf("Enter age: ");
                scanf("%d", &person.age);
                printf("Enter address: ");
                scanf("%s", person.address);

                person.id = count;
                database[count] = person;
                count++;

                printf("Person added to database.\n");
                break;
            }

            case 2: {
                if (count == 0) {
                    printf("Database is empty.\n");
                    break;
                }

                char search_name[MAX_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", search_name);

                for (int i = 0; i < count; i++) {
                    Person person = database[i];

                    if (strcmp(person.name, search_name) == 0) {
                        printf("ID: %d\n", person.id);
                        printf("Name: %s\n", person.name);
                        printf("Age: %d\n", person.age);
                        printf("Address: %s\n", person.address);
                        break;
                    }

                    if (i == count - 1) {
                        printf("Person not found.\n");
                    }
                }

                break;
            }

            case 3: {
                if (count == 0) {
                    printf("Database is empty.\n");
                    break;
                }

                for (int i = 0; i < count; i++) {
                    Person person = database[i];
                    printf("ID: %d\n", person.id);
                    printf("Name: %s\n", person.name);
                    printf("Age: %d\n", person.age);
                    printf("Address: %s\n", person.address);
                    printf("--------------------\n");
                }

                break;
            }

            case 4: {
                printf("Exiting program...\n");
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}