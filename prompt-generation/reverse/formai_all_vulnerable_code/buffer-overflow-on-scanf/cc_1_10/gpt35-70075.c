//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 20
#define MAX_PASSWORDS 100

struct password {
    char name[50];
    char value[PASSWORD_LENGTH];
};

int numPasswords = 0;
struct password passwords[MAX_PASSWORDS];

void generatePassword(char *password) {
    int i, r;
    char c;
    srand(time(NULL)); // Seed random generator
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        r = rand() % 62; // Generate random number from 0 to 61
        if (r < 26) {
            c = 'a' + r;
        } else if (r < 52) {
            c = 'A' + r - 26;
        } else {
            c = '0' + r - 52;
        }
        password[i] = c;
    }
    password[PASSWORD_LENGTH] = '\0';
}

void addPassword() {
    char name[50];
    char value[PASSWORD_LENGTH];
    printf("Enter name for password: ");
    scanf("%s", name);
    generatePassword(value);
    strncpy(passwords[numPasswords].name, name, 50);
    strncpy(passwords[numPasswords].value, value, PASSWORD_LENGTH);
    printf("Generated password for %s: %s\n", name, value);
    numPasswords++;
}

void displayPasswords() {
    int i;
    if (numPasswords == 0) {
        printf("No passwords saved.\n");
        return;
    }
    printf("%d password%s saved:\n", numPasswords, (numPasswords == 1) ? "" : "s");
    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].value);
    }
}

void searchPasswords() {
    int i;
    char query[50];
    printf("Enter name query: ");
    scanf("%s", query);
    for (i = 0; i < numPasswords; i++) {
        if (strstr(passwords[i].name, query)) {
            printf("%s: %s\n", passwords[i].name, passwords[i].value);
        }
    }
}

int main() {
    char c;
    printf("Password Manager\n\n");
    while (1) {
        printf("Options:\n");
        printf("1. Add password\n");
        printf("2. Display all passwords\n");
        printf("3. Search passwords\n");
        printf("4. Quit\n");
        printf("Enter option number: ");
        scanf(" %c", &c);
        printf("\n");
        switch (c) {
            case '1':
                addPassword();
                break;
            case '2':
                displayPasswords();
                break;
            case '3':
                searchPasswords();
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
        printf("\n");
    }
    return 0;
}