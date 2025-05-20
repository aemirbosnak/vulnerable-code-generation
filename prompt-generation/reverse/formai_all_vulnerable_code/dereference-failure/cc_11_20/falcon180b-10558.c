//Falcon-180B DATASET v1.0 Category: Educational ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordFrequency *word_frequency;
    int num_words = 0;

    // Allocate memory for word frequency array
    word_frequency = (WordFrequency*) malloc(MAX_WORDS * sizeof(WordFrequency));

    // Open input file
    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read input file and count word frequencies
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            num_words++;
            if (num_words > MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                exit(1);
            }
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_frequency[i].word) == 0) {
                    word_frequency[i].frequency++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(word_frequency[num_words - 1].word, word);
                word_frequency[num_words - 1].frequency = 1;
            }
            word = strtok(NULL, " ");
        }
    }

    // Sort word frequency array in descending order
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_frequency[j].frequency > word_frequency[i].frequency) {
                WordFrequency temp = word_frequency[i];
                word_frequency[i] = word_frequency[j];
                word_frequency[j] = temp;
            }
        }
    }

    // Print word frequency results
    printf("Word frequency:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }

    // Free memory
    free(word_frequency);

    // Close input file
    fclose(file);

    return 0;
}