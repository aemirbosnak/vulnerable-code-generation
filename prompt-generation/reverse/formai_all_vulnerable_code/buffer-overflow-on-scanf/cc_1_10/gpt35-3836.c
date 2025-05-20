//FormAI DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20

typedef struct {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_LEN];
} Password;

int main() {
    int numPasswords = 0;
    Password *passwords = NULL;

    while (1) {
        printf("Select an option:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter website: ");
                char website[50];
                scanf("%s", website);

                printf("Enter username: ");
                char username[50];
                scanf("%s", username);

                printf("Enter password (max length %d): ", MAX_PASSWORD_LEN);
                char password[MAX_PASSWORD_LEN];
                scanf("%s", password);

                Password newPass;
                strncpy(newPass.website, website, 50);
                strncpy(newPass.username, username, 50);
                strncpy(newPass.password, password, MAX_PASSWORD_LEN);

                numPasswords++;
                passwords = realloc(passwords, numPasswords * sizeof(Password));
                passwords[numPasswords - 1] = newPass;

                printf("Password added successfully!\n");
                break;
            }
            case 2: {
                if (numPasswords == 0) {
                    printf("No passwords added yet.\n");
                    break;
                }

                printf("%-15s%-15s%s\n", "Website", "Username", "Password");
                printf("-------------------------------------------\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%-15s%-15s%s\n",
                           passwords[i].website,
                           passwords[i].username,
                           passwords[i].password);
                }
                break;
            }
            case 3: {
                printf("Thank you for using the password manager.\n");
                exit(0);
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}