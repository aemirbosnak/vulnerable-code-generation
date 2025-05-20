//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
void concatenateStrings();
void compareStrings();
void reverseString();
void findSubstring();
void convertToUpper();
void convertToLower();
void clearBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-7, 0 to exit): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear input buffer

        switch (choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                compareStrings();
                break;
            case 3:
                reverseString();
                break;
            case 4:
                findSubstring();
                break;
            case 5:
                convertToUpper();
                break;
            case 6:
                convertToLower();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Concatenate Two Strings\n");
    printf("2. Compare Two Strings\n");
    printf("3. Reverse a String\n");
    printf("4. Find a Substring\n");
    printf("5. Convert String to Uppercase\n");
    printf("6. Convert String to Lowercase\n");
    printf("0. Exit\n");
}

void concatenateStrings() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character

    char result[200];
    strcpy(result, str1);
    strcat(result, str2);

    printf("Concatenated String: %s\n", result);
}

void compareStrings() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character

    int result = strcmp(str1, str2);
    if (result < 0) {
        printf("'%s' is less than '%s'\n", str1, str2);
    } else if (result > 0) {
        printf("'%s' is greater than '%s'\n", str1, str2);
    } else {
        printf("Both strings are equal.\n");
    }
}

void reverseString() {
    char str[100];
    
    printf("Enter a string to reverse: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    int len = strlen(str);
    char reversed[100];

    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';

    printf("Reversed String: %s\n", reversed);
}

void findSubstring() {
    char str[100], sub[100];

    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    printf("Enter the substring to find: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = '\0'; // Remove newline character

    if (strstr(str, sub) != NULL) {
        printf("The substring '%s' is found in '%s'.\n", sub, str);
    } else {
        printf("The substring '%s' is not found in '%s'.\n", sub, str);
    }
}

void convertToUpper() {
    char str[100];
    
    printf("Enter a string to convert to uppercase: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }

    printf("Uppercase String: %s\n", str);
}

void convertToLower() {
    char str[100];
    
    printf("Enter a string to convert to lowercase: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }

    printf("Lowercase String: %s\n", str);
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear the input buffer
}