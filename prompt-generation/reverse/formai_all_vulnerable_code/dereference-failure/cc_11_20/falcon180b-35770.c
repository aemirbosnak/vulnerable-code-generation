//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency *word_frequency_table = (WordFrequency *)malloc(MAX_WORDS * sizeof(WordFrequency));
    int num_words = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i = 0;
        int word_length = strlen(line);

        while (i < word_length) {
            if (isalpha(line[i])) {
                int j = 0;

                while (isalpha(line[i]) && j < MAX_WORD_LENGTH) {
                    word[j] = tolower(line[i]);
                    i++;
                    j++;
                }

                word[j] = '\0';

                for (int k = 0; k < num_words; k++) {
                    if (strcmp(word, word_frequency_table[k].word) == 0) {
                        word_frequency_table[k].count++;
                        break;
                    }
                }

                if (num_words >= MAX_WORDS) {
                    printf("Too many words.\n");
                    exit(1);
                }

                strcpy(word_frequency_table[num_words].word, word);
                word_frequency_table[num_words].count = 1;
                num_words++;
            } else {
                i++;
            }
        }
    }

    fclose(file);

    printf("Word\tFrequency\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].count);
    }

    free(word_frequency_table);

    return 0;
}