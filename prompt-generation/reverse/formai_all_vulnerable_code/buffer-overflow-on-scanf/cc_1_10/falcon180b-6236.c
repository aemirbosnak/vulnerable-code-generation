//Falcon-180B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    passwords[numPasswords].username = strdup(username);
    passwords[numPasswords].password = strdup(password);
    passwords[numPasswords].length = strlen(password);
    numPasswords++;
}

void printPasswords() {
    printf("Username\tPassword\tLength\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\t\t%d\n", passwords[i].username, passwords[i].password, passwords[i].length);
    }
}

void deletePassword(char *username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            for (int j = i; j < numPasswords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            numPasswords--;
            break;
        }
    }
}

int main() {
    char username[50], password[MAX_PASSWORD_LENGTH];
    int length;
    int choice;

    do {
        printf("1. Add Password\n2. Print Passwords\n3. Delete Password\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                length = strlen(password);
                addPassword(username, password);
                printf("Password added successfully!\n");
                break;
            case 2:
                printPasswords();
                break;
            case 3:
                printf("Enter username to delete password: ");
                scanf("%s", username);
                deletePassword(username);
                printf("Password deleted successfully!\n");
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