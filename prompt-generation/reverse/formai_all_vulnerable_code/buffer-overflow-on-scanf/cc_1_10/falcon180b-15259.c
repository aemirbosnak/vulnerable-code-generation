//Falcon-180B DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    strncpy(passwords[num_passwords].username, username, MAX_USERNAME_LENGTH);
    strncpy(passwords[num_passwords].password, password, MAX_PASSWORD_LENGTH);

    num_passwords++;
}

bool find_password(char* username, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strncpy(password, passwords[i].password, MAX_PASSWORD_LENGTH);
            return true;
        }
    }

    return false;
}

void print_passwords() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the Password Manager!\n");

    while (true) {
        printf("\n");
        printf("1. Add a new password\n");
        printf("2. Find a password\n");
        printf("3. Print all passwords\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                if (find_password(username, password)) {
                    printf("Password found: %s\n", password);
                } else {
                    printf("Password not found.\n");
                }
                break;
            case 3:
                print_passwords();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}