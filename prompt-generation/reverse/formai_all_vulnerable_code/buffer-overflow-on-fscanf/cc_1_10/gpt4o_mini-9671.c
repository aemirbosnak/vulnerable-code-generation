//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;
    return word2->frequency - word1->frequency; // Sort in descending order
}

void print_summary(WordFrequency *words, int total_words, int summary_length) {
    for (int i = 0; i < summary_length && i < total_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    WordFrequency words[MAX_WORDS] = {0};
    int total_words = 0;

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);

        // Check if the word already exists in the frequency array
        int found = 0;
        for (int i = 0; i < total_words; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it
        if (!found && total_words < MAX_WORDS) {
            strcpy(words[total_words].word, buffer);
            words[total_words].frequency = 1;
            total_words++;
        }
    }

    fclose(file);

    // Sort the words by their frequency
    qsort(words, total_words, sizeof(WordFrequency), compare);

    // Print the summary of the most common words
    printf("Summary of the most common words:\n");
    print_summary(words, total_words, 10); // Change 10 to get more/less summary words

    return 0;
}