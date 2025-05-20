//Falcon-180B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    printf("Enter name for password: ");
    scanf("%s", passwords[numPasswords].name);
    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);
    numPasswords++;
}

void removePassword() {
    printf("Enter name of password to remove: ");
    char name[MAX_PASSWORD_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (numPasswords - i - 1));
            numPasswords--;
            break;
        }
    }
}

void listPasswords() {
    printf("Passwords:\n");
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

void main() {
    int choice;
    while (1) {
        printf("1. Add password\n2. Remove password\n3. List passwords\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                removePassword();
                break;
            case 3:
                listPasswords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}