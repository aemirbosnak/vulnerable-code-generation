//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        // Remove the newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Convert the word to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Add the word to the dictionary
        strcpy(dictionary[num_words].word, line);
        dictionary[num_words].count = 0;
        num_words++;
    }

    fclose(fp);
}

int compare_words(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;

    return strcmp(word1->word, word2->word);
}

void check_spelling(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        // Remove the punctuation from the end of the word
        int len = strlen(word);
        while (len > 0 && !isalpha(word[len - 1])) {
            len--;
        }
        word[len] = '\0';

        // Convert the word to lowercase
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }

        // Search for the word in the dictionary
        Word key;
        strcpy(key.word, word);
        Word *result = bsearch(&key, dictionary, num_words, sizeof(Word), compare_words);

        if (result == NULL) {
            printf("%s\n", word);
        } else {
            result->count++;
        }
    }

    fclose(fp);
}

void print_results() {
    for (int i = 0; i < num_words; i++) {
        if (dictionary[i].count > 0) {
            printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s dictionary.txt input.txt\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);
    check_spelling(argv[2]);
    print_results();

    return 0;
}