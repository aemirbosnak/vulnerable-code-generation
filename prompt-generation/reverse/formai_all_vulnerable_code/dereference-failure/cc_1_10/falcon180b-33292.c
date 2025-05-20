//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_SENTENCE_LEN 200
#define MAX_LINE_LEN 1000

char *translate(char *word) {
    char *result = malloc(MAX_WORD_LEN * sizeof(char));
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(result, word);
    int len = strlen(result);
    for (int i = 0; i < len; i++) {
        if (islower(result[i])) {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}

int main() {
    char input[MAX_LINE_LEN];
    char sentence[MAX_SENTENCE_LEN];
    char word[MAX_WORD_LEN];
    char *translated_sentence = malloc(MAX_SENTENCE_LEN * sizeof(char));
    if (translated_sentence == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    int word_count = 0;
    int sentence_count = 0;
    printf("Enter a sentence:\n");
    fgets(input, MAX_LINE_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';
    strcpy(sentence, input);
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        char *translated_word = translate(word);
        strcat(translated_sentence, translated_word);
        strcat(translated_sentence, " ");
        token = strtok(NULL, " ");
        word_count++;
        if (word_count == 5) {
            printf("MEOW!\n");
            sentence_count++;
            word_count = 0;
        }
    }
    printf("Translated sentence: %s\n", translated_sentence);
    return 0;
}