//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void printMenu();
char *getInput();
void convertToUpper(char *str);
void convertToLower(char *str);
void reverseString(char *str);
void countVowels(char *str);
void findSubstring(char *str, char *substr);

// Entry point
int main() {
    char *inputString = NULL;
    int choice;

    // Loop for displaying the menu until the user chooses to exit
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after entering choice

        switch (choice) {
            case 1:
                inputString = getInput();
                break;
            case 2:
                if (inputString) {
                    convertToUpper(inputString);
                    printf("Uppercase: %s\n", inputString);
                } else {
                    printf("Please input a string first.\n");
                }
                break;
            case 3:
                if (inputString) {
                    convertToLower(inputString);
                    printf("Lowercase: %s\n", inputString);
                } else {
                    printf("Please input a string first.\n");
                }
                break;
            case 4:
                if (inputString) {
                    reverseString(inputString);
                    printf("Reversed: %s\n", inputString);
                } else {
                    printf("Please input a string first.\n");
                }
                break;
            case 5:
                if (inputString) {
                    countVowels(inputString);
                } else {
                    printf("Please input a string first.\n");
                }
                break;
            case 6:
                if (inputString) {
                    char substr[100];
                    printf("Enter substring to find: ");
                    fgets(substr, sizeof(substr), stdin);
                    substr[strcspn(substr, "\n")] = 0; // Remove newline
                    findSubstring(inputString, substr);
                } else {
                    printf("Please input a string first.\n");
                }
                break;
            case 7:
                free(inputString);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please choose between 1-7.\n");
        }
    }
}

// Function to display the options available to the user
void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Input a string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Convert to lowercase\n");
    printf("4. Reverse the string\n");
    printf("5. Count vowels\n");
    printf("6. Find a substring\n");
    printf("7. Exit\n");
}

// Function to get the input string from the user
char *getInput() {
    char *buffer = malloc(256 * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter a string: ");
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    return buffer;
}

// Function to convert the string to uppercase
void convertToUpper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert the string to lowercase
void convertToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to reverse the string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

// Function to count the vowels in the string
void countVowels(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);
}

// Function to find a substring within the string
void findSubstring(char *str, char *substr) {
    char *pos = strstr(str, substr);
    if (pos) {
        printf("Substring found at position: %ld\n", (long)(pos - str));
    } else {
        printf("Substring not found.\n");
    }
}