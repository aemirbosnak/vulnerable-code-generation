//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256

// Function prototypes
char* reverseString(const char* str);
int countVowels(const char* str);
char* replaceChar(const char* str, char oldChar, char newChar);
void toUpperCase(char* str);
void printMenu();
void clearBuffer();

int main() {
    char* str = (char*)malloc(MAX_SIZE * sizeof(char));
    if (!str) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter a string (max %d characters): ", MAX_SIZE - 1);
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = 0;  // Remove trailing newline

    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: {
                char* reversed = reverseString(str);
                printf("Reversed String: %s\n", reversed);
                free(reversed);  // Freeing the allocated memory for the reversed string
                break;
            }
            case 2: {
                int vowels = countVowels(str);
                printf("Number of vowels: %d\n", vowels);
                break;
            }
            case 3: {
                char oldChar, newChar;
                printf("Enter character to replace: ");
                scanf(" %c", &oldChar);
                printf("Enter new character: ");
                scanf(" %c", &newChar);
                char* replacedStr = replaceChar(str, oldChar, newChar);
                printf("Modified String: %s\n", replacedStr);
                free(replacedStr);  // Freeing the allocated memory for the modified string
                break;
            }
            case 4: {
                toUpperCase(str);
                printf("Uppercase String: %s\n", str);
                break;
            }
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    } while (choice != 5);

    free(str); // Freeing the allocated memory for input string
    return 0;
}

char* reverseString(const char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    if (!reversed) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0'; // Null-terminate the reversed string
    return reversed;
}

int countVowels(const char* str) {
    int count = 0;
    while (*str) {
        char lowerChar = tolower(*str);
        if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' ||
            lowerChar == 'o' || lowerChar == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

char* replaceChar(const char* str, char oldChar, char newChar) {
    char* modifiedStr = (char*)malloc((strlen(str) + 1) * sizeof(char));
    if (!modifiedStr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; str[i] != '\0'; i++) {
        modifiedStr[i] = (str[i] == oldChar) ? newChar : str[i];
    }
    modifiedStr[strlen(str)] = '\0'; // Null-terminate the modified string
    return modifiedStr;
}

void toUpperCase(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse the string\n");
    printf("2. Count vowels in the string\n");
    printf("3. Replace a character in the string\n");
    printf("4. Convert string to uppercase\n");
    printf("5. Exit\n");
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear the input buffer
}