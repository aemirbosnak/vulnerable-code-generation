//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define maximum string length
#define MAX_LENGTH 50

// Define menu options
const char menu_options[][20] = {
    "1. Reverse string",
    "2. Remove vowels",
    "3. Count vowels",
    "4. Replace character"
};
const int num_options = sizeof(menu_options) / sizeof(menu_options[0]);

// Function prototypes
void reverse_string(char*);
void remove_vowels(char*);
int count_vowels(char*);
void replace_char(char*, char, char);

int main() {
    // Initialize input buffer and menu choice variable
    char input_buffer[MAX_LENGTH];
    int choice;

    // Get input string from user
    printf("Enter a string (max length %d): ", MAX_LENGTH);
    fgets(input_buffer, MAX_LENGTH, stdin);

    // Remove newline character from input string
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    // Display menu and get user choice
    printf("Menu:\n");
    for (int i = 0; i < num_options; i++) {
        printf("%s\n", menu_options[i]);
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform selected manipulation on input string and output result
    switch (choice) {
        case 1:
            reverse_string(input_buffer);
            break;
        case 2:
            remove_vowels(input_buffer);
            break;
        case 3:
            printf("Number of vowels: %d\n", count_vowels(input_buffer));
            break;
        case 4:
            printf("Enter character to replace: ");
            char old_char = getchar();
            printf("Enter new character: ");
            char new_char = getchar();
            replace_char(input_buffer, old_char, new_char);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Result: %s\n", input_buffer);

    return 0;
}

// Reverse a string in place
void reverse_string(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Remove all vowels from a string
void remove_vowels(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

// Count the number of vowels in a string
int count_vowels(char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }
    return count;
}

// Replace all occurrences of a character in a string with another character
void replace_char(char* str, char old_char, char new_char) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }
}