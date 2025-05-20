//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

// Function prototypes
void reverseString(char str[]);
int countVowels(const char str[]);
void findLongestWord(const char str[], char longestWord[]);
void convertToUppercase(char str[]);

int main() {
    char input[MAX_LENGTH];
    char longestWord[MAX_WORD_LENGTH];
    int choice;

    printf("Welcome to the C String Manipulation Program!\n");
    printf("----------------------------------------------\n");

    do {
        printf("\nMenu:\n");
        printf("1. Reverse a string\n");
        printf("2. Count vowels in a string\n");
        printf("3. Find longest word in a sentence\n");
        printf("4. Convert string to uppercase\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                reverseString(input);
                printf("Reversed string: %s\n", input);
                break;

            case 2:
                printf("Enter a string to count vowels: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                printf("Number of vowels: %d\n", countVowels(input));
                break;

            case 3:
                printf("Enter a sentence to find the longest word: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                findLongestWord(input, longestWord);
                printf("Longest word: %s\n", longestWord);
                break;

            case 4:
                printf("Enter a string to convert to uppercase: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                convertToUppercase(input);
                printf("Uppercase string: %s\n", input);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to reverse a string
void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to count vowels in a string
int countVowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Function to find the longest word in a sentence
void findLongestWord(const char str[], char longestWord[]) {
    char temp[MAX_WORD_LENGTH];
    int maxLen = 0;
    int len = 0;

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            temp[len++] = str[i];
        } else {
            temp[len] = '\0'; // Null-terminate the current word
            if (len > maxLen) {
                maxLen = len;
                strcpy(longestWord, temp);
            }
            len = 0; // Reset length for the next word
            if (str[i] == '\0') break; // End of string
        }
    }
}

// Function to convert a string to uppercase
void convertToUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}