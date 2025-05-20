//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define CHAR_COUNT 45

int main() {
    char password[MAX_LENGTH + 1];
    int length, index1, index2;

    srand(time(NULL)); // Seed RNG with current time

    printf("Generating a secure password with a length between %d and %d characters...\n", MIN_LENGTH, MAX_LENGTH);

    length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;

    printf("Password length: %d\n", length);

    memset(password, 0, sizeof(password)); // Initialize password array with zeros

    printf("Generating %d random characters...\n", length);

    for (int i = 0; i < length; i++) {
        int charType = rand() % 3; // 0: Lowercase, 1: Uppercase, 2: Special character
        int charIndex;

        if (charType == 0) {
            charIndex = rand() % 26;
            password[i] = 'a' + charIndex;
        } else if (charType == 1) {
            charIndex = rand() % 26;
            password[i] = 'A' + charIndex;
        } else {
            charIndex = rand() % CHAR_COUNT;
            password[i] = "!@#$%^&*()-_+={[}]|\\:\"<>,.?/"[charIndex];
        }
    }

    // Shuffle password array to add some randomness
    for (int i = 0; i < length; i++) {
        index1 = rand() % length;
        index2 = rand() % length;
        char temp = password[index1];
        password[index1] = password[index2];
        password[index2] = temp;
    }

    printf("Your secure password is: %s\n", password);

    return 0;
}

// Function to check if a character is alphanumeric or a special character
int isValidChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (strchr("!@#$%^&*()-_+={[}]|\\:\"<>,.?/", c) != NULL)) {
        return 1;
    }
    return 0;
}