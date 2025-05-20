//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char* username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            passwords[i].username[0] = '\0';
            passwords[i].password[0] = '\0';
            num_passwords--;
            return;
        }
    }
}

void display_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

int main() {
    char choice;
    int i;

    srand(time(NULL));

    while (1) {
        printf("Password Manager\n");
        printf("1. Add Password\n");
        printf("2. Remove Password\n");
        printf("3. Display Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter username: ");
                scanf(" %s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf(" %s", passwords[num_passwords].password);
                break;
            case '2':
                printf("Enter username to remove: ");
                scanf(" %s", passwords[num_passwords].username);
                remove_password(passwords[num_passwords].username);
                break;
            case '3':
                display_passwords();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}