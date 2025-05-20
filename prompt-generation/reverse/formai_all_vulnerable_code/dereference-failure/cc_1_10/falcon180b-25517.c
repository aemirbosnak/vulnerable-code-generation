//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: too many words\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void print_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void alien_language(char* sentence) {
    char* word;
    char* new_sentence = malloc(strlen(sentence) + 1);
    strcpy(new_sentence, sentence);
    word = strtok(new_sentence, " ");
    while (word!= NULL) {
        add_word(word);
        word = strtok(NULL, " ");
    }
    free(new_sentence);
}

int main() {
    char sentence[1000];
    printf("Enter a sentence in English:\n");
    fgets(sentence, 1000, stdin);
    alien_language(sentence);
    print_words();
    return 0;
}