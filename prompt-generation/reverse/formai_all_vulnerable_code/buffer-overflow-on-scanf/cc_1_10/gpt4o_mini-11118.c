//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void toUpperCase(char *str);
void toLowerCase(char *str);
void reverseString(char *str);
void stringCopy(char *dest, const char *src);
void concatenateStrings(char *dest, const char *src);
void printMenu();
void clearBuffer();

// Main function
int main() {
    char inputString[256];
    char copiedString[256];
    char anotherString[256];
    int choice;

    printf("Enter a string (max 255 characters): ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove newline character

    do {
        printMenu();
        printf("Enter your choice (1-6, 0 to exit): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                printf("Original String: %s\n", inputString);
                toUpperCase(inputString);
                printf("Uppercase String: %s\n", inputString);
                break;
            case 2:
                printf("Original String: %s\n", inputString);
                toLowerCase(inputString);
                printf("Lowercase String: %s\n", inputString);
                break;
            case 3:
                printf("Original String: %s\n", inputString);
                reverseString(inputString);
                printf("Reversed String: %s\n", inputString);
                break;
            case 4:
                stringCopy(copiedString, inputString);
                printf("Copied String: %s\n", copiedString);
                break;
            case 5:
                printf("Enter another string to concatenate: ");
                fgets(anotherString, sizeof(anotherString), stdin);
                anotherString[strcspn(anotherString, "\n")] = 0; // Remove newline character
                concatenateStrings(inputString, anotherString);
                printf("Concatenated String: %s\n", inputString);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Convert string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Reverse the string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Copy one string to another
void stringCopy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

// Concatenate two strings
void concatenateStrings(char *dest, const char *src) {
    while (*dest) {
        dest++; // Move to the end of the destination string
    }
    while ((*dest++ = *src++)); // Copy the source string to the destination
}

// Print menu options
void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Reverse String\n");
    printf("4. Copy String\n");
    printf("5. Concatenate Another String\n");
    printf("6. Exit\n");
}

// Clear the input buffer to handle any excess characters
void clearBuffer() {
    while (getchar() != '\n');
}