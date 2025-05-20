//Falcon-180B DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8

typedef struct {
    char username[64];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int comparePasswords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void addPassword() {
    char username[64];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    generatePassword(password, rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void viewPasswords() {
    qsort(passwords, numPasswords, sizeof(Password), comparePasswords);

    printf("Username\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    srand(time(NULL));

    int choice;
    while (1) {
        printf("\n1. Add password\n2. View passwords\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}