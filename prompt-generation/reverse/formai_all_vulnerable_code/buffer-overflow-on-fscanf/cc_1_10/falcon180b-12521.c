//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_words(Word words[], int *num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i].word, word);
        words[i].is_correct = true;
        i++;

        if (i >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
    }

    *num_words = i;
    fclose(file);
}

void check_spelling(char *text, Word words[], int num_words) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    bool found_match = false;

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word_length = 0;
            while (isalpha(text[i])) {
                word[word_length++] = tolower(text[i++]);
            }
            word[word_length] = '\0';

            for (int j = 0; j < num_words; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    found_match = true;
                    break;
                }
            }

            if (!found_match) {
                printf("Possible spelling error: %s\n", word);
            }

            found_match = false;
        }
    }
}

int main() {
    Word words[MAX_WORDS];
    int num_words;

    load_words(words, &num_words);
    char text[1000];

    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    check_spelling(text, words, num_words);

    return 0;
}