//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings
char* concatenateStrings(char* str1, char* str2) {
    char* result = malloc(strlen(str1) + strlen(str2) + 1); // allocate memory for the result
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(result, str1); // copy str1 to result
    strcat(result, str2); // concatenate str2 to result
    return result;
}

// Function to search for a substring
int searchSubstring(char* str, char* sub) {
    char* pos = strstr(str, sub);
    return pos ? (pos - str) : -1; // return the position or -1 if not found
}

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]); // convert each character to uppercase
    }
}

// Function to display the menu
void displayMenu() {
    printf("String Manipulation Menu:\n");
    printf("1. Concatenate Strings\n");
    printf("2. Search for Substring\n");
    printf("3. Reverse String\n");
    printf("4. Convert String to Uppercase\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    char str1[100];
    char str2[100];
    int choice;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume the newline character after the number input

        switch (choice) {
            case 1: // Concatenate
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0; // Remove the newline character

                char* concatenated = concatenateStrings(str1, str2);
                printf("Result of concatenation: %s\n", concatenated);
                free(concatenated); // Remember to free allocated memory
                break;
            case 2: // Search substring
                printf("Enter substring to search: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0; // Remove the newline character

                int pos = searchSubstring(str1, str2);
                if (pos != -1) {
                    printf("Substring found at position: %d\n", pos);
                } else {
                    printf("Substring not found.\n");
                }
                break;
            case 3: // Reverse string
                strcpy(str2, str1); // Copy str1 to str2 for reversal
                reverseString(str2);
                printf("Reversed string: %s\n", str2);
                break;
            case 4: // Convert to uppercase
                strcpy(str2, str1); // Copy str1 to str2 for conversion
                toUpperCase(str2);
                printf("Uppercase string: %s\n", str2);
                break;
            case 5: // Exit
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}