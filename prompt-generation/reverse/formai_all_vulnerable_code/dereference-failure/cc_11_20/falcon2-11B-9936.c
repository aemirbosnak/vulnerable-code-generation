//Falcon2-11B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50

struct Password {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct Password passwords[MAX_PASSWORDS];

int main() {
    int choice, password_index, len;
    char user[MAX_LENGTH], pw[MAX_LENGTH];

    printf("Welcome to the Password Manager!\n");
    printf("Enter 1 to add a new password\n");
    printf("Enter 2 to display all passwords\n");
    printf("Enter 3 to search for a password\n");
    printf("Enter 4 to delete a password\n");
    printf("Enter 5 to exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(user, MAX_LENGTH, stdin);
                len = strlen(user);
                if (len >= MAX_LENGTH - 1) {
                    printf("Username is too long!\n");
                    continue;
                }
                strncpy(passwords[password_index].username, user, MAX_LENGTH - 1);
                printf("Enter password: ");
                fgets(pw, MAX_LENGTH, stdin);
                len = strlen(pw);
                if (len >= MAX_LENGTH - 1) {
                    printf("Password is too long!\n");
                    continue;
                }
                strncpy(passwords[password_index].password, pw, MAX_LENGTH - 1);
                password_index++;
                if (password_index == MAX_PASSWORDS) {
                    printf("Memory is full!\n");
                    break;
                }
                printf("Password added successfully!\n");
                break;
            case 2:
                printf("Displaying all passwords...\n");
                for (int i = 0; i < password_index; i++) {
                    printf("Username: %s\n", passwords[i].username);
                    printf("Password: ********\n");
                }
                break;
            case 3:
                printf("Enter username: ");
                fgets(user, MAX_LENGTH, stdin);
                len = strlen(user);
                if (len >= MAX_LENGTH - 1) {
                    printf("Username is too long!\n");
                    continue;
                }
                strncpy(passwords[password_index].username, user, MAX_LENGTH - 1);
                printf("Enter password: ");
                fgets(pw, MAX_LENGTH, stdin);
                len = strlen(pw);
                if (len >= MAX_LENGTH - 1) {
                    printf("Password is too long!\n");
                    continue;
                }
                strncpy(passwords[password_index].password, pw, MAX_LENGTH - 1);
                password_index++;
                if (password_index == MAX_PASSWORDS) {
                    printf("Memory is full!\n");
                    break;
                }
                printf("Password found!\n");
                break;
            case 4:
                printf("Enter username: ");
                fgets(user, MAX_LENGTH, stdin);
                len = strlen(user);
                if (len >= MAX_LENGTH - 1) {
                    printf("Username is too long!\n");
                    continue;
                }
                strncpy(passwords[password_index].username, user, MAX_LENGTH - 1);
                printf("Enter password: ");
                fgets(pw, MAX_LENGTH, stdin);
                len = strlen(pw);
                if (len >= MAX_LENGTH - 1) {
                    printf("Password is too long!\n");
                    continue;
                }
                strncpy(passwords[password_index].password, pw, MAX_LENGTH - 1);
                password_index++;
                if (password_index == MAX_PASSWORDS) {
                    printf("Memory is full!\n");
                    break;
                }
                printf("Password deleted successfully!\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}