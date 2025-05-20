//Gemma-7B DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int used;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int i = 0;
    char new_password[20];
    char confirm_password[20];

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].password = NULL;
        passwords[i].used = 0;
    }

    printf("Welcome to the Password Vault!\n");

    // Add a new password
    printf("Enter a new password: ");
    scanf("%s", new_password);

    // Confirm the password
    printf("Confirm your password: ");
    scanf("%s", confirm_password);

    // Check if the passwords match
    if (strcmp(new_password, confirm_password) == 0) {
        // Allocate memory for the new password
        passwords[i].name = malloc(20);
        passwords[i].password = malloc(20);

        // Store the new password
        strcpy(passwords[i].name, new_password);
        passwords[i].used = 1;

        // Print a confirmation message
        printf("Password added successfully!\n");
    } else {
        // Print an error message
        printf("Error: passwords do not match.\n");
    }

    return 0;
}