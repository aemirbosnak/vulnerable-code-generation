//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, char *text) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        text[i++] = tolower(ch);
    }

    text[i] = '\0';
}

void tokenize(char *text, char **tokens, int max_tokens) {
    int i = 0;
    char *token;

    token = strtok(text, ",.!?;:\"'");

    while (token!= NULL && i < max_tokens) {
        tokens[i++] = token;
        token = strtok(NULL, ",.!?;:\"'");
    }
}

void count_words(char **tokens, int num_tokens, WordFrequency *word_freq, int max_words) {
    int i;

    for (i = 0; i < num_tokens && i < max_words; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                break;
            }
        }

        if (j == i) {
            int k;
            for (k = 0; k < strlen(tokens[i]); k++) {
                if (!isalpha(tokens[i][k])) {
                    tokens[i][k] = '\0';
                    break;
                }
            }

            int word_index = 0;
            while (word_freq[word_index].count > 0 &&
                    strcmp(word_freq[word_index].word, tokens[i])!= 0) {
                word_index++;
            }

            if (word_freq[word_index].count == 0) {
                strcpy(word_freq[word_index].word, tokens[i]);
            }

            word_freq[word_index].count++;
        }
    }
}

void print_word_frequencies(WordFrequency *word_freq, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (word_freq[i].count > 0) {
            printf("%s: %d\n", word_freq[i].word, word_freq[i].count);
        }
    }
}

int main() {
    FILE *file;
    char text[MAX_WORD_LENGTH * MAX_WORDS];
    char *filename = "input.txt";
    WordFrequency word_freq[MAX_WORDS];
    int num_words = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    read_file(file, text);
    fclose(file);

    tokenize(text, (char **)&text, MAX_WORD_LENGTH * MAX_WORDS);

    count_words((char **)&text, MAX_WORD_LENGTH * MAX_WORDS, word_freq, MAX_WORDS);
    num_words = MAX_WORDS;

    printf("Word frequencies:\n");
    print_word_frequencies(word_freq, num_words);

    return 0;
}