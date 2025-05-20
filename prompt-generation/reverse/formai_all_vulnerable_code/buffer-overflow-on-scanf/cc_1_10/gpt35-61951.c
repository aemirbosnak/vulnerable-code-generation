//FormAI DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

int current_passwords = 0;

typedef struct {
    char website[50];
    char username[20];
    char password[20];
} Password;

Password passwords[MAX_PASSWORDS];

void add_password() {
    Password new_password;
    printf("Enter website name: ");
    scanf("%s", new_password.website);
    printf("Enter username: ");
    scanf("%s", new_password.username);
    printf("Enter password: ");
    scanf("%s", new_password.password);

    passwords[current_passwords++] = new_password;
    printf("Password added successfully!\n");
}

void show_passwords() {
    printf("Website\t\tUsername\tPassword\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < current_passwords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
    printf("------------------------------------------------\n");
}

void find_password() {
    char website[50];
    printf("Enter website name to find password: ");
    scanf("%s", website);

    for (int i = 0; i < current_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Password found for %s: %s\n", website, passwords[i].password);
            return;
        }
    }
    printf("No password found for %s\n", website);
}

void menu() {
    printf("Password Management System | Configurable Style\n");
    printf("------------------------------------------------\n");
    printf("1. Add Password\n");
    printf("2. Show all Passwords\n");
    printf("3. Find a Password\n");
    printf("4. Exit\n\n");
}

int main() {
    int option;
    while (1) {
        menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_password();
                break;
            case 2:
                show_passwords();
                break;
            case 3:
                find_password();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option, try again.\n");
        }
    }

    return 0;
}