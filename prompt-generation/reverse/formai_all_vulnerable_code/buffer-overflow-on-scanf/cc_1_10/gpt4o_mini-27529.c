//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function prototypes
void to_uppercase(char *str);
void to_lowercase(char *str);
void reverse_string(char *str);
int count_vowels(const char *str);
void print_word_frequency(const char *str);
void remove_whitespace(char *str);
void display_menu();

int main() {
    char str[MAX_SIZE];
    int choice;

    printf("Enter a string (max %d characters): ", MAX_SIZE - 1);
    fgets(str, MAX_SIZE, stdin);
    
    // Remove trailing newline character added by fgets
    str[strcspn(str, "\n")] = 0;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after the choice

        switch (choice) {
            case 1:
                to_uppercase(str);
                printf("Uppercase: %s\n", str);
                break;
            case 2:
                to_lowercase(str);
                printf("Lowercase: %s\n", str);
                break;
            case 3:
                reverse_string(str);
                printf("Reversed: %s\n", str);
                break;
            case 4:
                printf("Number of vowels: %d\n", count_vowels(str));
                break;
            case 5:
                print_word_frequency(str);
                break;
            case 6:
                remove_whitespace(str);
                printf("Whitespace removed: %s\n", str);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int count_vowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char lower_char = tolower((unsigned char)str[i]);
        if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
            count++;
        }
    }
    return count;
}

void print_word_frequency(const char *str) {
    char temp[MAX_SIZE];
    strcpy(temp, str);
    char *token = strtok(temp, " ");
    int frequency[MAX_SIZE] = {0};
    char *words[MAX_SIZE];
    int index = 0;

    while (token != NULL) {
        words[index++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[i]++;
                words[j] = ""; // Mark as counted
            }
        }
        if (frequency[i] > 0) {
            frequency[i]++;
            printf("Word: '%s', Frequency: %d\n", words[i], frequency[i]);
        }
    }
}

void remove_whitespace(char *str) {
    char *dest = str; // Pointer to where we want to copy characters
    while (*str != '\0') {
        if (!isspace((unsigned char)*str)) {
            *dest++ = *str; // Copy only non-whitespace characters
        }
        str++;
    }
    *dest = '\0'; // Null-terminate the new string
}

void display_menu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Convert to Lowercase\n");
    printf("3. Reverse String\n");
    printf("4. Count Vowels\n");
    printf("5. Print Word Frequency\n");
    printf("6. Remove Whitespace\n");
    printf("0. Exit\n");
}