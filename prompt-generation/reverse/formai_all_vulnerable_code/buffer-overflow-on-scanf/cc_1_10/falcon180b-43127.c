//Falcon-180B DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[20];
    char password[PASSWORD_LENGTH];
} password_t;

void add_password(password_t passwords[MAX_PASSWORDS], int num_passwords) {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);
    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);
    num_passwords++;
}

int find_password(password_t passwords[MAX_PASSWORDS], int num_passwords, char* username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password for %s: %s\n", username, passwords[i].password);
            return 1;
        }
    }
    return 0;
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nEnter 1 to add a password\nEnter 2 to find a password\nEnter 3 to quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, num_passwords);
                break;
            case 2:
                printf("Enter username: ");
                char username[20];
                scanf("%s", username);
                find_password(passwords, num_passwords, username);
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}