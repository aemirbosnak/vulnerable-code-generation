//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 100

typedef struct {
    char word[20];
    int freq;
} Word;

void tokenize(char *text, Word words[]) {
    int current_word = 0;
    bool in_word = false;
    int length = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        char c = tolower(text[i]);
        if (isalpha(c)) {
            if (!in_word) {
                strncpy(words[current_word].word, &text[i], 19);
                words[current_word++].freq = 0;
                in_word = true;
            } else {
                words[current_word - 1].freq++;
                if (length + 2 > 19) {
                    words[current_word++].freq = 0;
                    strncpy(words[current_word].word, &text[i], 19);
                    in_word = true;
                } else {
                    length++;
                }
            }
        } else if (in_word) {
            words[current_word - 1].freq += 2;
            in_word = false;
        }
    }
}

int main() {
    Word words[MAX_WORDS];
    char article_text[1000];

    printf("Enter the article text:\n");
    fgets(article_text, sizeof(article_text), stdin);
    article_text[strlen(article_text) - 1] = '\0';

    tokenize(article_text, words);

    int summary_length = 0;
    int start_index = 0;

    for (int i = 0; i < MAX_WORDS && summary_length < MAX_LENGTH; ++i) {
        if (words[i].freq > 0 && summary_length + strlen(words[i].word) + 1 < MAX_LENGTH) {
            summary_length += strlen(words[i].word) + 1;
            if (i > 0 && summary_length > MAX_LENGTH - (strlen(words[i].word) + 1)) {
                start_index = i - 1;
                break;
            }
            printf("%s ", words[i].word);
        }
    }

    printf("\b\b...\nSummary: %s\n", &article_text[start_index]);

    return 0;
}