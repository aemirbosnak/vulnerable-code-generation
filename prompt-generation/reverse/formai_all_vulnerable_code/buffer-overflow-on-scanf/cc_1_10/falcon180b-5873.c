//Falcon-180B DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LEN 100

typedef struct {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void deletePassword() {
    int i;
    char username[MAX_PASSWORD_LEN];

    printf("Enter username to delete: ");
    scanf("%s", username);

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (numPasswords - i - 1));
            numPasswords--;
            break;
        }
    }
}

void viewPasswords() {
    int i;

    printf("Username\tPassword\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add password\n2. Delete password\n3. View passwords\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                deletePassword();
                break;
            case 3:
                viewPasswords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}