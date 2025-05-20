//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequency) {
    char c;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            word[word_length++] = tolower(c);
        } else if (word_length > 0) {
            word[word_length] = '\0';
            int i;
            for (i = 0; i < MAX_WORD_LENGTH; i++) {
                if (strcmp(word, word_frequency[i].word) == 0) {
                    word_frequency[i].frequency++;
                    break;
                }
            }
            if (i == MAX_WORD_LENGTH) {
                if (word_frequency->frequency == 0) {
                    strcpy(word_frequency->word, word);
                    word_frequency->frequency = 1;
                } else {
                    printf("Error: maximum number of words reached (%d)\n", MAX_WORDS);
                    exit(1);
                }
            }
            word_length = 0;
        }
    }
}

void write_file(FILE *file, WordFrequency *word_frequency) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_frequency[i].frequency > 0) {
            fprintf(file, "%s %d\n", word_frequency[i].word, word_frequency[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        return 1;
    }

    WordFrequency word_frequency[MAX_WORDS];
    memset(word_frequency, 0, sizeof(WordFrequency) * MAX_WORDS);

    read_file(input_file, word_frequency);

    write_file(output_file, word_frequency);

    fclose(input_file);
    fclose(output_file);

    return 0;
}