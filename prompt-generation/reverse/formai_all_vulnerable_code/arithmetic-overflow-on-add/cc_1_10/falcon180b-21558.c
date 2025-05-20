//Falcon-180B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
    char *website;
} Password;

void generatePassword(char *password, int length) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (i = 0; i < length; i++) {
        int randomIndex = rand() % strlen(charset);
        password[i] = charset[randomIndex];
    }
    password[length] = '\0';
}

int comparePasswords(const void *a, const void *b) {
    return strcmp(*(Password **)a, *(Password **)b);
}

void printPasswords(Password *passwords[], int numPasswords) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\nWebsite: %s\n", passwords[i]->username, passwords[i]->password, passwords[i]->website);
    }
}

int main() {
    int numPasswords = 0;
    Password *passwords[MAX_PASSWORDS];

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter username: ");
        char username[50];
        scanf("%s", username);

        printf("Enter password length: ");
        int length;
        scanf("%d", &length);

        char password[length + 1];
        generatePassword(password, length);

        printf("Enter website: ");
        char website[100];
        scanf("%s", website);

        passwords[numPasswords] = malloc(sizeof(Password));
        passwords[numPasswords]->username = strdup(username);
        passwords[numPasswords]->password = strdup(password);
        passwords[numPasswords]->website = strdup(website);
        numPasswords++;
    }

    qsort(passwords, numPasswords, sizeof(Password *), comparePasswords);
    printPasswords(passwords, numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        free(passwords[i]->username);
        free(passwords[i]->password);
        free(passwords[i]->website);
        free(passwords[i]);
    }
    return 0;
}