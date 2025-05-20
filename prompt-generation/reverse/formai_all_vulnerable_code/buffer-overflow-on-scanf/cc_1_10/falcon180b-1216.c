//Falcon-180B DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char website[50];
    char username[50];
    char password[100];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char website[50];
    char username[50];
    char password[100];

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

    for (i = 0; i < numPasswords; i++) {
        printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    char searchWebsite[50];

    printf("Enter website to search for: ");
    scanf("%s", searchWebsite);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, searchWebsite) == 0) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n2. View passwords\n3. Search password\n4. Exit\n");
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
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}