//FormAI DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

int main(int argc, char* argv[]) {
    // Check if file path is provided
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Open file and check if it exists
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: file %s does not exist\n", argv[1]);
        return 1;
    }

    // Initialize variables
    char curr_word[MAX_WORD_LENGTH];
    int word_count = 0;
    int char_count = 0;
    char ch;

    // Loop through file, character by character
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            // If current character is a whitespace character, then count current word
            if (char_count > 0) {
                curr_word[char_count] = '\0'; // Terminate string
                word_count++;
                printf("Word %d: %s\n", word_count, curr_word);
                char_count = 0; // Reset character count
            }
        } else {
            // If current character is not a whitespace character, add it to current word
            curr_word[char_count] = ch;
            char_count++;
        }
    }

    // Count last word if file does not end with a whitespace character
    if (char_count > 0) {
        curr_word[char_count] = '\0'; // Terminate string
        word_count++;
        printf("Word %d: %s\n", word_count, curr_word);
        char_count = 0; // Reset character count
    }

    // Print word count
    printf("\nTotal words in file: %d\n", word_count);

    // Close file
    fclose(fp);

    return 0;
}