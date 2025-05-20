//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 32

typedef struct {
    char username[32];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[32];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;

    printf("Password added successfully!\n");
}

void remove_password() {
    char username[32];

    printf("Enter username to remove: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (num_passwords - i - 1));
            num_passwords--;
            break;
        }
    }

    if (i == num_passwords) {
        printf("User not found.\n");
    }
}

void print_passwords() {
    printf("Username\tPassword\n");
    printf("-------------------------------------------------\n");

    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                print_passwords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}