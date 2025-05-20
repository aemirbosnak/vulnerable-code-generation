//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int add_word(WordCount *words, int count, const char *new_word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].frequency++;
            return count; // return current count if word already exists
        }
    }

    // add a new word
    strcpy(words[count].word, new_word);
    words[count].frequency = 1;
    return count + 1; // increase the count of unique words
}

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    return wordB->frequency - wordA->frequency; // descending order
}

void summarize_text(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    WordCount words[MAX_WORDS];
    int count = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        count = add_word(words, count, buffer);
    }

    fclose(file);

    // Sort words by frequency
    qsort(words, count, sizeof(WordCount), compare);

    // Print top 10 words (or less if there are fewer words)
    printf("Top words in the text:\n");
    for (int i = 0; i < count && i < 10; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    summarize_text(argv[1]);
    
    return EXIT_SUCCESS;
}