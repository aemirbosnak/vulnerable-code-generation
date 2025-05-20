//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_SENTENCE_LENGTH 100
#define MAX_VOCABULARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Vocabulary;

Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
int vocabulary_size = 0;

int compareWords(const void *a, const void *b) {
    Vocabulary *vocab_a = (Vocabulary *) a;
    Vocabulary *vocab_b = (Vocabulary *) b;
    return strcmp(vocab_a->word, vocab_b->word);
}

void loadVocabulary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open vocabulary file.\n");
        exit(1);
    }
    while (fscanf(file, "%s %d", vocabulary[vocabulary_size].word, &vocabulary[vocabulary_size].frequency)!= EOF) {
        vocabulary_size++;
    }
    fclose(file);
    qsort(vocabulary, vocabulary_size, sizeof(Vocabulary), compareWords);
}

void generateSentence(int sentence_length) {
    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, "The quick brown fox jumps over the lazy dog. ");
    int position = strlen(sentence) - 1;
    while (position > 0) {
        int word_index = rand() % vocabulary_size;
        Vocabulary *vocab = &vocabulary[word_index];
        int word_length = strlen(vocab->word);
        if (position - word_length >= 0) {
            strcpy(&sentence[position - word_length], vocab->word);
            position -= word_length;
        }
    }
    printf("%s\n", sentence);
}

int main() {
    loadVocabulary("vocabulary.txt");
    int sentence_length = rand() % MAX_SENTENCE_LENGTH + 1;
    generateSentence(sentence_length);
    return 0;
}