//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASS_LENGTH 16
#define MIN_PASS_LENGTH 8

// Function to generate a random password
char* generate_password() {
    char* password = (char*) malloc(MAX_PASS_LENGTH * sizeof(char));
    srand(time(NULL));

    for (int i = 0; i < MAX_PASS_LENGTH; i++) {
        password[i] = rand() % 26 + 'a';
    }

    return password;
}

// Function to check if the password is valid
int check_password(char* password) {
    int len = strlen(password);

    if (len < MIN_PASS_LENGTH) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (password[i] == password[i - 1]) {
            return 0;
        }
    }

    return 1;
}

// Main function
int main() {
    char* password = generate_password();

    while (!check_password(password)) {
        free(password);
        password = generate_password();
    }

    printf("Your password is: %s\n", password);
    free(password);

    return 0;
}