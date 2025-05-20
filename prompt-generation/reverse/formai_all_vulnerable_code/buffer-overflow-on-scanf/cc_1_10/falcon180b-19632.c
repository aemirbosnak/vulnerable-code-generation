//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generatePassword(char *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int length = strlen(charset);
    int i = 0;

    while (i < MAX_PASSWORD_LENGTH - 1) {
        int randIndex = rand() % length;
        password[i] = charset[randIndex];
        i++;
    }

    password[i] = '\0';
}

int main() {
    int numPasswords;
    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &numPasswords);

    struct Password passwords[MAX_PASSWORDS];

    for (int i = 0; i < numPasswords; i++) {
        printf("Enter a name for password #%d: ", i + 1);
        scanf("%s", passwords[i].name);

        printf("Enter a length for password #%d: ", i + 1);
        int length;
        scanf("%d", &length);

        if (length > MAX_PASSWORD_LENGTH) {
            printf("Error: Password length must be %d or less.\n", MAX_PASSWORD_LENGTH);
            return 1;
        }

        char password[MAX_PASSWORD_LENGTH];
        generatePassword(password);

        strcpy(passwords[i].password, password);
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("Password #%d:\nName: %s\nPassword: %s\n\n", i + 1, passwords[i].name, passwords[i].password);
    }

    return 0;
}