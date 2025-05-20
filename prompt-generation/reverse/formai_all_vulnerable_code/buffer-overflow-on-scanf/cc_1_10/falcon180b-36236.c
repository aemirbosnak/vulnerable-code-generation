//Falcon-180B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void add_password(password_t passwords[], int num_passwords, char* username, char* password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            // Password already exists, update it
            strcpy(passwords[i].password, password);
            return;
        }
    }
    // Add new password
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

int find_password(password_t passwords[], int num_passwords, char* username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void print_passwords(password_t passwords[], int num_passwords) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(username, "exit") == 0) {
            break;
        }

        int index = find_password(passwords, num_passwords, username);
        if (index == -1) {
            add_password(passwords, num_passwords, username, password);
        } else {
            printf("Updating password for %s\n", username);
        }

        num_passwords++;
    }

    printf("Passwords:\n");
    print_passwords(passwords, num_passwords);

    return 0;
}