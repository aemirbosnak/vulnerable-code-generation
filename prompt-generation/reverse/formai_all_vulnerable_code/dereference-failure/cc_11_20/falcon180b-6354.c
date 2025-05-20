//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100
#define THRESHOLD 0.5

typedef struct {
    char *word;
    int is_spam;
} Token;

int main() {
    FILE *f;
    char line[1024];
    char *tokens[MAX_TOKENS];
    int num_tokens = 0;
    Token *spam_words = NULL;
    int num_spam_words = 0;
    int is_spam = 0;

    // Load spam words into memory
    f = fopen("spam_words.txt", "r");
    if (f == NULL) {
        printf("Error: could not open spam_words.txt\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), f)!= NULL) {
        char *word = strtok(line, "\n");
        while (word!= NULL) {
            num_spam_words++;
            spam_words = realloc(spam_words, sizeof(Token) * num_spam_words);
            spam_words[num_spam_words - 1].word = strdup(word);
            spam_words[num_spam_words - 1].is_spam = 1;
            word = strtok(NULL, "\n");
        }
    }
    fclose(f);

    // Read input email
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Error: could not open input.txt\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), f)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            num_tokens++;
            tokens[num_tokens - 1] = strdup(word);
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(f);

    // Check for spam words
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_spam_words; j++) {
            if (strcasecmp(tokens[i], spam_words[j].word) == 0) {
                is_spam = 1;
                break;
            }
        }
        if (is_spam) break;
    }

    // Print result
    if (is_spam) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}