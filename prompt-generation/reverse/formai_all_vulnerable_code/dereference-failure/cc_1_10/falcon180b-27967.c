//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char line[MAX_WORD_LENGTH];
    char *word;
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i;

    if (argc!= 3) {
        printf("Usage: spell_check input_file output_file\n");
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, " \t\r\n\f\v,.?!");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words\n");
                return 1;
            }
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
            word = strtok(NULL, " \t\r\n\f\v,.?!");
        }
    }

    for (i = 0; i < num_words; i++) {
        if (words[i].count > 1) {
            fprintf(output_file, "%s\n", words[i].word);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}