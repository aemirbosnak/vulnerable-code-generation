//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compare(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void add_word(WordFrequency *wordArray, int *size, char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(wordArray[i].word, word) == 0) {
            wordArray[i].count++;
            return;
        }
    }

    strcpy(wordArray[*size].word, word);
    wordArray[*size].count = 1;
    (*size)++;
}

void print_word_frequencies(WordFrequency *wordArray, int size) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", wordArray[i].word, wordArray[i].count);
    }
}

void clean_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    FILE *file;
    char filename[256];
    char buffer[MAX_WORD_LENGTH];
    WordFrequency wordArray[MAX_WORDS];
    int wordCount = 0;

    printf("Enter the filename to analyze: ");
    scanf("%s", filename);
    clean_buffer(); // Clean any leftover input

    file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        add_word(wordArray, &wordCount, buffer);
    }

    fclose(file);

    // Sort the word frequencies
    qsort(wordArray, wordCount, sizeof(WordFrequency), compare);

    // Print the results
    print_word_frequencies(wordArray, wordCount);

    return EXIT_SUCCESS;
}