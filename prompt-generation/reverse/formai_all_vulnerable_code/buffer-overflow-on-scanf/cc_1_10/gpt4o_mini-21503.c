//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function prototypes
void concatenateStrings(char *str1, const char *str2);
int compareStrings(const char *str1, const char *str2);
void findSubstring(const char *str, const char *sub);
void displayMenu();
void clearInputBuffer();

// Main function
int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    int choice;

    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer(); // clear input buffer to avoid reading leftover characters

        switch (choice) {
            case 1:
                concatenateStrings(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 2:
                if (compareStrings(str1, str2) == 0) {
                    printf("The strings are equal.\n");
                } else {
                    printf("The strings are not equal.\n");
                }
                break;
            case 3:
                findSubstring(str1, str2);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to concatenate two strings
void concatenateStrings(char *str1, const char *str2) {
    strncat(str1, str2, MAX_LENGTH - strlen(str1) - 1);
}

// Function to compare two strings
int compareStrings(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

// Function to find a substring within a string
void findSubstring(const char *str, const char *sub) {
    char *pos = strstr(str, sub);
    if (pos) {
        printf("Substring '%s' found at position: %ld\n", sub, (long)(pos - str));
    } else {
        printf("Substring '%s' not found in '%s'.\n", sub, str);
    }
}

// Function to display a menu
void displayMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Concatenate Strings\n");
    printf("2. Compare Strings\n");
    printf("3. Find Substring\n");
    printf("4. Exit\n");
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}