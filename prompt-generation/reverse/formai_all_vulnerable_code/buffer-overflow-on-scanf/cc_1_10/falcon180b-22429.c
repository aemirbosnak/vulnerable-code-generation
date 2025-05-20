//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// Password structure
typedef struct {
    char username[50];
    char password[50];
    int length;
} Password;

void generatePassword(char password[], int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    // Initialize password with null characters
    for (i = 0; i < length; i++) {
        password[i] = '\0';
    }

    // Fill password with random characters
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
}

int main() {
    char username[50];
    char password[50];
    int length;
    int numPasswords;

    // Get number of passwords to generate
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &numPasswords);

    // Generate passwords
    printf("\nEnter the desired password length (max 50): ");
    scanf("%d", &length);

    Password passwords[MAX_PASSWORDS];

    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("\nEnter username for password %d: ", i + 1);
        scanf("%s", passwords[i].username);

        generatePassword(passwords[i].password, length);
        passwords[i].length = length;

        printf("\nPassword for %s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}