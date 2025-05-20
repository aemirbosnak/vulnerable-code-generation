//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *input_file;
    char line[1024];
    char *word;
    WordFrequency *word_frequency_table = (WordFrequency*) malloc(MAX_WORDS * sizeof(WordFrequency));
    int num_words = 0;
    int i;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        num_words = 0;
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            if (strlen(word) > 0) {
                int found = 0;
                for (i = 0; i < num_words; i++) {
                    if (strcmp(word_frequency_table[i].word, word) == 0) {
                        word_frequency_table[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(word_frequency_table[num_words].word, word);
                    word_frequency_table[num_words].count = 1;
                    num_words++;
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].count);
    }

    free(word_frequency_table);

    return 0;
}