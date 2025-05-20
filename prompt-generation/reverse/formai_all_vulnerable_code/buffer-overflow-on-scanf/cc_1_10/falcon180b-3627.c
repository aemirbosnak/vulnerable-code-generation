//Falcon-180B DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Sorry, maximum number of passwords reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;

    printf("Password added successfully.\n");
}

void listPasswords() {
    printf("Password list:\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].password);
    }
}

void removePassword() {
    printf("Enter name of password to remove: ");
    scanf("%s", passwords[numPasswords - 1].name);

    numPasswords--;

    printf("Password removed successfully.\n");
}

int main() {
    while (1) {
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Remove password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;

            case 2:
                listPasswords();
                break;

            case 3:
                removePassword();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}