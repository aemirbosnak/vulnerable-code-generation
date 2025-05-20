//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

struct Password {
    char name[50];
    char password[PASSWORD_LENGTH];
};

void generatePassword(char password[PASSWORD_LENGTH]) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i = 0;
    while (i < PASSWORD_LENGTH) {
        password[i] = chars[rand() % strlen(chars)];
        i++;
    }
    password[i] = '\0';
}

int main() {
    int choice;
    char name[50];
    char password[PASSWORD_LENGTH];
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    do {
        printf("Password Manager\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the name of the website/service: ");
            scanf("%s", name);
            generatePassword(password);
            strcpy(passwords[numPasswords].name, name);
            strcpy(passwords[numPasswords].password, password);
            numPasswords++;
            break;
        case 2:
            printf("Passwords:\n");
            for (int i = 0; i < numPasswords; i++) {
                printf("%s - %s\n", passwords[i].name, passwords[i].password);
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice!= 3);

    return 0;
}