//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100 // Maximum length for user input strings

// A function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// A function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// A function to count the number of vowels in a string
int countVowels(const char *str) {
    int count = 0;
    char vowels[] = "AEIOUaeiou";
    for (int i = 0; str[i]; i++) {
        if (strchr(vowels, str[i])) {
            count++;
        }
    }
    return count;
}

// A function to concatenate two strings with a space
char* concatStrings(const char *str1, const char *str2) {
    char *result = malloc(strlen(str1) + strlen(str2) + 2); // +2 for space and null terminator
    if (result) {
        strcpy(result, str1);
        strcat(result, " ");
        strcat(result, str2);
    }
    return result;
}

// A function to remove spaces from a string
void removeSpaces(char *str) {
    char *dst = str; // Destination pointer
    while (*str != '\0') {
        if (*str != ' ') {
            *dst++ = *str; // Copy non-space character
        }
        str++;
    }
    *dst = '\0'; // Null-terminate the destination string
}

// A function to display a menu and get user choice
int displayMenu() {
    int choice;
    printf("\n=== String Manipulation Menu ===\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Reverse String\n");
    printf("3. Count Vowels\n");
    printf("4. Concatenate Strings\n");
    printf("5. Remove Spaces\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    getchar(); // To consume the newline character after entering the choice
    return choice;
}

// Main program function
int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int choice;

    printf("Welcome to the String Manipulation Program!\n");
    printf("Please enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                toUpperCase(str1);
                printf("Uppercase: %s\n", str1);
                break;
            case 2:
                reverseString(str1);
                printf("Reversed: %s\n", str1);
                break;
            case 3:
                printf("Number of vowels: %d\n", countVowels(str1));
                break;
            case 4:
                printf("Please enter a second string (max %d characters): ", MAX_LENGTH - 1);
                fgets(str2, MAX_LENGTH, stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
                char *concatenated = concatStrings(str1, str2);
                if (concatenated) {
                    printf("Concatenated: %s\n", concatenated);
                    free(concatenated); // Free the allocated memory
                }
                break;
            case 5:
                removeSpaces(str1);
                printf("String without spaces: %s\n", str1);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 6);

    return 0;
}