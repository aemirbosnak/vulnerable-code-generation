//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void convertToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int wordExists(WordCount *words, int totalWords, const char *word) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i; // return the index of the word
        }
    }
    return -1; // word not found
}

void summarizeText(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    
    WordCount words[MAX_WORDS];
    int totalWords = 0;
    char word[MAX_WORD_LEN];

    while (fscanf(file, "%s", word) != EOF) {
        convertToLower(word);
        int index = wordExists(words, totalWords, word);
        if (index != -1) {
            words[index].count++;
        } else {
            if (totalWords < MAX_WORDS) {
                strcpy(words[totalWords].word, word);
                words[totalWords].count = 1;
                totalWords++;
            } else {
                printf("Maximum word limit reached!\n");
                break; // Stop if we have reached the max word limit
            }
        }
    }

    fclose(file);

    // Sort words based on frequency
    for (int i = 0; i < totalWords - 1; i++) {
        for (int j = i + 1; j < totalWords; j++) {
            if (words[i].count < words[j].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the summarized output
    printf("Word Frequency Summary:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    summarizeText(argv[1]);
    return EXIT_SUCCESS;
}