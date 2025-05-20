//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function to convert a string into lowercase and clean it up
void clean_word(char *word) {
    char *p = word;

    // Remove punctuation and convert to lowercase
    while (*p) {
        if (ispunct((unsigned char)*p) || isspace((unsigned char)*p)) {
            *p = '\0';
            break;
        }
        *p = tolower((unsigned char)*p);
        p++;
    }
}

// Function to find a word in the list
int find_word(WordFrequency *words, int word_count, const char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordFrequency words[MAX_WORDS] = {0};
    int word_count = 0;
    char buffer[MAX_WORD_LENGTH];

    // Read words from the file
    while (fscanf(file, "%s", buffer) != EOF) {
        clean_word(buffer);

        if (buffer[0] != '\0') { // Ignore empty words
            int index = find_word(words, word_count, buffer);
            if (index != -1) {
                words[index].count++;
            } else {
                // Add a new word
                if (word_count < MAX_WORDS) {
                    strcpy(words[word_count].word, buffer);
                    words[word_count].count = 1;
                    word_count++;
                } else {
                    fprintf(stderr, "Word limit reached! Cannot count more words.\n");
                    break;
                }
            }
        }
    }

    fclose(file);

    // Display the words and their counts
    printf("Word Frequency Count:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Now let's ensure data integrity, paranoid check for overflows and unexpected behaviors
    for (int i = 0; i < word_count; i++) {
        if (words[i].count < 0) {
            fprintf(stderr, "Error: Negative count found for word: %s\n", words[i].word);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}