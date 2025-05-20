//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings
char* string_concat(char* str1, char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, str1); // Copy first string
    strcat(result, str2); // Concatenate second string
    return result;
}

// Function to reverse a string
void string_reverse(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to count words in a string
int word_count(char* str) {
    int count = 0;
    char* token = strtok(str, " \n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \n");
    }
    return count;
}

// Function to display the menu options
void display_menu() {
    printf("\nString Manipulation Program\n");
    printf("1. Concatenate two strings\n");
    printf("2. Reverse a string\n");
    printf("3. Count words in a string\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char str1[100], str2[100];
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
                char* concatenated = string_concat(str1, str2);
                printf("Concatenated String: %s\n", concatenated);
                free(concatenated); // Free the allocated memory
                break;
            case 2:
                printf("Enter the string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                string_reverse(str1);
                printf("Reversed String: %s\n", str1);
                break;
            case 3:
                printf("Enter the string to count words: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character
                char str_copy[100];
                strcpy(str_copy, str1); // Make a copy for strtok to work on
                int count = word_count(str_copy);
                printf("Number of words: %d\n", count);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}