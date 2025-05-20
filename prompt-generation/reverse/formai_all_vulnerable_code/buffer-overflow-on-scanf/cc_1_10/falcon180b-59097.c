//Falcon-180B DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

// Define the structure for storing passwords
typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    // Prompt the user for the number of passwords they want to store
    printf("How many passwords do you want to store? (Max %d): ", MAX_PASSWORDS);
    scanf("%d", &numPasswords);

    // Prompt the user for each password and store it in the passwords array
    for (int i = 0; i < numPasswords; i++) {
        printf("Enter password %d: ", i+1);
        scanf("%s", passwords[i].password);
        passwords[i].length = strlen(passwords[i].password);
    }

    // Prompt the user for the password they want to retrieve
    printf("Enter the password you want to retrieve: ");
    char searchPassword[MAX_PASSWORD_LENGTH];
    scanf("%s", searchPassword);

    // Search for the password in the passwords array
    int passwordIndex = -1;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].password, searchPassword) == 0) {
            passwordIndex = i;
            break;
        }
    }

    // Display the retrieved password
    if (passwordIndex!= -1) {
        printf("Password found!\n");
        printf("Password: %s\n", passwords[passwordIndex].password);
        printf("Password length: %d\n", passwords[passwordIndex].length);
    } else {
        printf("Password not found.\n");
    }

    return 0;
}