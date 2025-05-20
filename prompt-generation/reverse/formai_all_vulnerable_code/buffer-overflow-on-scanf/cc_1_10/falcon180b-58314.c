//Falcon-180B DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter website: ");
    scanf("%s", website);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].website, website);
    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void viewPasswords() {
    int i;

    printf("\nWebsite\tUsername\tPassword\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    char searchWebsite[MAX_PASSWORD_LENGTH];

    printf("Enter website to search: ");
    scanf("%s", searchWebsite);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, searchWebsite) == 0) {
            printf("\nWebsite: %s\nUsername: %s\nPassword: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add password\n2. View passwords\n3. Search password\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPassword();
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