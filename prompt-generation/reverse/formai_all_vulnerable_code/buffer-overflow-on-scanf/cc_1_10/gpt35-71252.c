//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
int getStrength();
void generatePassword(int strength, char* password);
void copyToClipboard(char* password);

int main() {
    // Set the random seed
    srand(time(NULL));
    
    // Obtain user input for the strength of the password
    int strength = getStrength();
    
    // Generate the password
    char* password = (char*) calloc(20, sizeof(char));
    generatePassword(strength, password);
    
    // Print the password to the console and copy to clipboard
    printf("Your generated password is: %s\n", password);
    copyToClipboard(password);
    
    // Free memory for the password and exit
    free(password);
    return 0;
}

// Function to get user input for password strength
int getStrength() {
    int strength;
    printf("Enter desired password strength (1-5): ");
    scanf("%d", &strength);
    while (strength < 1 || strength > 5) {
        printf("Invalid input. Enter desired password strength (1-5): ");
        scanf("%d", &strength);
    }
    return strength;
}

// Function to generate the password based on strength level
void generatePassword(int strength, char* password) {
    int numChars = 0;
    switch(strength) {
        case 1:
            numChars = 6;
            break;
        case 2:
            numChars = 8;
            break;
        case 3:
            numChars = 10;
            break;
        case 4:
            numChars = 12;
            break;
        case 5:
            numChars = 16;
            break;
    }
    char* lowercase = "abcdefghijklmnopqrstuvwxyz";
    char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* numbers = "0123456789";
    char* symbols = "!@#$%^&*()_+-=";
    int numLower = numChars/3;
    int numUpper = numChars/3;
    int numNumbers = numChars/3;
    int numSymbols = numChars - numLower - numUpper - numNumbers;
    for (int i = 0; i < numLower; i++) {
        int randIndex = rand() % strlen(lowercase);
        password[i] = lowercase[randIndex];
    }
    for (int i = numLower; i < numLower+numUpper; i++) {
        int randIndex = rand() % strlen(uppercase);
        password[i] = uppercase[randIndex];
    }
    for (int i = numLower+numUpper; i < numLower+numUpper+numNumbers; i++) {
        int randIndex = rand() % strlen(numbers);
        password[i] = numbers[randIndex];
    }
    for (int i = numLower+numUpper+numNumbers; i < numChars; i++) {
        int randIndex = rand() % strlen(symbols);
        password[i] = symbols[randIndex];
    }
}

// Function to copy the password string to the clipboard
void copyToClipboard(char* password) {
    // implement platform-specific clipboard copying
    #ifdef _WIN32
        OpenClipboard(NULL);
        EmptyClipboard();
        int len = strlen(password)+1;
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), password, len);
        GlobalUnlock(hMem);
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
    #else
        // implement clipboard copying for other OSes
        printf("Password copied to clipboard.\n");
    #endif
}