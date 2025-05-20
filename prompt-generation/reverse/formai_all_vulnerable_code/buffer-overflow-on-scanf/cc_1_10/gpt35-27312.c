//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

void normalize_word(char* word) {
    int i;
    for (i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

void add_word(Word* words, int* num_words, char* new_word) {
    normalize_word(new_word);
    int i;
    for (i = 0; i < *num_words; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            // The word already exists in the array - increment its count
            words[i].count++;
            return;
        }
    }
    // The word does not exist in the array - add it
    if (*num_words == MAX_WORDS) {
        fprintf(stderr, "Too many words in the file!\n");
        exit(1);
    }
    strcpy(words[*num_words].word, new_word);
    words[*num_words].count = 1;
    (*num_words)++;
}

int main(void) {
    char filename[FILENAME_MAX];
    printf("Enter a file name to read: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open %s\n", filename);
        exit(1);
    }

    Word words[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH + 1]; // +1 is for the null terminator
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            // Add the character to the current word
            if (strlen(word) < MAX_WORD_LENGTH) {
                word[strlen(word)] = c;
            }
        } else {
            // End of a word - add it to the array
            if (strlen(word) > 0) {
                word[strlen(word)] = '\0'; // Null terminate the string
                add_word(words, &num_words, word);
                word[0] = '\0'; // Reset the word buffer
            }
        }
    }

    // Handle the last word if necessary
    if (strlen(word) > 0) {
        word[strlen(word)] = '\0'; // Null terminate the string
        add_word(words, &num_words, word);
    }

    fclose(file);

    // Sort the words by frequency
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[i].count < words[j].count) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the words and their frequency
    printf("Word frequency in %s:\n", filename);
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}