//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

struct word {
    char *word;
    int frequency;
};

struct sentence {
    char *sentence;
    int num_words;
    struct word *words;
};

void generate_random_sentence(struct sentence *sentence) {
    char *words[MAX_SENTENCE_LENGTH];
    int num_words = 0;

    srand(time(NULL));

    while (num_words < MAX_SENTENCE_LENGTH) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        char *word = malloc(word_length + 1);
        for (int i = 0; i < word_length; i++) {
            word[i] = rand() % 26 + 'a';
        }
        word[word_length] = '\0';
        words[num_words++] = word;
    }

    sentence->num_words = num_words;
    sentence->words = malloc(num_words * sizeof(struct word));

    for (int i = 0; i < num_words; i++) {
        int frequency = rand() % 10 + 1;
        sentence->words[i].word = words[i];
        sentence->words[i].frequency = frequency;
    }

    sentence->sentence = malloc((num_words - 1) * (MAX_WORD_LENGTH + 1) + 1);
    for (int i = 0; i < num_words - 1; i++) {
        strcat(sentence->sentence, words[i]);
        strcat(sentence->sentence, " ");
    }
    strcat(sentence->sentence, words[num_words - 1]);
}

void print_sentence(struct sentence *sentence) {
    printf("Sentence: %s\n", sentence->sentence);

    printf("Word frequencies:\n");
    for (int i = 0; i < sentence->num_words; i++) {
        printf("%s: %d\n", sentence->words[i].word, sentence->words[i].frequency);
    }
}

int main() {
    struct sentence sentence;
    generate_random_sentence(&sentence);
    print_sentence(&sentence);

    return 0;
}