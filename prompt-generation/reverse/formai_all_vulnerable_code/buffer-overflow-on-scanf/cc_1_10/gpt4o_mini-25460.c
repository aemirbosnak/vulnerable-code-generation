//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_INPUT_LENGTH 200

void printMenu() {
    printf("\nString Manipulation Utility\n");
    printf("1. Concatenate Strings\n");
    printf("2. Search Substring\n");
    printf("3. Reverse String\n");
    printf("4. Convert to Uppercase\n");
    printf("5. Convert to Lowercase\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

void concatenateStrings() {
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];

    printf("Enter first string: ");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, MAX_STRING_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character

    char result[MAX_STRING_LENGTH * 2];
    snprintf(result, sizeof(result), "%s%s", str1, str2);
    printf("Concatenated String: %s\n", result);
}

void searchSubstring() {
    char str[MAX_STRING_LENGTH], substr[MAX_STRING_LENGTH];
    
    printf("Enter the main string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    printf("Enter the substring to search: ");
    fgets(substr, MAX_STRING_LENGTH, stdin);
    substr[strcspn(substr, "\n")] = '\0'; // Remove newline character
    
    if (strstr(str, substr)) {
        printf("Substring found in the main string.\n");
    } else {
        printf("Substring not found in the main string.\n");
    }
}

void reverseString() {
    char str[MAX_STRING_LENGTH];

    printf("Enter string to reverse: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    int len = strlen(str);
    char reversed[MAX_STRING_LENGTH];
    
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    
    printf("Reversed String: %s\n", reversed);
}

void convertToUppercase() {
    char str[MAX_STRING_LENGTH];

    printf("Enter string to convert to uppercase: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    
    printf("Uppercase String: %s\n", str);
}

void convertToLowercase() {
    char str[MAX_STRING_LENGTH];

    printf("Enter string to convert to lowercase: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    
    printf("Lowercase String: %s\n", str);
}

int main() {
    int choice;
    
    do {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                searchSubstring();
                break;
            case 3:
                reverseString();
                break;
            case 4:
                convertToUppercase();
                break;
            case 5:
                convertToLowercase();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}