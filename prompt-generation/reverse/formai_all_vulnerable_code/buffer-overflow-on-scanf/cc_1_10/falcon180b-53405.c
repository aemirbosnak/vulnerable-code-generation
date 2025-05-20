//Falcon-180B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);
    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);
    numPasswords++;
}

void deletePassword() {
    printf("Enter username to delete: ");
    char username[50];
    scanf("%s", username);
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            memcpy(&passwords[i], &passwords[numPasswords - 1], sizeof(Password));
            numPasswords--;
            break;
        }
    }
}

void viewPasswords() {
    printf("Username\tPassword\n");
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;
    do {
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
    } while (1);
    return 0;
}