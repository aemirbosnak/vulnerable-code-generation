//FormAI DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char username[50];
    char password[50];
};

int main() {
    struct user users[10];
    char choice;
    int count = 0;

    printf("Welcome to Happy Password Manager!\n");

    do {
        printf("\n-- Menu --\n");
        printf("a. Add user\n");
        printf("b. View user information\n");
        printf("c. Change user password\n");
        printf("d. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                printf("\n-- Add User --\n");
                printf("Enter username: ");
                scanf("%s", users[count].username);
                printf("Enter password: ");
                scanf("%s", users[count].password);
                printf("User added successfully!\n");
                count++;
                break;
            case 'b':
                printf("\n-- View User Information --\n");
                if (count == 0) {
                    printf("No users found.\n");
                    break;
                }
                printf("Enter username: ");
                char view_username[50];
                scanf("%s", view_username);
                for (int i = 0; i < count; i++) {
                    if (strcmp(users[i].username, view_username) == 0) {
                        printf("Username: %s\n", users[i].username);
                        printf("Password: %s\n", users[i].password);
                        break;
                    }
                }
                printf("User not found.\n");
                break;
            case 'c':
                printf("\n-- Change User Password --\n");
                if (count == 0) {
                    printf("No users found.\n");
                    break;
                }
                printf("Enter username: ");
                char change_username[50];
                scanf("%s", change_username);
                for (int i = 0; i < count; i++) {
                    if (strcmp(users[i].username, change_username) == 0) {
                        printf("Enter new password: ");
                        scanf("%s", users[i].password);
                        printf("Password changed successfully!\n");
                        break;
                    }
                }
                printf("User not found.\n");
                break;
            case 'd':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 'd');

    return 0;
}