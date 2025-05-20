//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomInt(int max);
char generateRandomChar();
void generatePassword();

int main() {
    int numPasswords;

    printf("How many passwords do you want to generate? ");
    scanf("%d", &numPasswords);

    printf("\nGenerating %d passwords...\n\n", numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        generatePassword();
    }

    printf("\nDone!\n");

    return 0;
}

int generateRandomInt(int max) {
    // Generate a random integer between 0 and max (inclusive)
    return rand() % (max + 1);
}

char generateRandomChar() {
    // Generate a random character between '!' (ASCII value 33) and '~' (ASCII value 126)
    return (char) (generateRandomInt('~' - '!') + '!');
}

void generatePassword() {
    int length = 12; // Password length of 12 characters
    char password[length + 1]; // Array for password, plus one for null terminator
    password[length] = '\0'; // Add null terminator at end of array

    srand(time(NULL)); // Initialize random number generator with current time

    // Generate the password characters
    for (int i = 0; i < length; i++) {
        password[i] = generateRandomChar();
    }

    printf("%s\n", password);
}