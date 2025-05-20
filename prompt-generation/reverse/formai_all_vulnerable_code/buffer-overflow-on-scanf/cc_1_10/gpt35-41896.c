//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Person {
    char name[50];
    int age;
    char address[100];
};

int main() {
    struct Person database[MAX_SIZE];
    int count = 0;
    int option = 0;

    do {
        printf("Please choose an option:\n");
        printf("1. Add a new person to the database\n");
        printf("2. Search for a person in the database\n");
        printf("3. View all people in the database\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the person's name: ");
                scanf("%s", &database[count].name);

                printf("Enter the person's age: ");
                scanf("%d", &database[count].age);

                printf("Enter the person's address: ");
                scanf("%s", &database[count].address);

                printf("New person added to the database!\n");
                count++;
                break;

            case 2:
                printf("Enter the person's name to search for: ");
                char search_name[50];
                scanf("%s", &search_name);

                int found = 0;

                for (int i = 0; i < count; i++) {
                    if (strcmp(search_name, database[i].name) == 0) {
                        found = 1;

                        printf("Name: %s\n", database[i].name);
                        printf("Age: %d\n", database[i].age);
                        printf("Address: %s\n", database[i].address);

                        break;
                    }
                }

                if (!found) {
                    printf("Person not found in the database.\n");
                }

                break;

            case 3:
                printf("People in the database:\n");

                for (int i = 0; i < count; i++) {
                    printf("Name: %s\n", database[i].name);
                    printf("Age: %d\n", database[i].age);
                    printf("Address: %s\n", database[i].address);
                    printf("\n");
                }

                break;

            case 4:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    } while (option != 4);

    return 0;
}