//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

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
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

// Function to count frequency of characters in a string
void countCharacterFrequency(char str[]) {
    int frequency[256] = {0};
    for (int i = 0; str[i]; i++) {
        frequency[(unsigned char)str[i]]++;
    }

    printf("Character Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", i, frequency[i]);
        }
    }
}

// Function to find a substring within a string
void findSubstring(char str[], char substr[]) {
    char *pos = strstr(str, substr);
    if (pos) {
        printf("Substring '%s' found at position %ld in '%s'.\n", 
            substr, (pos - str), str);
    } else {
        printf("Substring '%s' not found in '%s'.\n", substr, str);
    }
}

// Main function displaying a menu
int main() {
    char str[MAX_LENGTH];
    char substr[MAX_LENGTH];
    int choice;

    do {
        printf("String Manipulation Menu:\n");
        printf("1. Reverse a String\n");
        printf("2. Check if a String is a Palindrome\n");
        printf("3. Count Character Frequencies\n");
        printf("4. Find a Substring\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(str, MAX_LENGTH, stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                reverseString(str);
                printf("Reversed String: %s\n", str);
                break;

            case 2:
                printf("Enter a string to check for palindrome: ");
                fgets(str, MAX_LENGTH, stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                if (isPalindrome(str)) {
                    printf("\"%s\" is a palindrome.\n", str);
                } else {
                    printf("\"%s\" is not a palindrome.\n", str);
                }
                break;

            case 3:
                printf("Enter a string to count character frequencies: ");
                fgets(str, MAX_LENGTH, stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                countCharacterFrequency(str);
                break;

            case 4:
                printf("Enter the main string: ");
                fgets(str, MAX_LENGTH, stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                printf("Enter the substring to find: ");
                fgets(substr, MAX_LENGTH, stdin);
                substr[strcspn(substr, "\n")] = 0; // Remove newline character
                findSubstring(str, substr);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}