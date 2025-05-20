//Falcon-180B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int num_passwords = 0;
struct Password passwords[MAX_PASSWORDS];

void add_password() {
    printf("Enter the name for the password: ");
    scanf("%s", passwords[num_passwords].name);

    printf("Enter the password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void remove_password() {
    printf("Enter the name of the password to remove: ");
    scanf("%s", passwords[num_passwords].name);

    num_passwords--;
}

void search_password() {
    printf("Enter the name of the password to search for: ");
    scanf("%s", passwords[num_passwords].name);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, passwords[num_passwords].name) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Password not found.\n");
    }
}

void main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            remove_password();
            break;
        case 3:
            search_password();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}