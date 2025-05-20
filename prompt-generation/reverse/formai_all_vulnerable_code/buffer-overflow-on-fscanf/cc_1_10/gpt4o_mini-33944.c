//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 255

// Function prototype declarations
void countWordsInFile(const char *filename);
bool isWordCharacter(char ch);
void trimNewline(char *str);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No file provided for word count. Please specify a file.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        printf("Processing file: %s...\n", argv[i]);
        countWordsInFile(argv[i]);
    }

    return EXIT_SUCCESS;
}

void countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s. Check if the file exists and has read permissions.\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(file, "%s", word) == 1) {
        // Remove any newline or trailing punctuation
        trimNewline(word);
        
        bool isWord = true;
        for (int i = 0; word[i] != '\0'; i++) {
            if (!isWordCharacter(word[i])) {
                isWord = false;
                break;
            }
        }

        if (isWord && strlen(word) > 0) {
            wordCount++;
            printf("Found word: %s\n", word);
        }
    }

    fclose(file);
    printf("Total words in file %s: %d\n", filename, wordCount);
}

bool isWordCharacter(char ch) {
    // In a world of paranoia, we might consider the vast variety of characters.
    // We assume words have only alphanumeric characters, excluding any evil punctuation.
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

void trimNewline(char *str) {
    // Cautiously trim any newline characters that can sneak into our word
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}