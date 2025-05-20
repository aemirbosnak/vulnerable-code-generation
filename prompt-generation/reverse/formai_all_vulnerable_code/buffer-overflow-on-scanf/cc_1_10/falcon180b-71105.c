//Falcon-180B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct Sentence {
    char sentence[MAX_SENTENCE_LENGTH];
    Word words[100];
    int num_words;
} Sentence;

void init_sentence(Sentence *sentence) {
    strcpy(sentence->sentence, "");
    sentence->num_words = 0;
}

void add_word(Sentence *sentence, char *word) {
    int i;
    for (i = 0; i < sentence->num_words; i++) {
        if (strcmp(sentence->words[i].word, word) == 0) {
            sentence->words[i].count++;
            return;
        }
    }
    if (sentence->num_words >= 100) {
        printf("Error: Too many unique words in sentence.\n");
        exit(1);
    }
    strcpy(sentence->words[sentence->num_words].word, word);
    sentence->words[sentence->num_words].count = 1;
    sentence->num_words++;
}

void print_sentence_stats(Sentence *sentence) {
    int i;
    printf("Sentence: %s\n", sentence->sentence);
    printf("Number of words: %d\n", sentence->num_words);
    for (i = 0; i < sentence->num_words; i++) {
        printf("Word %d: %s (%d occurrences)\n", i+1, sentence->words[i].word, sentence->words[i].count);
    }
}

int main() {
    char input_sentence[MAX_SENTENCE_LENGTH];
    Sentence sentence;
    init_sentence(&sentence);
    printf("Enter a sentence: ");
    scanf("%[^\n]", input_sentence);
    strcat(sentence.sentence, input_sentence);
    char *token = strtok(input_sentence, " ");
    while (token!= NULL) {
        add_word(&sentence, token);
        token = strtok(NULL, " ");
    }
    print_sentence_stats(&sentence);
    return 0;
}