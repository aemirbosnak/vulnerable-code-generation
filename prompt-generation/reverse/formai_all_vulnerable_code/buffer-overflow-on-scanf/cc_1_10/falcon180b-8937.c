//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void add_password(struct password passwords[], int num_passwords, char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password(struct password passwords[], int num_passwords, char* username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].username, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);

            num_passwords--;
            break;
        }
    }
}

void print_passwords(struct password passwords[], int num_passwords) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char choice;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("Password Manager\n");
        printf("1. Add Password\n2. Delete Password\n3. Print Passwords\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                add_password(passwords, num_passwords, username, password);
                break;

            case '2':
                printf("Enter username: ");
                scanf("%s", username);

                delete_password(passwords, num_passwords, username);
                break;

            case '3':
                print_passwords(passwords, num_passwords);
                break;

            case '4':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= '4');

    return 0;
}