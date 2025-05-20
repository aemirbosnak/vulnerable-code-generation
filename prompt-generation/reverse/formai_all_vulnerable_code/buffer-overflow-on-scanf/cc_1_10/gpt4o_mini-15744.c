//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100

// Function to check if a character is a word character (alphanumeric)
int is_word_char(char c) {
    return isalnum(c) || c == '_';
}

// Function to count words in a given line
int count_words(const char *line) {
    int count = 0;
    int in_word = 0;
    
    for (int i = 0; line[i] != '\0'; i++) {
        if (is_word_char(line[i])) {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }
    }
    return count;
}

// Function to read the file and count words
void count_words_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int total_word_count = 0;

    while (fgets(line, sizeof(line), file)) {
        total_word_count += count_words(line);
    }

    fclose(file);
    printf("Total word count in file '%s': %d\n", filename, total_word_count);
}

// Function to interactively count words from user input
void count_words_interactively() {
    char input[MAX_LINE_LENGTH];
    int total_word_count = 0;
    
    printf("Enter text (press Ctrl+D to finish):\n");
    while (fgets(input, sizeof(input), stdin)) {
        total_word_count += count_words(input);
    }
    
    printf("Total word count: %d\n", total_word_count);
}

// Function to display menu
void display_menu() {
    printf("\nWord Count Tool\n");
    printf("1. Count words from a file\n");
    printf("2. Count words interactively\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice;
    char filename[255];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // To consume the newline after the choice input

        switch (choice) {
            case 1:
                printf("Enter the filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                count_words_in_file(filename);
                break;
            case 2:
                count_words_interactively();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}