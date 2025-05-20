//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50
#define DELIM "--------------------------------------------------------"

struct Password {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
};

void printDelim() {
    printf("%s\n", DELIM);
}

void printHeader() {
    printf("%s\n", DELIM);
    printf("| %-30s| %-30s|\n", "Username", "Password");
    printf("%s\n", DELIM);
}

void printPassword(struct Password pass) {
    printf("| %-30s| %-30s|\n", pass.username, "*");
    for (int i = 0; i < strlen(pass.password); i++) {
        printf("*");
    }
    printf("\n");
}

void addPassword(struct Password passwords[] , char username[PASSWORD_LENGTH], char password[PASSWORD_LENGTH]) {
    int index = -1;

    for (int i = 0; i < MAX_PASSWORDS && passwords[i].username[0] != '\0'; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Username already exists!\n");
            return;
        }
        index = i;
    }

    strcpy(passwords[++index].username, username);
    strcpy(passwords[index].password, password);
}

void searchPassword(struct Password passwords[], char username[PASSWORD_LENGTH]) {
    for (int i = 0; i < MAX_PASSWORDS && passwords[i].username[0] != '\0'; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printPassword(passwords[i]);
            return;
        }
    }

    printf("Username not found!\n");
}

int main() {
    int choice;
    struct Password passwords[MAX_PASSWORDS];
    char username[PASSWORD_LENGTH], password[PASSWORD_LENGTH];

    srand(time(NULL));

    printHeader();

    while (1) {
        printf("1. Add Password\n");
        printf("2. Search Password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                addPassword(passwords, username, password);
                break;

            case 2:
                printf("Enter username to search: ");
                scanf("%s", username);
                searchPassword(passwords, username);
                break;

            case 3:
                printDelim();
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

        printDelim();
        printHeader();
    }

    return 0;
}