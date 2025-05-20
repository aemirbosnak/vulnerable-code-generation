//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64
#define MAX_SPECIAL_CHARS 4

char *generate_password(int length) {

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        return NULL;
    }

    // Seed the random number generator with the current time.
    srand(time(NULL));

    // Allocate memory for the password.
    char *password = malloc(length + 1);
    if (password == NULL) {
        printf("Error allocating memory for password.\n");
        return NULL;
    }

    // Generate a random password.
    for (int i = 0; i < length; i++) {
        int type = rand() % 4;
        switch (type) {
            case 0:
                password[i] = 'a' + (rand() % 26);
                break;
            case 1:
                password[i] = 'A' + (rand() % 26);
                break;
            case 2:
                password[i] = '0' + (rand() % 10);
                break;
            case 3:
                password[i] = "!@#$%^&*()_+=-`~"[rand() % MAX_SPECIAL_CHARS];
                break;
        }
    }

    // Null-terminate the password.
    password[length] = '\0';

    // Return the password.
    return password;
}

int main() {

    // Get the password length from the user.
    int length;
    printf("Enter the desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    // Generate the password.
    char *password = generate_password(length);

    // Print the password.
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password.
    free(password);

    return 0;
}