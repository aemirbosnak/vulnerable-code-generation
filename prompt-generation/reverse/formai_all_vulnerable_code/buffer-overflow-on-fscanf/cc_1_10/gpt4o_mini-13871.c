//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void initialize_word_count(WordCount *wc, const char *word) {
    strncpy(wc->word, word, MAX_WORD_LENGTH);
    wc->count = 1;
}

int compare(const void *a, const void *b) {
    WordCount *wordCountA = (WordCount *)a;
    WordCount *wordCountB = (WordCount *)b;
    return strcmp(wordCountA->word, wordCountB->word);
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    WordCount words[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        
        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the list
        if (!found && word_count < MAX_WORDS) {
            initialize_word_count(&words[word_count], buffer);
            word_count++;
        }
    }

    fclose(file);
    
    // Sorting words by their lexicographical order
    qsort(words, word_count, sizeof(WordCount), compare);

    printf("%-20s | Count\n", "Word");
    printf("-------------------------\n");
    for (int i = 0; i < word_count; i++) {
        printf("%-20s | %d\n", words[i].word, words[i].count);
    }

    return EXIT_SUCCESS;
}