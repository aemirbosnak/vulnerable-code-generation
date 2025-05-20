//Falcon-180B DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 32
#define HASH_LENGTH 64

// Function to generate a random string of given length
char *generate_random_string(int length) {
    char *result = malloc(length + 1);
    if (result == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        result[i] = 'a' + rand() % 26;
    }

    result[length] = '\0';
    return result;
}

// Function to hash a password
char *hash_password(char *password) {
    char *result = malloc(HASH_LENGTH + 1);
    if (result == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }

    for (int i = 0; i < HASH_LENGTH; i++) {
        result[i] = 'a' + rand() % 26;
    }

    result[HASH_LENGTH] = '\0';
    return result;
}

// Function to compare two hashed passwords
int compare_hashed_passwords(char *password1, char *password2) {
    return strcmp(password1, password2) == 0;
}

int main() {
    char *password = generate_random_string(PASSWORD_LENGTH);
    char *hashed_password = hash_password(password);

    printf("Your password is: %s\n", password);
    printf("Your hashed password is: %s\n", hashed_password);

    free(password);
    free(hashed_password);

    return 0;
}