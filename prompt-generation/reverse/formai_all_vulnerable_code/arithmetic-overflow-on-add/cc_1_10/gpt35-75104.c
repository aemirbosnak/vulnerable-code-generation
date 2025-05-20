//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random characters
char generate_random_character() {
    char c;
    int random = rand() % 3;

    switch(random) {
        case 0:
            c = rand() % 26 + 'a';
            break;
        case 1:
            c = rand() % 26 + 'A';
            break;
        case 2:
            c = rand() % 10 + '0';
            break;
        default:
            c = rand() % 26 + 'a';
            break;
    }

    return c;
}

// Function to generate secure password 
char* generate_secure_password(int length) {
    char* password = malloc((length + 1) * sizeof(char));
    srand(time(NULL));

    for(int i = 0; i < length; ++i) {
        password[i] = generate_random_character();
    }

    password[length] = '\0'; // String termination character

    return password;
}

int main() {
    printf("Welcome to Secure Password Generator!\n");

    // Get password length from user
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    // Generate password and print to console
    char* password = generate_secure_password(length);
    printf("Your new password is: %s\n", password);

    free(password); // Free password memory

    return 0;
}