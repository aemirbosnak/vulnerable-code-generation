//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 256
#define MAX_WORD_SIZE 50

// Function prototypes
void toUpperCase(char *str);
void toLowerCase(char *str);
int countWords(const char *str);
void reverseString(char *str);
void removeExtraSpaces(char *str);
void displayMenu();

int main() {
    char inputString[MAX_STRING_SIZE];
    int choice;

    printf("Welcome to the Creative C String Manipulator!\n");
    printf("Please enter a string (max 255 characters): ");
    fgets(inputString, MAX_STRING_SIZE, stdin);
    inputString[strcspn(inputString, "\n")] = 0;  // Remove newline character

    do {
        displayMenu();
        printf("Enter your choice (1-6, 0 to exit): ");
        scanf("%d", &choice);
        getchar();  // Consume newline character after scanf

        switch (choice) {
            case 1:
                toUpperCase(inputString);
                printf("Uppercase: %s\n", inputString);
                break;

            case 2:
                toLowerCase(inputString);
                printf("Lowercase: %s\n", inputString);
                break;

            case 3:
                printf("Word count: %d\n", countWords(inputString));
                break;

            case 4:
                reverseString(inputString);
                printf("Reversed: %s\n", inputString);
                break;

            case 5:
                removeExtraSpaces(inputString);
                printf("String after removing extra spaces: '%s'\n", inputString);
                break;

            case 6:
                printf("Original string: '%s'\n", inputString);
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int countWords(const char *str) {
    int count = 0;
    int inWord = 0;

    for (const char *c = str; *c; c++) {
        if (isspace(*c)) {
            if (inWord) {
                inWord = 0;  // We just left a word
            }
        } else {
            if (!inWord) {
                inWord = 1;  // We just entered a word
                count++;
            }
        }
    }
    return count;
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

void removeExtraSpaces(char *str) {
    char *current = str;
    char *result = str;
    int spaceFound = 0;

    while (*current) {
        if (isspace(*current)) {
            if (!spaceFound) {
                *result++ = *current;
                spaceFound = 1;  // Space found
            }
        } else {
            *result++ = *current;  // Copy non-space character
            spaceFound = 0;       // Reset space finder
        }
        current++;
    }
    *result = '\0';  // Null-terminate the new string
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Count Words\n");
    printf("4. Reverse String\n");
    printf("5. Remove Extra Spaces\n");
    printf("6. Show Original String\n");
    printf("0. Exit Program\n");
}