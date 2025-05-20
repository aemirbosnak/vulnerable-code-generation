//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void delete_password() {
    printf("Enter username to delete: ");
    scanf("%s", passwords[num_passwords - 1].username);

    num_passwords--;
}

void print_passwords() {
    printf("\nPasswords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Welcome to the Password Manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
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