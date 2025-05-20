//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 25

char passwords[MAX_PASSWORDS][MAX_LENGTH];
int numPasswords = 0;

void displayMenu() {
    printf("\nPassword Manager\n");
    printf("-----------------\n");
    printf("1. Add Password\n");
    printf("2. Display All Passwords\n");
    printf("3. Search For Password\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

void addPassword() {
    if (numPasswords < MAX_PASSWORDS) {
        printf("\nEnter new password: ");
        scanf("%s", passwords[numPasswords]);
        numPasswords++;
        printf("Password added successfully!\n");
    } else {
        printf("\nMaximum number of passwords reached!\n");
    }
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("\nNo passwords added yet!\n");
    } else {
        printf("\nAll Passwords\n");
        printf("-----------------\n");
        for (int i = 0; i < numPasswords; i++) {
            printf("%d. %s\n", i+1, passwords[i]);
        }
    }
}

void searchPassword() {
    char search[MAX_LENGTH];
    printf("\nEnter password to search: ");
    scanf("%s", search);
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i], search) == 0) {
            printf("\nPassword found at index %d\n", i+1);
            return;
        }
    }
    printf("\nPassword not found!\n");
}

int main() {
    int choice = 0;
    while (choice != 4) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}