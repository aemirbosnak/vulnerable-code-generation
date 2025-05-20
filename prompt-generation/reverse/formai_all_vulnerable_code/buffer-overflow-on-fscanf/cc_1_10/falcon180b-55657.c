//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    WordFrequency *word_frequency_table = (WordFrequency*) malloc(MAX_WORDS * sizeof(WordFrequency));
    int num_words = 0;

    // Read in words from input file and count their frequencies
    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_frequency_table[i].word, word) == 0) {
                // Word already exists in table, increment frequency
                word_frequency_table[i].frequency++;
                break;
            }
        }
        if (i == num_words) {
            // Word does not exist in table, add it
            strcpy(word_frequency_table[num_words].word, word);
            word_frequency_table[num_words].frequency = 1;
            num_words++;
        }
    }
    fclose(input_file);

    // Sort words by frequency in descending order
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_frequency_table[j].frequency > word_frequency_table[i].frequency) {
                WordFrequency temp = word_frequency_table[i];
                word_frequency_table[i] = word_frequency_table[j];
                word_frequency_table[j] = temp;
            }
        }
    }

    // Print out word frequency table
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    // Free memory
    free(word_frequency_table);

    return 0;
}