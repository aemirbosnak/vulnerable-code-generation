//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    int length = strlen(password);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Password is too long.\n");
        return;
    }

    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].length = length;

    num_passwords++;
    printf("Password added.\n");
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("No passwords added.\n");
        return;
    }

    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s (%d characters)\n", i+1, passwords[i].password, passwords[i].length);
    }
}

void main() {
    printf("Password Manager\n");
    int choice;

    do {
        printf("\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 3);
}