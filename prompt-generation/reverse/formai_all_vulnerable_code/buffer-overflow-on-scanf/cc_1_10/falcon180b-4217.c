//Falcon-180B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 1000
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);
    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);
    numPasswords++;
    printf("Password added successfully!\n");
}

void removePassword() {
    printf("Enter username of password to remove: ");
    scanf("%s", passwords[numPasswords - 1].username);
    numPasswords--;
    printf("Password removed successfully!\n");
}

void searchPassword() {
    printf("Enter username to search for: ");
    scanf("%s", passwords[numPasswords - 1].username);
    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, passwords[numPasswords - 1].username) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Password not found.\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Add password\n2. Remove password\n3. Search for password\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                removePassword();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}