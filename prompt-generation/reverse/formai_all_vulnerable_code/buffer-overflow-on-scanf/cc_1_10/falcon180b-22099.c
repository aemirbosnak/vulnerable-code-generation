//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
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

int find_password(char* username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void print_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        int index = find_password(username);
        if (index == -1) {
            add_password(username, password);
            printf("Password added successfully.\n");
        } else {
            printf("Password already exists.\n");
        }

        printf("Do you want to add another password? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    printf("All passwords:\n");
    print_passwords();

    return 0;
}