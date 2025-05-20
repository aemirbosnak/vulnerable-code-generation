//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_TOKENS 10000
#define MAX_TOKEN_LENGTH 100
#define MIN_WORD_LENGTH 3

typedef struct {
    char *word;
    int frequency;
} token_t;

token_t tokens[MAX_TOKENS];

int num_tokens = 0;

int compare_tokens(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void load_tokens() {
    FILE *fp = fopen("tokens.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open tokens file.\n");
        exit(1);
    }

    char line[MAX_TOKEN_LENGTH];
    while (fgets(line, MAX_TOKEN_LENGTH, fp)!= NULL) {
        char *word = strtok(line, " ");
        if (word == NULL) {
            continue;
        }

        int i;
        for (i = 0; i < num_tokens && strcmp(tokens[i].word, word)!= 0; i++) {
            // do nothing
        }

        if (i == num_tokens) {
            tokens[num_tokens].word = strdup(word);
            tokens[num_tokens].frequency = 1;
            num_tokens++;
        } else {
            tokens[i].frequency++;
        }
    }

    fclose(fp);

    qsort(tokens, num_tokens, sizeof(token_t), compare_tokens);
}

int is_spam(const char *text) {
    int num_words = 0;
    int spam_score = 0;

    char *word = strtok(text, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_tokens && strcmp(tokens[i].word, word)!= 0; i++) {
            // do nothing
        }

        if (i == num_tokens) {
            continue;
        }

        spam_score += tokens[i].frequency;
        num_words++;

        word = strtok(NULL, " ");
    }

    if (num_words == 0) {
        return 0;
    }

    return (spam_score * 100) / num_words;
}

int main() {
    load_tokens();

    char text[MAX_TOKEN_LENGTH];
    while (fgets(text, MAX_TOKEN_LENGTH, stdin)!= NULL) {
        int score = is_spam(text);
        if (score >= 50) {
            printf("Spam detected: %d%%\n", score);
        } else {
            printf("Not spam\n");
        }
    }

    return 0;
}