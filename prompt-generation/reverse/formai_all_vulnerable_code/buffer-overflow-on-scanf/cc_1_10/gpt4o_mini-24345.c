//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 128
#define NUM_UPPERCASE 26
#define NUM_LOWERCASE 26
#define NUM_DIGITS 10
#define NUM_SPECIAL_CHARS 32

// Function prototypes
void generatePassword(char *password, int length);
void addCharacterSet(char *set, const char *source, int *index, int count);
void shuffleArray(char *array, int n);
void printPassword(const char *password, int length);
int isSecurePassword(const char *password, int length);

int main() {
    int passwordLength;
    char password[MAX_PASSWORD_LENGTH + 1]; // +1 for null-terminator

    // Seed random number generator
    srand((unsigned int)time(NULL));

    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter desired password length (1 to %d): ", MAX_PASSWORD_LENGTH);
    if (scanf("%d", &passwordLength) != 1 || passwordLength < 1 || passwordLength > MAX_PASSWORD_LENGTH) {
        fprintf(stderr, "Invalid password length. Exiting.\n");
        return 1;
    }

    generatePassword(password, passwordLength);
    printf("Generated Password: ");
    printPassword(password, passwordLength);

    return 0;
}

void generatePassword(char *password, int length) {
    const char uppercase[NUM_UPPERCASE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase[NUM_LOWERCASE] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[NUM_DIGITS] = "0123456789";
    const char specialChars[NUM_SPECIAL_CHARS] = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    char passwordPool[MAX_PASSWORD_LENGTH];
    int poolIndex = 0;

    // Ensure that password includes at least one character from each set
    addCharacterSet(passwordPool, uppercase, &poolIndex, 1);
    addCharacterSet(passwordPool, lowercase, &poolIndex, 1);
    addCharacterSet(passwordPool, digits, &poolIndex, 1);
    addCharacterSet(passwordPool, specialChars, &poolIndex, 1);

    // Fill remaining length of password with random characters from all sets
    int remainingLength = length - 4; // 4 already added from each character set
    for (int i = 0; i < remainingLength; i++) {
        int randomSet = rand() % 4;
        switch (randomSet) {
            case 0: 
                passwordPool[poolIndex++] = uppercase[rand() % NUM_UPPERCASE];
                break;
            case 1: 
                passwordPool[poolIndex++] = lowercase[rand() % NUM_LOWERCASE];
                break;
            case 2: 
                passwordPool[poolIndex++] = digits[rand() % NUM_DIGITS];
                break;
            case 3: 
                passwordPool[poolIndex++] = specialChars[rand() % NUM_SPECIAL_CHARS];
                break;
        }
    }

    // Null terminate the pool and shuffle it
    passwordPool[poolIndex] = '\0';
    shuffleArray(passwordPool, poolIndex);

    // Copy the final password to the output variable
    strncpy(password, passwordPool, length);
    password[length] = '\0'; // Null terminate the final password
}

void addCharacterSet(char *set, const char *source, int *index, int count) {
    for (int i = 0; i < count; i++) {
        char randomChar = source[rand() % strlen(source)];
        set[(*index)++] = randomChar;
    }
}

// Shuffle function to randomize the order of characters in the password
void shuffleArray(char *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() % (n - i);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void printPassword(const char *password, int length) {
    for (int i = 0; i < length; i++) {
        putchar(password[i]);
    }
    putchar('\n');
}

int isSecurePassword(const char *password, int length) {
    // Placeholder for future implementation of password security checks
    return 1; // Currently valid, can implement checks like length, diversity etc.
}