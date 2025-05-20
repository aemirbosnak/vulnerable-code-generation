//Falcon-180B DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void ReadTextFile(const char* filename, char* buffer, int* buffer_size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    *buffer_size = (int)file_size + 1;
    buffer[*buffer_size - 1] = '\0';

    fread(buffer, *buffer_size, 1, file);
    fclose(file);
}

void ProcessText(char* buffer, struct WordFrequency* word_frequencies, int num_words) {
    char* token = strtok(buffer, " \t\n\r\f\v.,!?;:\"'");
    while (token!= NULL && num_words > 0) {
        int i;
        for (i = 0; i < num_words; ++i) {
            if (strcmp(token, word_frequencies[i].word) == 0) {
                word_frequencies[i].frequency++;
                break;
            }
        }

        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Warning: maximum number of words (%d) reached\n", MAX_WORDS);
            } else {
                strcpy(word_frequencies[num_words].word, token);
                word_frequencies[num_words].frequency = 1;
                ++num_words;
            }
        }

        token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'");
    }
}

void PrintWordFrequencies(struct WordFrequency* word_frequencies, int num_words) {
    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; ++i) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char buffer[MAX_WORD_LENGTH * 100000];
    int buffer_size = 0;

    ReadTextFile(argv[1], buffer, &buffer_size);

    int num_words = 0;
    struct WordFrequency word_frequencies[MAX_WORDS];

    ProcessText(buffer, word_frequencies, num_words);

    PrintWordFrequencies(word_frequencies, num_words);

    return 0;
}