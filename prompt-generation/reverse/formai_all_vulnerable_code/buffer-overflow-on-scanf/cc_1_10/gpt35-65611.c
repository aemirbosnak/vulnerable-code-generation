//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 25
#define MAX_PASSWDS 100

typedef struct {
    char website[50];
    char username[25];
    char password[MAX_PASS_LENGTH];
} password;

int main() {
    password passwords[MAX_PASSWDS];
    int num_passwords = 0;

    char option;
    do {
        printf("\nPassword Manager\n");
        printf("================\n");
        printf("1. Create new password\n");
        printf("2. Display saved passwords\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1': {
                // Creating a new password
                if (num_passwords == MAX_PASSWDS) {
                    printf("Maximum number of passwords reached\n");
                    break;
                }

                // Ask user for website and username
                char website[50];
                char username[25];
                printf("Website: ");
                scanf("%s", website);
                printf("Username: ");
                scanf("%s", username);

                // Generate a random password
                char password[MAX_PASS_LENGTH];
                for (int i = 0; i < 8; i++) {
                    password[i] = rand() % 26 + 'a';
                }
                for (int i = 8; i < MAX_PASS_LENGTH; i++) {
                    password[i] = rand() % 10 + '0';
                }
                password[MAX_PASS_LENGTH - 1] = '\0';

                // Save the new password
                strncpy(passwords[num_passwords].website, website, sizeof(passwords[num_passwords].website));
                strncpy(passwords[num_passwords].username, username, sizeof(passwords[num_passwords].username));
                strncpy(passwords[num_passwords].password, password, sizeof(passwords[num_passwords].password));

                // Increase the count of saved passwords
                num_passwords++;

                printf("Password created successfully!\n");
                break;
            }
            case '2': {
                // Displaying saved passwords
                printf("\n");
                printf("%-20s %-20s %-20s\n", "Website", "Username", "Password");
                printf("--------------------------------------------------------------------------------\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%-20s %-20s %-20s\n", passwords[i].website, passwords[i].username, passwords[i].password);
                }
                break;
            }
            case '3': {
                // Exiting the program
                printf("Goodbye!\n");
                break;
            }
            default: {
                // Invalid option
                printf("Invalid option, try again\n");
                break;
            }
        }
    } while(option != '3');

    return 0;
}