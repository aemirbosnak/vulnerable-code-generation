//Falcon-180B DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USER_LENGTH 50

typedef struct {
    char username[MAX_USER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char* password) {
    int length = rand() % MAX_PASSWORD_LENGTH + 1;
    for (int i = 0; i < length; i++) {
        int randChar = rand() % 94 + 33; // 33 is the ascii code for '!'
        password[i] = randChar;
    }
    password[length] = '\0';
}

int main() {
    srand(time(0));

    char userInput[MAX_USER_LENGTH];
    while (1) {
        printf("Enter username: ");
        scanf("%s", userInput);

        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(userInput, passwords[i].username) == 0) {
                printf("Password: %s\n", passwords[i].password);
                return 0;
            }
        }

        if (numPasswords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            return 0;
        }

        char password[MAX_PASSWORD_LENGTH];
        generatePassword(password);
        strcpy(passwords[numPasswords].password, password);
        strcpy(passwords[numPasswords].username, userInput);
        numPasswords++;
    }

    return 0;
}