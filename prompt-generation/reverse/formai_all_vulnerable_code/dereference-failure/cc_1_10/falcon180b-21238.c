//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50
#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 500

typedef struct {
    char *text;
    int len;
} Sentence;

typedef struct {
    char *text;
    int len;
    int count;
} Token;

void tokenize(Sentence *sentence, Token *tokens) {
    char *text = sentence->text;
    int len = sentence->len;
    int count = 0;

    while (count < MAX_TOKENS && len > 0) {
        if (isalnum(text[0])) {
            int i = 0;
            while (isalnum(text[i]) && i < MAX_TOKEN_LEN) {
                i++;
            }
            tokens[count].text = malloc(i + 1);
            strncpy(tokens[count].text, text, i);
            tokens[count].text[i] = '\0';
            tokens[count].len = i;
            count++;
            len -= i;
            text += i;
        } else {
            text++;
            len--;
        }
    }

    if (count == MAX_TOKENS) {
        printf("Warning: sentence contains more than %d tokens\n", MAX_TOKENS);
    }
}

void analyze_sentiment(Token *tokens, int count) {
    int positive_count = 0;
    int negative_count = 0;

    for (int i = 0; i < count; i++) {
        Token *token = &tokens[i];
        char *text = token->text;
        int len = token->len;

        if (len > 0 && text[0] == '-') {
            negative_count++;
        } else if (len > 0 && text[0] == '+') {
            positive_count++;
        }
    }

    printf("Sentiment analysis: %d positive, %d negative\n", positive_count, negative_count);
}

int main() {
    Sentence sentence;
    Token tokens[MAX_TOKENS];

    printf("Enter a sentence: ");
    fgets(sentence.text, MAX_SENTENCE_LEN, stdin);
    sentence.len = strlen(sentence.text);

    tokenize(&sentence, tokens);
    analyze_sentiment(tokens, sentence.len);

    return 0;
}