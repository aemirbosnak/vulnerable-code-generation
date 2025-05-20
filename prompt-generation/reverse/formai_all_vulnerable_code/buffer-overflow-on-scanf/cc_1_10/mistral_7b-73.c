//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 50

struct Password {
    char name[30];
    char password[PASSWORD_LENGTH];
};

struct Password passwords[MAX_PASSWORDS];
int passwordIndex = 0;

void createPassword(char* name, char* password) {
    if (passwordIndex < MAX_PASSWORDS) {
        strcpy(passwords[passwordIndex].name, name);
        strcpy(passwords[passwordIndex].password, password);
        passwordIndex++;
        printf("Thou hast added %s with password %s to thy record.\n", name, password);
    } else {
        printf("Alas! Thy record is full.\n");
    }
}

void displayPasswords() {
    int i;
    printf("\nList of thy passwords:\n");
    for (i = 0; i < passwordIndex; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

void searchPassword(char* name) {
    int i;
    bool found = false;
    for (i = 0; i < passwordIndex; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("'Tis the password for %s: %s\n", name, passwords[i].password);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("We could not find %s in thy records.\n", name);
    }
}

int main() {
    char name[30], password[PASSWORD_LENGTH];
    int choice;
    while (true) {
        printf("\nWelcome, noble knight! Thy password manager at thy service.\n");
        printf("1. Create a new password entry\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
        printf("Choose thy action: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the password: ");
                scanf("%s", password);
                createPassword(name, password);
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                printf("Enter the name to search: ");
                scanf("%s", name);
                searchPassword(name);
                break;
            case 4:
                printf("Farewell, noble knight!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}