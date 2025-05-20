//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 20
#define MAX_LENGTH 50

struct password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_passwords == MAX_PASSWORDS) {
                printf("Sorry, you have reached the maximum number of passwords.\n");
                continue;
            }

            char website[MAX_LENGTH], username[MAX_LENGTH], password[MAX_LENGTH];

            printf("Enter website: ");
            scanf("%s", website);

            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            struct password new_password;
            strcpy(new_password.website, website);
            strcpy(new_password.username, username);
            strcpy(new_password.password, password);

            passwords[num_passwords] = new_password;
            num_passwords++;

            printf("Password added successfully!\n");
        } else if (choice == 2) {
            if (num_passwords == 0) {
                printf("No passwords to view.\n");
                continue;
            }

            printf("Here are your saved passwords:\n");

            for (int i = 0; i < num_passwords; i++) {
                printf("%d. Website: %s, Username: %s, Password: %s\n", i+1, passwords[i].website, passwords[i].username, passwords[i].password);
            }
        } else if (choice == 3) {
            printf("Thank you for using Password Manager!\n");
            exit(0);
        } else {
            printf("Sorry, that is not a valid choice. Please try again.\n");
        }
    }
}