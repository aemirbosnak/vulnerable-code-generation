//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
int num_passwords = 0;

int main() {
    char choice;

    printf("Welcome to the Password Manager!\n");

    do {
        printf("\n");
        printf("What would you like to do?\n");
        printf("a) Add a new password\n");
        printf("b) Show all passwords\n");
        printf("c) Find a password\n");
        printf("d) Quit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': {
                if (num_passwords >= MAX_PASSWORDS) {
                    printf("Sorry, you have reached the maximum number of passwords.\n");
                    break;
                }

                char password[MAX_PASSWORD_LENGTH];
                printf("Enter a new password (up to %d characters): ", MAX_PASSWORD_LENGTH-1);
                scanf("%s", password);

                strcpy(passwords[num_passwords], password);
                num_passwords++;

                printf("Password added successfully!\n");
                break;
            }
            case 'b': {
                if (num_passwords == 0) {
                    printf("No passwords found.\n");
                    break;
                }

                printf("All Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("- %s\n", passwords[i]);
                }

                break;
            }
            case 'c': {
                if (num_passwords == 0) {
                    printf("No passwords found.\n");
                    break;
                }

                char search_password[MAX_PASSWORD_LENGTH];
                printf("Enter the password to search for: ");
                scanf("%s", search_password);

                int found = 0;
                for (int i = 0; i < num_passwords; i++) {
                    if (strcmp(passwords[i], search_password) == 0) {
                        found = 1;
                        printf("Password found!\n");
                        break;
                    }
                }

                if (!found) {
                    printf("Password not found.\n");
                }

                break;
            }
            case 'd': {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while (1);

    return 0;
}