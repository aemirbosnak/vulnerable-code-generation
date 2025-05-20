//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 1000

typedef struct {
    char username[50];
    char password[50];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = strlen(password);

    numPasswords++;
}

void removePassword() {
    char username[50];

    printf("Enter username to remove: ");
    scanf("%s", username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (numPasswords - i - 1));
            numPasswords--;
            break;
        }
    }
}

void displayPasswords() {
    printf("Username\tPassword\tLength\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%d\n", passwords[i].username, passwords[i].password, passwords[i].length);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add password\n2. Remove password\n3. Display passwords\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                removePassword();
                break;
            case 3:
                displayPasswords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}