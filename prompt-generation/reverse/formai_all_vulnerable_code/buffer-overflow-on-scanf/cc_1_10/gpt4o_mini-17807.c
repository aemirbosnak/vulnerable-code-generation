//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

// Function prototype declarations
void displayMenu();
void reverseString(char *str);
void toUpperCase(char *str);
void toLowerCase(char *str);
void toggleCase(char *str);
void removeWhitespace(char *str);
void countVowelsConsonants(char *str);

int main() {
    char userInput[MAX_LENGTH];
    int choice;

    printf("Welcome to the Magical String Manipulator!\n");
    printf("Please enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(userInput, MAX_LENGTH, stdin);
    
    // Remove newline at the end of input
    userInput[strcspn(userInput, "\n")] = 0;

    do {
        displayMenu();
        printf("Choose an option (1-6) or 0 to exit: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                reverseString(userInput);
                break;
            case 2:
                toUpperCase(userInput);
                break;
            case 3:
                toLowerCase(userInput);
                break;
            case 4:
                toggleCase(userInput);
                break;
            case 5:
                removeWhitespace(userInput);
                break;
            case 6:
                countVowelsConsonants(userInput);
                break;
            case 0:
                printf("Exiting. Thank you for using the Magical String Manipulator!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- String Manipulation Options ---\n");
    printf("1. Reverse String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Convert to Lowercase\n");
    printf("4. Toggle Case\n");
    printf("5. Remove Whitespace\n");
    printf("6. Count Vowels and Consonants\n");
    printf("-----------------------------------\n");
}

void reverseString(char *str) {
    size_t len = strlen(str);
    char reversed[MAX_LENGTH];
    
    for (size_t i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    
    printf("Reversed String: %s\n", reversed);
}

void toUpperCase(char *str) {
    char upper[MAX_LENGTH];
    size_t len = strlen(str);
    
    for (size_t i = 0; i < len; i++) {
        upper[i] = toupper(str[i]);
    }
    upper[len] = '\0';
    
    printf("Uppercase String: %s\n", upper);
}

void toLowerCase(char *str) {
    char lower[MAX_LENGTH];
    size_t len = strlen(str);
    
    for (size_t i = 0; i < len; i++) {
        lower[i] = tolower(str[i]);
    }
    lower[len] = '\0';
    
    printf("Lowercase String: %s\n", lower);
}

void toggleCase(char *str) {
    char toggled[MAX_LENGTH];
    size_t len = strlen(str);
    
    for (size_t i = 0; i < len; i++) {
        if (isupper(str[i])) {
            toggled[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            toggled[i] = toupper(str[i]);
        } else {
            toggled[i] = str[i]; // Non-alphabet characters remain unchanged
        }
    }
    toggled[len] = '\0';
    
    printf("Toggled Case String: %s\n", toggled);
}

void removeWhitespace(char *str) {
    char noWhitespace[MAX_LENGTH];
    size_t index = 0;
    
    for (size_t i = 0; str[i]; i++) {
        if (!isspace((unsigned char)str[i])) {
            noWhitespace[index++] = str[i];
        }
    }
    noWhitespace[index] = '\0';
    
    printf("String without Whitespace: %s\n", noWhitespace);
}

void countVowelsConsonants(char *str) {
    int vowels = 0;
    int consonants = 0;
    
    for (size_t i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}