//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';

    printf("Enter username: ");
    fgets(username, MAX_PASSWORD_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';

    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].username, username);

    num_passwords++;

    printf("Password added successfully!\n");
}

void view_passwords() {
    int i;

    printf("Passwords:\n");
    for (i = 0; i < num_passwords; i++) {
        printf("%d. %s - %s\n", i+1, passwords[i].username, passwords[i].password);
    }
}

void search_password() {
    char search_username[MAX_PASSWORD_LENGTH];

    printf("Enter username to search: ");
    fgets(search_username, MAX_PASSWORD_LENGTH, stdin);
    search_username[strcspn(search_username, "\n")] = '\0';

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, search_username) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
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
                search_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}