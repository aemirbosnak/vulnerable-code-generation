//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char password[PASSWORD_LENGTH + 1];
    char username[PASSWORD_LENGTH + 1];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
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
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            num_passwords--;
            break;
        }
    }
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (passwords[i].username[0]!= '\0') {
            printf("%s\t%s\n", passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    char choice;
    char username[PASSWORD_LENGTH + 1];
    char password[PASSWORD_LENGTH + 1];

    printf("Welcome to the Password Manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            add_password(username, password);
            break;
        case '2':
            printf("Enter username: ");
            scanf("%s", username);
            remove_password(username);
            break;
        case '3':
            print_passwords();
            break;
        case '4':
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}