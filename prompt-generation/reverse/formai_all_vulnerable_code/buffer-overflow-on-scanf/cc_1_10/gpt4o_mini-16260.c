//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void reverseString(char *str);
void convertToUpper(char *str);
int stringLength(const char *str);
int isPalindrome(const char *str);
void displayMenu();

// Main function
int main() {
    char str[100];
    int choice;

    // Get user input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 2:
                convertToUpper(str);
                printf("Uppercase string: %s\n", str);
                break;
            case 3:
                printf("Length of string: %d\n", stringLength(str));
                break;
            case 4:
                if (isPalindrome(str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert a string to uppercase
void convertToUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to find the length of a string
int stringLength(const char *str) {
    return strlen(str);
}

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Reverse the string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Find length of the string\n");
    printf("4. Check if the string is a palindrome\n");
    printf("5. Exit\n");
}