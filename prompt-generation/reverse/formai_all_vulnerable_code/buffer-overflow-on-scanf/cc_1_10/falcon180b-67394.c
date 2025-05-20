//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
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
    printf("Enter website: ");
    scanf("%s", passwords[numPasswords].website);

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void viewPasswords() {
    printf("\nPasswords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s - %s - %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    char searchTerm[100];
    printf("Enter search term: ");
    scanf("%s", searchTerm);

    for (int i = 0; i < numPasswords; i++) {
        if (strstr(passwords[i].website, searchTerm) || strstr(passwords[i].username, searchTerm) || strstr(passwords[i].password, searchTerm)) {
            printf("%s - %s - %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    printf("Welcome to the Password Manager!\n");

    int choice;
    do {
        printf("\n1. Add password\n2. View passwords\n3. Search password\n4. Exit\n");
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