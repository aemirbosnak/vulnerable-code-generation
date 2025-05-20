//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

char *translate_word(char *word);
void translate_sentence(char *sentence);

int main(void) {
    char input_sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence to translate to alien language:\n");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);

    translate_sentence(input_sentence);

    return 0;
}

char *translate_word(char *word) {
    int length = strlen(word);
    char *translated_word = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        if (isalpha(word[i])) {
            if (isupper(word[i])) {
                translated_word[i] = 'Z' - (word[i] - 'A') + 'A';
            } else {
                translated_word[i] = 'z' - (word[i] - 'a') + 'a';
            }
        } else {
            translated_word[i] = word[i];
        }
    }

    translated_word[length] = '\0';

    return translated_word;
}

void translate_sentence(char *sentence) {
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        char *translated_word = translate_word(word);
        printf("%s ", translated_word);
        free(translated_word);
        word = strtok(NULL, " ");
    }
    printf("\n");
}