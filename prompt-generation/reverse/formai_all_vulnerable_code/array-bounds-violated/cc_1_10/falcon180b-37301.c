//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];

    // Prompt user for number of passwords to generate
    printf("How many passwords do you want to generate? ");
    scanf("%d", &numPasswords);

    // Generate passwords
    for (int i = 0; i < numPasswords; i++) {
        // Prompt user for service name
        printf("Enter service name: ");
        scanf("%s", passwords[i].service);

        // Prompt user for username
        printf("Enter username: ");
        scanf("%s", passwords[i].username);

        // Prompt user for password length
        printf("Enter password length: ");
        int passwordLength;
        scanf("%d", &passwordLength);

        // Generate random password
        char password[MAX_PASSWORD_LENGTH];
        for (int j = 0; j < passwordLength; j++) {
            password[j] = (char) (rand() % 26 + 'a');
        }
        password[passwordLength] = '\0';

        // Copy password to password struct
        strcpy(passwords[i].password, password);
    }

    // Print passwords
    printf("\nPasswords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("Service: %s\nUsername: %s\nPassword: %s\n\n", passwords[i].service, passwords[i].username, passwords[i].password);
    }

    return 0;
}