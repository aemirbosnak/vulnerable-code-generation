//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, char *buffer, int buffer_size) {
    int bytes_read = fread(buffer, 1, buffer_size, file);
    if (bytes_read == 0) {
        printf("Error reading file\n");
        exit(1);
    }
}

void process_sentence(char *sentence, int sentence_length, WordFrequency *word_frequencies, int num_word_frequencies) {
    char *token = strtok(sentence, ",.?!;:");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_word_frequencies; i++) {
            if (strcmp(token, word_frequencies[i].word) == 0) {
                word_frequencies[i].frequency++;
                break;
            }
        }
        if (i == num_word_frequencies) {
            if (num_word_frequencies >= MAX_WORD_LENGTH) {
                printf("Maximum number of unique words reached\n");
                exit(1);
            }
            strcpy(word_frequencies[num_word_frequencies].word, token);
            word_frequencies[num_word_frequencies].frequency = 1;
            num_word_frequencies++;
        }
        token = strtok(NULL, ",.?!;:");
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_word_frequencies) {
    printf("Word frequencies:\n");
    for (int i = 0; i < num_word_frequencies; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main() {
    FILE *input_file;
    char input_filename[MAX_SENTENCE_LENGTH];
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    char buffer[MAX_SENTENCE_LENGTH];
    int buffer_size = fread(buffer, 1, MAX_SENTENCE_LENGTH, input_file);
    if (buffer_size == 0) {
        printf("Error reading input file\n");
        exit(1);
    }
    buffer[buffer_size - 1] = '\0';

    WordFrequency word_frequencies[MAX_WORD_LENGTH];
    int num_word_frequencies = 0;

    char *sentence = strtok(buffer, ".");
    while (sentence!= NULL) {
        process_sentence(sentence, strlen(sentence), word_frequencies, num_word_frequencies);
        sentence = strtok(NULL, ".");
    }

    print_word_frequencies(word_frequencies, num_word_frequencies);

    fclose(input_file);
    return 0;
}