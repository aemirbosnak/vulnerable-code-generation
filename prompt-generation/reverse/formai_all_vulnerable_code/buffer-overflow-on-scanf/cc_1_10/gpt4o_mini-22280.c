//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to remove whitespace from a string
void removeWhitespace(char *str) {
    char *ptr = str;
    while (*str != '\0') {
        if (!isspace((unsigned char)*str)) {
            *ptr++ = *str;
        }
        str++;
    }
    *ptr = '\0';
}

// Function to count vowels in a string
int countVowels(const char *str) {
    int count = 0;
    while (*str) {
        char c = tolower((unsigned char)*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

// Function to concatenate two strings
char* concatenateStrings(const char *str1, const char *str2) {
    char *result = malloc(strlen(str1) + strlen(str2) + 1);
    if (!result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// Function to duplicate a string
char* duplicateString(const char *str) {
    char *dup = malloc(strlen(str) + 1);
    if (!dup) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(dup, str);
    return dup;
}

// Function to print the menu and get user choice
int printMenu() {
    int choice;
    printf("String Manipulation Menu:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Reverse String\n");
    printf("3. Remove Whitespace\n");
    printf("4. Count Vowels\n");
    printf("5. Concatenate Two Strings\n");
    printf("6. Duplicate String\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    char input[MAX_LENGTH];
    char additional[MAX_LENGTH];
    int choice;

    while (1) {
        choice = printMenu();

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                getchar(); // to consume the newline left by scanf
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0'; // Removing the trailing newline
                toUpperCase(input);
                printf("Uppercase: %s\n", input);
                break;
            case 2:
                printf("Enter a string: ");
                getchar(); // to consume the newline
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0';
                reverseString(input);
                printf("Reversed: %s\n", input);
                break;
            case 3:
                printf("Enter a string: ");
                getchar(); // to consume the newline
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0';
                removeWhitespace(input);
                printf("Without whitespace: '%s'\n", input);
                break;
            case 4:
                printf("Enter a string: ");
                getchar(); // to consume the newline
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0';
                int vowelCount = countVowels(input);
                printf("Number of vowels: %d\n", vowelCount);
                break;
            case 5:
                printf("Enter the first string: ");
                getchar(); // to consume the newline
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0';
                printf("Enter the second string: ");
                fgets(additional, MAX_LENGTH, stdin);
                additional[strcspn(additional, "\n")] = '\0';
                char *concatenated = concatenateStrings(input, additional);
                printf("Concatenated: %s\n", concatenated);
                free(concatenated);
                break;
            case 6:
                printf("Enter a string: ");
                getchar(); // to consume the newline
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0';
                char *duplicated = duplicateString(input);
                printf("Duplicated: %s\n", duplicated);
                free(duplicated);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}