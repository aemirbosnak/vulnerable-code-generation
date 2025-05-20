//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100     // Maximum number of passwords the program can store
#define MAX_PASSWORD_LENGTH 50  // Maximum length of a password

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main()
{
    struct password passwords[MAX_PASSWORDS];   // Array of passwords to be stored
    int password_count = 0;     // The number of passwords initially stored, which will be incremented with each new one

    int option;     // The choice selected from the main menu
    int index;     // The index of the selected password

    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Store a new password\n");
        printf("2. View a stored password\n");
        printf("3. Delete a stored password\n");
        printf("4. Exit\n");
        printf("> ");

        scanf("%d", &option);

        switch (option) {
            case 1: {
                if (password_count == MAX_PASSWORDS) {
                    printf("Error: maximum number of passwords reached!\n");
                    break;
                }

                struct password new_password;
                printf("Enter the name of the website or service: ");
                scanf("%s", new_password.name);
                printf("Enter the password for \"%s\": ", new_password.name);
                scanf("%s", new_password.password);

                passwords[password_count] = new_password;
                password_count++;

                printf("Password stored successfully.\n");
                break;
            }

            case 2: {
                if (password_count == 0) {
                    printf("There are no stored passwords!\n");
                    break;
                }

                printf("Select a password index to view:\n");

                for (int i = 0; i < password_count; i++) {
                    printf("%d. \"%s\"\n", i, passwords[i].name);
                }

                printf("> ");
                scanf("%d", &index);

                if (index < 0 || index >= password_count) {
                    printf("Invalid index selected!\n");
                    break;
                }

                char password[MAX_PASSWORD_LENGTH];
                printf("Enter the password to view \"%s\": ", passwords[index].name);
                scanf("%s", password);

                if (strcmp(password, passwords[index].password) != 0) {
                    printf("Incorrect password!\n");
                    break;
                }

                printf("\"%s\" password is \"%s\"\n", passwords[index].name, passwords[index].password);
                break;
            }

            case 3: {
                if (password_count == 0) {
                    printf("There are no stored passwords!\n");
                    break;
                }

                printf("Select a password index to delete:\n");

                for (int i = 0; i < password_count; i++) {
                    printf("%d. \"%s\"\n", i, passwords[i].name);
                }

                printf("> ");
                scanf("%d", &index);

                if (index < 0 || index >= password_count) {
                    printf("Invalid index selected!\n");
                    break;
                }

                char password[MAX_PASSWORD_LENGTH];
                printf("Enter the password to delete \"%s\": ", passwords[index].name);
                scanf("%s", password);

                if (strcmp(password, passwords[index].password) != 0) {
                    printf("Incorrect password!\n");
                    break;
                }

                for (int i = index; i < password_count - 1; i++) {
                    passwords[i] = passwords[i + 1];
                }

                password_count--;

                printf("Password \"%s\" deleted successfully.\n", passwords[index].name);
                break;
            }

            case 4: {
                printf("Exiting program...\n");
                exit(0);
            }

            default: {
                printf("Invalid option selected!\n");
            }
        }
    }

    return 0;
}