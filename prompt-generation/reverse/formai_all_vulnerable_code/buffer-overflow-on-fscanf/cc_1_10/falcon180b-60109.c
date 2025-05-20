//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} Word;

void load_words(Word words[]) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s", words[count].word)!= EOF) {
        count++;
    }

    fclose(fp);
}

int is_spam(const char *message, Word words[]) {
    int spam_words_found = 0;

    char *tokens[MAX_WORDS];
    int num_tokens = 0;

    char *token = strtok(message, " ");
    while (token!= NULL && num_tokens < MAX_WORDS) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            if (tokens[i][j] == '\0') {
                break;
            }

            Word *word = &words[i];

            if (strcasecmp(tokens[i], word->word) == 0) {
                spam_words_found++;
                break;
            }
        }
    }

    if (spam_words_found >= 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Word words[MAX_WORDS];
    load_words(words);

    char message[MAX_WORD_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_WORD_LENGTH, stdin);

    if (is_spam(message, words)) {
        printf("Spam detected\n");
    } else {
        printf("No spam detected\n");
    }

    return 0;
}