//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(const char* filename, struct word_frequency* words, int* num_words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        struct word_frequency* found_word = NULL;
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found_word = &words[i];
                break;
            }
        }

        if (found_word == NULL) {
            if (*num_words >= MAX_WORDS) {
                printf("Error: too many unique words in file\n");
                exit(1);
            }
            strcpy(found_word->word, word);
            found_word->frequency = 1;
            (*num_words)++;
        } else {
            found_word->frequency++;
        }
    }

    fclose(file);
}

void write_file(const char* filename, struct word_frequency* words, int num_words) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].frequency);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    struct word_frequency words[MAX_WORDS];
    int num_words = 0;

    read_file(argv[1], words, &num_words);
    write_file(argv[2], words, num_words);

    return 0;
}