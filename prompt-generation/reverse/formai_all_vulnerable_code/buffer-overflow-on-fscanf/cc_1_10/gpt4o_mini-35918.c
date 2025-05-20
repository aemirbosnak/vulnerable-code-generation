//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;
    return word2->count - word1->count; // Sort in descending order
}

void summarize_text(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    WordFrequency words[MAX_WORDS];
    int total_words = 0;
    char buffer[MAX_WORD_LEN];

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);

        // Remove punctuation from the word
        for (int i = 0; buffer[i]; i++) {
            if (ispunct(buffer[i])) {
                buffer[i] = '\0';
            }
        }

        if (strlen(buffer) > 0) {
            int found = 0;
            for (int i = 0; i < total_words; i++) {
                if (strcmp(words[i].word, buffer) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found && total_words < MAX_WORDS) {
                strcpy(words[total_words].word, buffer);
                words[total_words].count = 1;
                total_words++;
            }
        }
    }

    fclose(file);

    // Sort the words based on frequency
    qsort(words, total_words, sizeof(WordFrequency), compare);

    printf("Top Frequencies:\n");
    for (int i = 0; i < total_words && i < 10; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    printf("\nTotal unique words: %d\n", total_words);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    summarize_text(argv[1]);
    return 0;
}