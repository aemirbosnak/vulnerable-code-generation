//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define DATABASE_SIZE 100

typedef struct {
   int id;
   char name[MAX_NAME_LENGTH];
   char email[MAX_EMAIL_LENGTH];
   char address[MAX_ADDRESS_LENGTH];
} User;

int main() {
    User database[DATABASE_SIZE];
    int count = 0;
    char option;

    while (1) {
        printf("------------------------------\n");
        printf(" Welcome to the User Database \n");
        printf("------------------------------\n");
        printf("Options:\n");
        printf("1. Add user\n");
        printf("2. Search user by ID\n");
        printf("3. Search user by name\n");
        printf("4. Display all users\n");
        printf("5. Quit\n");
        printf("Please select an option (1-5): ");

        scanf(" %c", &option);

        switch (option) {
            case '1':
                if (count >= DATABASE_SIZE) {
                    printf("Error: database is full\n");
                    break;
                }

                User user;
                user.id = count + 1;

                printf("\nAdd user to database:\n");
                printf("Name: ");
                scanf(" %[^\n]s", user.name);
                printf("Email: ");
                scanf(" %[^\n]s", user.email);
                printf("Address: ");
                scanf(" %[^\n]s", user.address);

                database[count] = user;
                count++;

                printf("\nUser added to database\n\n");
                break;

            case '2': {
                int search_id, found = 0;

                printf("\nEnter user ID: ");
                scanf("%d", &search_id);

                for (int i = 0; i < count; i++) {
                    if (database[i].id == search_id) {
                        printf("\nUser found:\n");
                        printf("Name: %s\n", database[i].name);
                        printf("Email: %s\n", database[i].email);
                        printf("Address: %s\n\n", database[i].address);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nUser not found\n\n");
                }

                break;
            }

            case '3': {
                char search_name[MAX_NAME_LENGTH];
                int found = 0;

                printf("\nEnter user name: ");
                scanf(" %[^\n]s", search_name);

                for (int i = 0; i < count; i++) {
                    if (strcmp(database[i].name, search_name) == 0) {
                        printf("\nUser found:\n");
                        printf("ID: %d\n", database[i].id);
                        printf("Email: %s\n", database[i].email);
                        printf("Address: %s\n\n", database[i].address);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("\nUser not found\n\n");
                }

                break;
            }

            case '4':
                printf("\n");
                if (count == 0) {
                    printf("No users in database\n\n");
                    break;
                }
                
                for (int i = 0; i < count; i++) {
                    printf("User %d:\n", database[i].id);
                    printf("Name: %s\n", database[i].name);
                    printf("Email: %s\n", database[i].email);
                    printf("Address: %s\n", database[i].address);
                    printf("\n");
                }

                break;

            case '5':
                printf("\nThank you for using the User Database!\n");
                exit(0);

            default:
                printf("\nInvalid option, please select again\n\n");
                break;
        }
    }

    return 0;
}