//Falcon-180B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    printf("Enter the name of the password: ");
    scanf("%s", passwords[numPasswords].name);
    printf("Enter the password: ");
    scanf("%s", passwords[numPasswords].password);
    numPasswords++;
}

void deletePassword() {
    printf("Enter the name of the password to delete: ");
    scanf("%s", passwords[numPasswords - 1].name);
    numPasswords--;
}

void displayPasswords() {
    printf("Name\t\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\n", passwords[i].name, passwords[i].password);
    }
}

void main() {
    printf("Welcome to the Password Manager!\n");
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. Display Passwords\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                deletePassword();
                break;
            case 3:
                displayPasswords();
                break;
            case 4:
                printf("Thank you for using the Password Manager!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
}