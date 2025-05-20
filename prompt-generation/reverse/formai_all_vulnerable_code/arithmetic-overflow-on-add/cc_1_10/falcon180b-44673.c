//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_words(FILE *fp, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) <= MAX_WORD_LENGTH) {
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            int index = 0;
            while (index < MAX_WORDS && strcmp(words[index].word, word)!= 0) {
                index++;
            }
            if (index == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
            } else {
                words[index].frequency++;
            }
        }
    }
}

void write_words(FILE *fp, WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            fprintf(fp, "%s %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    WordFrequency words[MAX_WORDS];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    read_words(input_file, words);

    fclose(input_file);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    write_words(output_file, words);

    fclose(output_file);

    return 0;
}