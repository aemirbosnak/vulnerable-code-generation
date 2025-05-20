//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    int numPasswords;
    Password passwords[MAX_PASSWORDS];

    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &numPasswords);

    if (numPasswords > MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords is %d.\n", MAX_PASSWORDS);
        return 1;
    }

    printf("Enter the usernames and passwords:\n");

    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("Username for password %d: ", i+1);
        scanf("%s", passwords[i].username);

        printf("Password length for %s: ", passwords[i].username);
        int length;
        scanf("%d", &length);

        if (length > MAX_PASSWORD_LENGTH) {
            printf("Error: Password length cannot be greater than %d.\n", MAX_PASSWORD_LENGTH);
            return 1;
        }

        generatePassword(passwords[i].password, length);
        printf("Generated password for %s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}