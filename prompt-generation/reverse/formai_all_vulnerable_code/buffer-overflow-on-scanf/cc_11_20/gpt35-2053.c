//FormAI DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LEN 20

char passwords[MAX_PASSWORDS][MAX_PASSWORD_LEN];

int main() {
    int choice, password_index = 0;
    char password[MAX_PASSWORD_LEN];

    while (1) {
        printf("1. Add password\n");
        printf("2. Show passwords\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter password: ");
            scanf("%s", password);

            // Check if password already exists
            int found = 0;
            for (int i = 0; i < password_index; i++) {
                if (strcmp(passwords[i], password) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("Password already exists. Try a different one.\n\n");
                continue;
            }

            // Add password
            if (password_index == MAX_PASSWORDS) {
                printf("Max password limit reached. Password not added.\n\n");
            } else {
                strcpy(passwords[password_index], password);
                password_index++;
                printf("Password added successfully.\n\n");
            }
        } else if (choice == 2) {
            if (password_index == 0) {
                printf("No passwords added yet.\n\n");
            } else {
                printf("Passwords:\n");
                for (int i = 0; i < password_index; i++) {
                    printf("%d. %s\n", i+1, passwords[i]);
                }
                printf("\n");
            }
        } else if (choice == 3) {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid choice. Try again.\n\n");
        }
    }

    return 0;
}