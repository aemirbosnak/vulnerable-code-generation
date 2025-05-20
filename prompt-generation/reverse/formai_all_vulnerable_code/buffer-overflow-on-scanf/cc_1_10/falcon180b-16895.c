//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *english;
    char *alien;
} word_t;

typedef struct {
    int num_words;
    word_t *words;
} sentence_t;

sentence_t *create_sentence(int num_words) {
    sentence_t *sentence = malloc(sizeof(sentence_t));
    sentence->num_words = num_words;
    sentence->words = malloc(sizeof(word_t) * num_words);
    for (int i = 0; i < num_words; i++) {
        sentence->words[i].english = NULL;
        sentence->words[i].alien = NULL;
    }
    return sentence;
}

void destroy_sentence(sentence_t *sentence) {
    for (int i = 0; i < sentence->num_words; i++) {
        free(sentence->words[i].english);
        free(sentence->words[i].alien);
    }
    free(sentence->words);
    free(sentence);
}

void add_word(sentence_t *sentence, char *english, char *alien) {
    if (sentence->num_words >= MAX_WORDS) {
        printf("Error: sentence is too long\n");
        exit(1);
    }
    sentence->words[sentence->num_words].english = strdup(english);
    sentence->words[sentence->num_words].alien = strdup(alien);
    sentence->num_words++;
}

void print_sentence(sentence_t *sentence) {
    for (int i = 0; i < sentence->num_words; i++) {
        printf("%s -> %s\n", sentence->words[i].english, sentence->words[i].alien);
    }
}

int main() {
    sentence_t *sentence = create_sentence(0);
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];

    while (1) {
        printf("Enter an English word (or type 'done' to finish): ");
        scanf("%s", english);
        if (strcmp(english, "done") == 0) {
            break;
        }
        printf("Enter the corresponding alien word: ");
        scanf("%s", alien);
        add_word(sentence, english, alien);
    }

    print_sentence(sentence);
    destroy_sentence(sentence);

    return 0;
}