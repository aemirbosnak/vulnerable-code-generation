//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

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

// Function to concatenate two strings with a space in between
char* concatenateWithSpace(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char *)malloc(len1 + len2 + 2); // +1 for space, +1 for null terminator
    if (result) {
        strcpy(result, str1);
        strcat(result, " ");
        strcat(result, str2);
    } else {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return result;
}

// Function to count vowels in a string
int countVowels(const char *str) {
    int count = 0;
    const char *vowels = "aeiouAEIOU";
    for (int i = 0; str[i]; i++) {
        if (strchr(vowels, str[i])) {
            count++;
        }
    }
    return count;
}

// Helper function to display menu options
void displayMenu() {
    printf("Choose a string operation:\n");
    printf("1. Convert to uppercase\n");
    printf("2. Reverse string\n");
    printf("3. Concatenate two strings\n");
    printf("4. Count vowels in a string\n");
    printf("5. Exit\n");
}

// Main function
int main() {
    int choice;
    char str1[100], str2[100];

    while (1) {
        displayMenu(); 
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1: // Convert to uppercase
                printf("Enter a string: ");
                getchar(); // Clear the newline character from input buffer
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove trailing newline
                toUpperCase(str1);
                printf("Uppercase string: %s\n", str1);
                break;

            case 2: // Reverse string
                printf("Enter a string: ");
                getchar();
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 3: // Concatenate two strings
                printf("Enter first string: ");
                getchar();
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;

                {
                    char *result = concatenateWithSpace(str1, str2);
                    printf("Concatenated string: %s\n", result);
                    free(result);
                }
                break;

            case 4: // Count vowels
                printf("Enter a string: ");
                getchar();
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                int vowelCount = countVowels(str1);
                printf("Number of vowels in the string: %d\n", vowelCount);
                break;

            case 5: // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}