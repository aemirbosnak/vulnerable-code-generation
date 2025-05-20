//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordInfo;

int main() {
    char *input_text = NULL;
    size_t input_len = 0;
    ssize_t bytes_read;

    printf("Enter some text: ");
    bytes_read = getline(&input_text, &input_len, stdin);

    if (bytes_read == -1) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    // Initialize empty array of words
    WordInfo words[MAX_WORD_COUNT];
    int word_count = 0;

    // Process input text
    char *word_start = input_text;
    for (char *p = input_text; *p != '\0'; ++p) {
        if (*p == '\n' || *p == '\r' || !isalnum(*p)) {
            // End previous word
            *p = '\0';

            // Check word length
            int word_len = p - word_start;
            if (word_len > 0 && word_len < MAX_WORD_LENGTH) {
                // Add word to list (or update count if already present)
                int existing_index = -1;
                for (int i = 0; i < word_count; ++i) {
                    if (strcmp(words[i].word, word_start) == 0) {
                        existing_index = i;
                        break;
                    }
                }
                if (existing_index == -1) {
                    // Add new word
                    if (word_count < MAX_WORD_COUNT) {
                        strcpy(words[word_count].word, word_start);
                        words[word_count].count = 1;
                        ++word_count;
                    } else {
                        printf("Maximum word count reached, stopping processing.\n");
                        break;
                    }
                } else {
                    // Update existing word count
                    ++words[existing_index].count;
                }
            }

            // Start new word
            word_start = p + 1;
        }
    }

    // Print frequency table
    printf("Word frequency:\n");
    for (int i = 0; i < word_count; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(input_text);
    return 0;
}