//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function declarations
void initialize_string(char *str);
void reverse_string(char *str);
void to_uppercase(char *str);
void find_and_replace(char *str, const char *old_word, const char *new_word);
void append_strings(char *dest, const char *src);
void display_menu();
void clear_buffer();

int main() {
    char buffer[MAX_SIZE];
    char temp_string[MAX_SIZE];
    char old_word[MAX_SIZE], new_word[MAX_SIZE];
    int choice;

    // Initialize the buffer for further use
    initialize_string(buffer);

    printf("Welcome to the Complex C String Manipulation Program!\n");
    printf("You can perform various operations on strings.\n");

    do {
        display_menu();
        printf("Enter your choice (1-6, or 0 to exit): ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(buffer, MAX_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Strip newline character
                printf("Your string: %s\n", buffer);
                break;
            case 2:
                reverse_string(buffer);
                printf("Reversed string: %s\n", buffer);
                break;
            case 3:
                to_uppercase(buffer);
                printf("Uppercase string: %s\n", buffer);
                break;
            case 4:
                printf("Enter the word to find: ");
                fgets(old_word, MAX_SIZE, stdin);
                old_word[strcspn(old_word, "\n")] = 0; // Strip newline character
                printf("Enter the new word to replace with: ");
                fgets(new_word, MAX_SIZE, stdin);
                new_word[strcspn(new_word, "\n")] = 0; // Strip newline character
                find_and_replace(buffer, old_word, new_word);
                printf("Modified string: %s\n", buffer);
                break;
            case 5:
                printf("Enter another string to append: ");
                fgets(temp_string, MAX_SIZE, stdin);
                temp_string[strcspn(temp_string, "\n")] = 0; // Strip newline character
                append_strings(buffer, temp_string);
                printf("Appended string: %s\n", buffer);
                break;
            case 6:
                printf("Length of the current string: %lu\n", strlen(buffer));
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void initialize_string(char *str) {
    memset(str, 0, MAX_SIZE); // Clear the buffer
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - ('a' - 'A') : str[i];
    }
}

void find_and_replace(char *str, const char *old_word, const char *new_word) {
    char buffer[MAX_SIZE];
    char *pos;
    int old_word_len = strlen(old_word);
    int new_word_len = strlen(new_word);
    int index = 0;

    while ((pos = strstr(str, old_word)) != NULL) {
        // Copy part before the old word
        strncpy(buffer + index, str, pos - str);
        index += pos - str;

        // Copy new word
        strcpy(buffer + index, new_word);
        index += new_word_len;

        // Move past the old word
        str = pos + old_word_len;
    }

    // Copy remaining part of the original string
    strcpy(buffer + index, str);
    strcpy(str, buffer);
}

void append_strings(char *dest, const char *src) {
    strncat(dest, src, MAX_SIZE - strlen(dest) - 1);
}

void display_menu() {
    printf("\n--- String Manipulation Menu ---\n");
    printf("1. Input a string\n");
    printf("2. Reverse the string\n");
    printf("3. Convert to uppercase\n");
    printf("4. Find and replace a word\n");
    printf("5. Append a string\n");
    printf("6. Get string length\n");
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}