//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL "/*!@#$%^&*()-_+=~`|:;'<>,.?/"
#define CHAR_SETS 4

void generatePassword(int length, char *password) {
    const char *charSets[CHAR_SETS] = {UPPERCASE, LOWERCASE, DIGITS, SPECIAL};
    int charSetSizes[CHAR_SETS] = {
        strlen(UPPERCASE),
        strlen(LOWERCASE),
        strlen(DIGITS),
        strlen(SPECIAL)
    };

    // Ensure at least one character from each set is included
    password[0] = charSets[0][rand() % charSetSizes[0]]; // Uppercase
    password[1] = charSets[1][rand() % charSetSizes[1]]; // Lowercase
    password[2] = charSets[2][rand() % charSetSizes[2]]; // Digit
    password[3] = charSets[3][rand() % charSetSizes[3]]; // Special

    // Fill the rest of the password length
    for (int i = 4; i < length; i++) {
        int setIndex = rand() % CHAR_SETS;
        password[i] = charSets[setIndex][rand() % charSetSizes[setIndex]];
    }

    // Shuffle the password to randomize positions
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    password[length] = '\0'; // Null-terminate the string
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    char password[MAX_LENGTH];
    int length;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Let's create a super strong password for you!\n");

    // Input password length from user
    do {
        printf("Enter desired password length (minimum 8 characters): ");
        scanf("%d", &length);
        if (length < 8) {
            printf("A strong password needs to be at least 8 characters long!\n");
        }
    } while (length < 8 || length > MAX_LENGTH);

    generatePassword(length, password);
    
    printf("Congratulations! Your secure password is: %s\n", password);
    printf("Remember to keep your password safe and do not share it with anyone!\n");
    
    return 0;
}