//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

void trimWhitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return; // All spaces

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

void printMenu() {
    printf("String Manipulation Program\n");
    printf("============================\n");
    printf("1. Reverse a string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Check for palindrome\n");
    printf("4. Trim whitespace\n");
    printf("5. Exit\n");
}

int main() {
    char input[MAX_STRING_LENGTH];
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        if (choice == 5) break;

        printf("Enter a string: ");
        getchar(); // Consume newline left by scanf
        if (fgets(input, sizeof(input), stdin) == NULL) {
            fprintf(stderr, "Error reading input string.\n");
            continue;
        }
        trimWhitespace(input);
        // Remove the newline character from fgets
        input[strcspn(input, "\n")] = 0;

        switch (choice) {
            case 1:
                reverseString(input);
                printf("Reversed string: %s\n", input);
                break;
            case 2:
                toUpperCase(input);
                printf("Uppercase string: %s\n", input);
                break;
            case 3:
                if (isPalindrome(input))
                    printf("\"%s\" is a palindrome.\n", input);
                else
                    printf("\"%s\" is not a palindrome.\n", input);
                break;
            case 4:
                trimWhitespace(input);
                printf("Trimmed string: \"%s\"\n", input);
                break;
            default:
                fprintf(stderr, "Invalid choice. Please try again.\n");
                break;
        }
    }

    printf("Exiting program. Goodbye!\n");
    return 0;
}