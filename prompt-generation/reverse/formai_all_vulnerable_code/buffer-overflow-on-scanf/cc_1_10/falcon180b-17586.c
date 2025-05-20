//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Sorry, you can't add any more passwords!\n");
        return;
    }

    printf("Enter website: ");
    scanf("%s", passwords[num_passwords].website);

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
    printf("Password added!\n");
}

void view_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i].website);
        printf("%s\n", passwords[i].username);
        printf("%s\n\n", passwords[i].password);
    }
}

void remove_password() {
    printf("Enter website to remove: ");
    scanf("%s", passwords[num_passwords - 1].website);

    for (int i = 0; i < num_passwords - 1; i++) {
        if (strcmp(passwords[i].website, passwords[num_passwords - 1].website) == 0) {
            memcpy(&passwords[i], &passwords[num_passwords - 1], sizeof(Password));
            printf("Password removed!\n");
            return;
        }
    }

    printf("Password not found!\n");
}

int main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Remove password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            view_passwords();
            break;
        case 3:
            remove_password();
            break;
        case 4:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}