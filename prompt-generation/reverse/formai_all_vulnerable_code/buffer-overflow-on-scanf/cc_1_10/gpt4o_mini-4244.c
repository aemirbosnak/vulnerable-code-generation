//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to reverse a string
void reverseString(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

int main() {
    char str[MAX_LENGTH];
    int choice;

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    do {
        printf("\nChoose an operation:\n");
        printf("1. Reverse the string\n");
        printf("2. Convert to uppercase\n");
        printf("3. Check if palindrome\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // flush the newline from input buffer

        switch (choice) {
            case 1:
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 2:
                toUpperCase(str);
                printf("Uppercase string: %s\n", str);
                break;
            case 3:
                if (isPalindrome(str)) {
                    printf("\"%s\" is a palindrome.\n", str);
                } else {
                    printf("\"%s\" is not a palindrome.\n", str);
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}