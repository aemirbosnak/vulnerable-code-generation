//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: complete
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

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

int get_word_count(char *filename, WordCount *words) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return -1;
    }

    char buffer[MAX_WORD_LENGTH];
    int word_count = 0;

    while (fscanf(file, "%s", buffer) == 1) {
        // Convert words to lowercase
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word was not found, add it to the list
        if (!found && word_count < MAX_WORDS) {
            strcpy(words[word_count].word, buffer);
            words[word_count].count = 1;
            word_count++;
        }
    }

    fclose(file);
    return word_count;
}

void print_word_counts(WordCount *words, int word_count) {
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordCount words[MAX_WORDS];
    int word_count = get_word_count(argv[1], words);
    if (word_count == -1) {
        return 1;
    }

    // Sort the words alphabetically
    qsort(words, word_count, sizeof(WordCount), compare);

    // Print the word counts
    print_word_counts(words, word_count);
    return 0;
}