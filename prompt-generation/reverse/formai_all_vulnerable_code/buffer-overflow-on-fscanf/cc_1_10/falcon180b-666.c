//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VOCABULARY_SIZE 10000
#define MAX_WORD_LENGTH 10
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Vocabulary;

Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
int vocabulary_size = 0;

void load_vocabulary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", line)!= EOF) {
        if (vocabulary_size >= MAX_VOCABULARY_SIZE) {
            printf("Error: vocabulary is full\n");
            exit(1);
        }

        strcpy(vocabulary[vocabulary_size].word, line);
        vocabulary[vocabulary_size].frequency = 1;
        vocabulary_size++;
    }

    fclose(file);
}

int get_word_index(char* word) {
    for (int i = 0; i < vocabulary_size; i++) {
        if (strcmp(vocabulary[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

void generate_sentence(int length) {
    char sentence[MAX_SENTENCE_LENGTH];
    int position = 0;

    srand(time(NULL));
    int start_index = rand() % vocabulary_size;
    strcpy(sentence, vocabulary[start_index].word);
    position++;

    while (position < length) {
        int next_index = get_word_index(sentence);
        if (next_index == -1) {
            next_index = rand() % vocabulary_size;
        }

        strcat(sentence, " ");
        strcat(sentence, vocabulary[next_index].word);
        position += strlen(vocabulary[next_index].word) + 1;
    }

    printf("%s\n", sentence);
}

int main() {
    load_vocabulary("vocabulary.txt");

    int sentence_length = 10;
    int num_sentences = 5;

    for (int i = 0; i < num_sentences; i++) {
        generate_sentence(sentence_length);
    }

    return 0;
}