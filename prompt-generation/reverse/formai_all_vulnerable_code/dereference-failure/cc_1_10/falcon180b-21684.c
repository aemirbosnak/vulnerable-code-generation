//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_NUM_TOKENS 100
#define MAX_NUM_RULES 100

typedef struct {
    char *pattern;
    char *translation;
} Rule;

typedef struct {
    char *word;
    int length;
} Token;

Token tokens[MAX_NUM_TOKENS];
int num_tokens;

Rule rules[MAX_NUM_RULES];
int num_rules;

void add_token(char *word) {
    if (num_tokens >= MAX_NUM_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    strcpy(tokens[num_tokens].word, word);
    tokens[num_tokens].length = strlen(word);
    num_tokens++;
}

void add_rule(char *pattern, char *translation) {
    if (num_rules >= MAX_NUM_RULES) {
        printf("Error: Too many rules.\n");
        exit(1);
    }
    strcpy(rules[num_rules].pattern, pattern);
    strcpy(rules[num_rules].translation, translation);
    num_rules++;
}

int match_rule(char *word) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcasecmp(word, rules[i].pattern) == 0) {
            return i;
        }
    }
    return -1;
}

void translate_sentence(char *sentence) {
    char *word;
    char *translation;
    int i;
    char buffer[MAX_TOKEN_LENGTH];

    for (word = strtok(sentence, " "); word!= NULL; word = strtok(NULL, " ")) {
        i = match_rule(word);
        if (i >= 0) {
            strcpy(buffer, rules[i].translation);
        } else {
            strcpy(buffer, word);
        }
        printf("%s ", buffer);
    }
    printf("\n");
}

int main() {
    add_token("cat");
    add_token("dog");
    add_token("bird");
    add_token("mouse");

    add_rule("cat", "gato");
    add_rule("dog", "perro");
    add_rule("bird", "pájaro");
    add_rule("mouse", "ratón");

    translate_sentence("The cat sat on the mat.");
    translate_sentence("The dog chased the cat.");
    translate_sentence("The bird flew away.");
    translate_sentence("The mouse ran into its hole.");

    return 0;
}