//Falcon-180B DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generate_password(Password *password) {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int i, j;

    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = chars[rand() % strlen(chars)];
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Password Manager\n");

    while (1) {
        printf("\n1. Add password\n2. View passwords\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                generate_password(&passwords[num_passwords]);
                num_passwords++;
                printf("Password added.\n");
            }
            break;

        case 2:
            for (int i = 0; i < num_passwords; i++) {
                printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}