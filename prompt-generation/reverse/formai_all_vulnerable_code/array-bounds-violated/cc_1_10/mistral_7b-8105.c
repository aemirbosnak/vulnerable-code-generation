//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50
#define TEXT_LEN 10000

typedef struct Word {
    char *word;
    int freq;
} Word;

Word words[MAX_WORDS];
char text[TEXT_LEN];
int num_words = 0;

void preprocess(char *input_text) {
    char *token = strtok(input_text, " .,!?");
    strcpy(text, "");

    while (token != NULL) {
        int len = strlen(token);
        if (len > 0 && len < WORD_LEN) {
            for (int i = 0; i < num_words; i++) {
                if (strcasecmp(words[i].word, token) == 0) {
                    words[i].freq++;
                    goto next_token;
                }
            }

            Word new_word = {(char *) malloc(len + 1), 1};
            strcpy(new_word.word, token);
            words[num_words++] = new_word;
        }

        strcat(text, token);
        strcat(text, " ");

next_token:
        token = strtok(NULL, " .,!?");
    }
}

int main() {
    char input_text[TEXT_LEN];
    printf("Enter text to summarize, in medieval style:\n");
    fgets(input_text, TEXT_LEN, stdin);
    input_text[strlen(input_text) - 1] = '\0';

    preprocess(input_text);

    printf("Text: %s\n", text);
    printf("Summary:\n");

    for (int i = 0; i < num_words && num_words > 10; i++) {
        printf("%s (%d)\n", words[i].word, words[i].freq);
    }

    for (int i = num_words - 1; i >= 0 && num_words > 10; i--) {
        free(words[i].word);
    }
    num_words -= (num_words - 10);

    return 0;
}