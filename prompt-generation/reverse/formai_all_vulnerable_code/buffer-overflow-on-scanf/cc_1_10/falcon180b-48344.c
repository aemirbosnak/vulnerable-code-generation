//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

// Function prototypes
void generateRandomCode(char code[MAX_CODE_LENGTH]);
int isValidCode(char code[MAX_CODE_LENGTH]);

int main() {
    char userCode[MAX_CODE_LENGTH];
    char generatedCode[MAX_CODE_LENGTH];
    int isValid;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a 6-character color code (e.g. #FF0000): ");
    scanf("%s", userCode);

    // Validate user input
    isValid = isValidCode(userCode);
    if (!isValid) {
        printf("Invalid color code. Please enter a valid 6-character code.\n");
        return 1;
    }

    // Generate a random color code
    generateRandomCode(generatedCode);

    printf("\nYour color code is: %s\n", userCode);
    printf("Random color code: %s\n", generatedCode);

    return 0;
}

// Generates a random 6-character color code
void generateRandomCode(char code[MAX_CODE_LENGTH]) {
    const char hexChars[] = "0123456789ABCDEF";
    int i;

    for (i = 0; i < MAX_CODE_LENGTH; i++) {
        code[i] = hexChars[rand() % 16];
    }
    code[MAX_CODE_LENGTH - 1] = '\0'; // Add null terminator
}

// Checks if a given string is a valid 6-character color code
int isValidCode(char code[MAX_CODE_LENGTH]) {
    if (strlen(code)!= MAX_CODE_LENGTH) {
        return 0;
    }

    if (code[0]!= '#') {
        return 0;
    }

    // Check remaining characters
    int i;
    for (i = 1; i < MAX_CODE_LENGTH; i++) {
        if (!isxdigit(code[i])) {
            return 0;
        }
    }

    return 1;
}