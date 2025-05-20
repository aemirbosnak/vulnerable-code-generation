//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function prototypes
void reverseString(char str[]);
int isPalindrome(char str[]);
void concatenateStrings(char str1[], char str2[], char result[]);
void changeCase(char str[]);

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH], result[MAX_LENGTH * 2];
    int choice;

    printf("Welcome to the C String Manipulation Program!\n");
    printf("Please enter the first string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove newline character if present

    printf("Please enter the second string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove newline character if present

    do {
        printf("\nChoose an operation to perform:\n");
        printf("1. Reverse the first string\n");
        printf("2. Check if the first string is a palindrome\n");
        printf("3. Concatenate the two strings\n");
        printf("4. Change the case of the first string\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from buffer

        switch (choice) {
            case 1:
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 2:
                if (isPalindrome(str1)) {
                    printf("The first string is a palindrome!\n");
                } else {
                    printf("The first string is not a palindrome.\n");
                }
                break;

            case 3:
                concatenateStrings(str1, str2, result);
                printf("Concatenated string: %s\n", result);
                break;

            case 4:
                changeCase(str1);
                printf("String after case change: %s\n", str1);
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
void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

// Function to concatenate two strings
void concatenateStrings(char str1[], char str2[], char result[]) {
    strcpy(result, str1);         // Copy first string to result
    strcat(result, " ");          // Add a space between them
    strcat(result, str2);         // Concatenate the second string
}

// Function to change the case of a string
void changeCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}