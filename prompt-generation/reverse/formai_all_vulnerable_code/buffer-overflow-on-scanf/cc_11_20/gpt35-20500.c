//FormAI DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    int option = 0;

    printf("Welcome to the password manager!\n");

    while (option != 4) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Find password by username\n");
        printf("4. Quit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_passwords == MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached!\n");
                    break;
                }

                printf("\nEnter username: ");
                scanf("%s", passwords[num_passwords].username);

                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);

                num_passwords++;

                printf("Password added successfully!\n");
                break;

            case 2:
                if (num_passwords == 0) {
                    printf("No passwords to display!\n");
                    break;
                }

                printf("\nAll passwords:\n");

                for (int i = 0; i < num_passwords; i++) {
                    printf("%s: %s\n", passwords[i].username, passwords[i].password);
                }
                break;

            case 3:
                if (num_passwords == 0) {
                    printf("No passwords to search!\n");
                    break;
                }

                char search_username[MAX_PASSWORD_LENGTH];
                printf("\nEnter username to search: ");
                scanf("%s", search_username);

                int found = 0;

                for (int i = 0; i < num_passwords; i++) {
                    if (strcmp(search_username, passwords[i].username) == 0) {
                        printf("%s: %s\n", passwords[i].username, passwords[i].password);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("Password not found!\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option! Try again.\n");
                break;
        }
    }

    return 0;
}