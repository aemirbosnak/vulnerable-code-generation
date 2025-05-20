//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 100
#define MAX_VOCABULARY_SIZE 1000

// Struct to store vocabulary
typedef struct vocabulary {
    char english_word[MAX_WORD_LENGTH];
    char cat_word[MAX_WORD_LENGTH];
} Vocabulary;

// Struct to store sentence
typedef struct sentence {
    int word_count;
    char words[MAX_SENTENCE_LENGTH][MAX_WORD_LENGTH];
} Sentence;

// Function to load vocabulary from file
void load_vocabulary(Vocabulary *vocabulary, int size) {
    FILE *file = fopen("vocabulary.txt", "r");
    if (file == NULL) {
        printf("Error loading vocabulary\n");
        exit(1);
    }
    int count = 0;
    while (count < size && fscanf(file, "%s %s", vocabulary[count].english_word, vocabulary[count].cat_word)!= EOF) {
        count++;
    }
    fclose(file);
}

// Function to load sentence from file
void load_sentence(Sentence *sentence) {
    FILE *file = fopen("sentence.txt", "r");
    if (file == NULL) {
        printf("Error loading sentence\n");
        exit(1);
    }
    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(sentence->words[word_count], word);
        word_count++;
    }
    sentence->word_count = word_count;
    fclose(file);
}

// Function to translate sentence
void translate_sentence(Vocabulary *vocabulary, Sentence *sentence) {
    int i, j;
    for (i = 0; i < sentence->word_count; i++) {
        for (j = 0; j < MAX_VOCABULARY_SIZE; j++) {
            if (strcmp(sentence->words[i], vocabulary[j].english_word) == 0) {
                strcpy(sentence->words[i], vocabulary[j].cat_word);
                break;
            }
        }
    }
}

// Function to save translated sentence to file
void save_sentence(Sentence *sentence) {
    FILE *file = fopen("translated_sentence.txt", "w");
    if (file == NULL) {
        printf("Error saving translated sentence\n");
        exit(1);
    }
    int i;
    for (i = 0; i < sentence->word_count; i++) {
        fprintf(file, "%s ", sentence->words[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}

int main() {
    Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
    load_vocabulary(vocabulary, MAX_VOCABULARY_SIZE);

    Sentence sentence;
    load_sentence(&sentence);

    translate_sentence(vocabulary, &sentence);

    save_sentence(&sentence);

    return 0;
}