//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 50

// Function to generate a random password
void generate_password(char *password, int length) {
    const char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz"
                              "0123456789"
                              "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }

    password[length] = '\0';
}

// Function to prompt the user for a password length
int prompt_password_length() {
    int length;

    printf("Enter the desired length of the password (between 1 and %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    while (length < 1 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid length. Please enter a value between 1 and %d: ", MAX_PASSWORD_LENGTH);
        scanf("%d", &length);
    }

    return length;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for a password length
    length = prompt_password_length();

    // Generate a random password
    generate_password(password, length);

    // Print the generated password
    printf("Your secure password is: %s\n", password);

    return 0;
}