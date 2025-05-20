//Falcon-180B DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password limit reached.\n");
        return;
    }

    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;

    printf("Password added successfully.\n");
}

void remove_password() {
    if (num_passwords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    char username[50];

    printf("Enter username: ");
    scanf("%s", username);

    int i = 0;
    while (i < num_passwords) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], (num_passwords - i - 1) * sizeof(Password));
            num_passwords--;
            printf("Password removed successfully.\n");
            return;
        }
        i++;
    }

    printf("Password not found.\n");
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n2. Remove Password\n3. View Passwords\n4. Exit\n");

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
                view_passwords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}