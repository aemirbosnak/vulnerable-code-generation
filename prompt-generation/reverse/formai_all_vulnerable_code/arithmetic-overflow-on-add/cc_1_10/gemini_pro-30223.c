//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Function to generate a random password
char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        return NULL;
    }

    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Generate a random password
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 94 + 33;
        password[i] = (char)random_number;
    }

    // Terminate the string
    password[length] = '\0';

    return password;
}

int main() {
    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generate_password(length);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}