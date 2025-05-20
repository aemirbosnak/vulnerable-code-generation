//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void reverseString(char *str);
void toUpperCase(char *str);
int countVowels(const char *str);
void substituteCharacter(char *str, char toReplace, char replacement);

int main() {
    char inputString[100];
    int choice;
    
    // User instructions
    printf("Welcome to the String Manipulation Program!\n");
    printf("Please enter a string (max 99 characters): ");
    fgets(inputString, sizeof(inputString), stdin);
    // Remove the newline character if it is present
    inputString[strcspn(inputString, "\n")] = 0;

    // Menu for string manipulations
    do {
        printf("\nChoose an operation:\n");
        printf("1. Reverse the string\n");
        printf("2. Convert to uppercase\n");
        printf("3. Count vowels\n");
        printf("4. Substitute a character\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character left by scanf

        switch (choice) {
            case 1:
                reverseString(inputString);
                printf("Reversed String: %s\n", inputString);
                break;
            case 2:
                toUpperCase(inputString);
                printf("Uppercase String: %s\n", inputString);
                break;
            case 3:
                {
                    int vowelCount = countVowels(inputString);
                    printf("Number of vowels: %d\n", vowelCount);
                }
                break;
            case 4:
                {
                    char toReplace, replacement;
                    printf("Enter the character to replace: ");
                    scanf(" %c", &toReplace);
                    printf("Enter the replacement character: ");
                    scanf(" %c", &replacement);
                    substituteCharacter(inputString, toReplace, replacement);
                    printf("Modified String: %s\n", inputString);
                }
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Function to count vowels in a string
int countVowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower((unsigned char)str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// Function to substitute a character in a string
void substituteCharacter(char *str, char toReplace, char replacement) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == toReplace) {
            str[i] = replacement;
        }
    }
}