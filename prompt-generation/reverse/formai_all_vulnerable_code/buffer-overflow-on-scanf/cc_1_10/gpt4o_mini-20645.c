//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define BUFFER_SIZE 256

// Function to safely concatenate two strings
void safe_string_concat(char *dest, const char *src, size_t dest_size) {
    strncat(dest, src, dest_size - strlen(dest) - 1);
}

// Function to safely copy string
void safe_string_copy(char *dest, const char *src, size_t dest_size) {
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0'; // Null-terminate to avoid overflow
}

// Function to extract a substring
void extract_substring(const char *src, char *sub, int start, int length) {
    int i;
    for (i = 0; i < length && i + start < strlen(src); i++) {
        sub[i] = src[i + start];
    }
    sub[i] = '\0'; // Null-terminate the substring
}

// Display the menu
void display_menu() {
    printf("String Manipulation Menu:\n");
    printf("1. Concatenate Strings\n");
    printf("2. Copy String\n");
    printf("3. Extract Substring\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Main program function
int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];
    char result[MAX_STRING_LENGTH] = "";
    char substring[MAX_STRING_LENGTH];
    int choice, start, length;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter first string: ");
                getchar(); // To consume newline character
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline character

                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0; // Remove newline character

                safe_string_copy(result, str1, sizeof(result));
                safe_string_concat(result, str2, sizeof(result));
                
                printf("Result of concatenation: %s\n", result);
                break;

            case 2:
                printf("Enter source string: ");
                getchar();
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline character

                safe_string_copy(result, str1, sizeof(result));
                printf("Copied string: %s\n", result);
                break;

            case 3:
                printf("Enter the main string: ");
                getchar();
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline character

                printf("Enter start index for substring: ");
                scanf("%d", &start);
                
                printf("Enter length of substring: ");
                scanf("%d", &length);

                if (start < 0 || length < 0 || start + length > strlen(str1)) {
                    printf("Invalid start index or length.\n");
                } else {
                    extract_substring(str1, substring, start, length);
                    printf("Extracted substring: %s\n", substring);
                }
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}