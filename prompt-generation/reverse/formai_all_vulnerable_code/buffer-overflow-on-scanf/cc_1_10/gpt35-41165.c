//FormAI DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_MAX_LENGTH 20
#define PASSWORD_COUNT 10

typedef struct {
    char name[CHAR_MAX_LENGTH];
    char password[CHAR_MAX_LENGTH];
} PasswordEntry;

int menu();
void addPassword();
void viewPasswords();
void deletePassword();

PasswordEntry passwordStore[PASSWORD_COUNT];
int passwordIndex = 0;

int main() {
    printf("Welcome to the Password Manager!\n");
    while(1) {
        int choice = menu();
        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

int menu() {
    printf("\n");
    printf("1. Add a Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete a Password\n");
    printf("4. Quit Program\n");
    printf("\n");
    printf("Please enter your choice: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

void addPassword() {
    if(passwordIndex == PASSWORD_COUNT) {
        printf("Password store is full, cannot add any more passwords.\n");
        return;
    }

    PasswordEntry entry;

    printf("Enter name for password: ");
    scanf("%s", entry.name);

    printf("Enter password for name: ");
    scanf("%s", entry.password);

    passwordStore[passwordIndex++] = entry;

    printf("\nPassword added successfully!\n");
}

void viewPasswords() {
    if(passwordIndex == 0) {
        printf("Password store is empty, no passwords to view.\n");
        return;
    }

    printf("Here are the passwords in the password store:\n\n");

    for(int i = 0; i < passwordIndex; i++) {
        printf("Name: %s\n", passwordStore[i].name);
        printf("Password: %s\n\n", passwordStore[i].password);
    }
}

void deletePassword() {
    if(passwordIndex == 0) {
        printf("Password store is empty, no passwords to delete.\n");
        return;
    }

    printf("Please enter the name of the password you want to delete: ");

    char nameToDelete[CHAR_MAX_LENGTH];
    scanf("%s", nameToDelete);

    int foundAtIndex = -1;

    for(int i = 0; i < passwordIndex; i++) {
        if(strcmp(passwordStore[i].name, nameToDelete) == 0) {
            foundAtIndex = i;
            break;
        }
    }

    if(foundAtIndex == -1) {
        printf("Password with name %s not found in password store.\n", nameToDelete);
    } else {
        for(int i = foundAtIndex; i < passwordIndex - 1; i++) {
            passwordStore[i] = passwordStore[i+1];
        }
        passwordIndex--;
        printf("Password with name %s deleted successfully!\n", nameToDelete);
    }
}