//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024
#define MAX_TOKEN_LEN 64

typedef struct token {
    char *word;
    int freq;
} Token;

typedef struct doc {
    Token *tokens;
    int num_tokens;
} Doc;

Doc *new_doc() {
    Doc *d = malloc(sizeof(Doc));
    d->tokens = NULL;
    d->num_tokens = 0;
    return d;
}

void free_doc(Doc *d) {
    for (int i = 0; i < d->num_tokens; i++) {
        free(d->tokens[i].word);
    }
    free(d->tokens);
    free(d);
}

void add_token(Doc *d, char *word) {
    Token *t = malloc(sizeof(Token));
    t->word = strdup(word);
    t->freq = 1;
    d->tokens = realloc(d->tokens, (d->num_tokens + 1) * sizeof(Token));
    d->tokens[d->num_tokens++] = *t;
}

int count_tokens(Doc *d, char *word) {
    for (int i = 0; i < d->num_tokens; i++) {
        if (strcmp(d->tokens[i].word, word) == 0) {
            return d->tokens[i].freq;
        }
    }
    return 0;
}

int main() {
    Doc *doc = new_doc();
    char *word;
    int token_count = 0;

    while (fgets(word, MAX_TOKEN_LEN, stdin)!= NULL) {
        char *tok = strtok(word, " \n\t");
        while (tok!= NULL) {
            add_token(doc, tok);
            token_count++;
            tok = strtok(NULL, " \n\t");
        }
    }

    int total_tokens = 0;
    for (int i = 0; i < doc->num_tokens; i++) {
        total_tokens += doc->tokens[i].freq;
    }

    for (int i = 0; i < doc->num_tokens; i++) {
        int freq = count_tokens(doc, doc->tokens[i].word);
        printf("%s %d\n", doc->tokens[i].word, freq);
    }

    free_doc(doc);

    return 0;
}