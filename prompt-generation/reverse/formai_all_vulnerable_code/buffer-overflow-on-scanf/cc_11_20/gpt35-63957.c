//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Struct for the database
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

int main() {
    // Initializing the database with MAX_SIZE
    Person database[MAX_SIZE];
    int count = 0;

    while (1) {
        // Prompt the user to enter a command
        printf("\nEnter a command (add, delete, view, quit): ");

        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            // Adding a new person to the database
            if (count < MAX_SIZE) {
                Person person;
                printf("Enter the person's ID: ");
                scanf("%d", &person.id);
                printf("Enter the person's name: ");
                scanf("%s", person.name);
                printf("Enter the person's age: ");
                scanf("%d", &person.age);

                database[count] = person;
                count++;
            }
            else {
                printf("The database is full.\n");
            }
        }
        else if (strcmp(command, "delete") == 0) {
            // Deleting a person from the database
            printf("Enter the ID of the person you would like to delete: ");
            int id;
            scanf("%d", &id);

            int found = 0;
            for (int i = 0; i < count; i++) {
                if (database[i].id == id) {
                    found = 1;
                    for (int j = i; j < count - 1; j++) {
                        database[j] = database[j+1];
                    }
                    count--;
                    break;
                }
            }

            if (!found) {
                printf("Person with ID %d not found in the database.\n", id);
            }
            else {
                printf("Person with ID %d deleted from the database.\n", id);
            }
        }
        else if (strcmp(command, "view") == 0) {
            // Viewing the entire database
            printf("\n ID | Name | Age\n");
            printf("--- | ---- | ---\n");
            for (int i = 0; i < count; i++) {
                printf("%3d | %-20s | %d\n", database[i].id, database[i].name, database[i].age);
            }
        }
        else if (strcmp(command, "quit") == 0) {
            // Exiting the program
            printf("Exiting the database program...\n");
            break;
        }
        else {
            printf("%s is not a valid command.\n", command);
        }
    }

    return 0;
}