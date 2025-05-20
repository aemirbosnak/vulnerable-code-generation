//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 32
#define MAX_SENTENCE_LEN 256

typedef struct {
    char alien_word[MAX_WORD_LEN];
    char english_word[MAX_WORD_LEN];
} word_pair;

word_pair dictionary[] = {
    {"a", "one"},
    {"b", "two"},
    {"c", "three"},
    {"d", "four"},
    {"e", "five"},
    {"f", "six"},
    {"g", "seven"},
    {"h", "eight"},
    {"i", "nine"},
    {"j", "ten"},
};

int num_words = sizeof(dictionary) / sizeof(word_pair);

int main() {
    char sentence[MAX_SENTENCE_LEN];
    char translated_sentence[MAX_SENTENCE_LEN];
    int i, j;

    printf("Enter an Alien language sentence: ");
    gets(sentence);

    translated_sentence[0] = '\0';
    for (i = 0; sentence[i] != '\0'; i++) {
        for (j = 0; j < num_words; j++) {
            if (sentence[i] == dictionary[j].alien_word[0]) {
                strcat(translated_sentence, dictionary[j].english_word);
                break;
            }
        }
        if (j == num_words) {
            translated_sentence[strlen(translated_sentence)] = sentence[i];
        }
    }

    printf("English translation: %s\n", translated_sentence);

    return 0;
}