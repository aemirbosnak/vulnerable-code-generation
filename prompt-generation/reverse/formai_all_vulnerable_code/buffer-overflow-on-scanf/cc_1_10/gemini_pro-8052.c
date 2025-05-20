//GEMINI-pro DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password
typedef struct {
    char *password;
    char *website;
} Password;

// Define the array of passwords
Password passwords[NUM_PASSWORDS];

// Get a password from the user
char *get_password() {
    char *password = malloc(MAX_PASSWORD_LENGTH);
    printf("Enter your password: ");
    scanf("%s", password);
    return password;
}

// Get a website from the user
char *get_website() {
    char *website = malloc(MAX_PASSWORD_LENGTH);
    printf("Enter the website: ");
    scanf("%s", website);
    return website;
}

// Store a password in the array
void store_password(char *password, char *website) {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].password == NULL) {
            passwords[i].password = password;
            passwords[i].website = website;
            break;
        }
    }
}

// Print all the passwords in the array
void print_passwords() {
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (passwords[i].password != NULL) {
            printf("Password: %s\n", passwords[i].password);
            printf("Website: %s\n\n", passwords[i].website);
        }
    }
}

// Main function
int main() {
    // Get the passwords from the user
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        char *password = get_password();
        char *website = get_website();
        store_password(password, website);
    }

    // Print the passwords
    print_passwords();

    return 0;
}