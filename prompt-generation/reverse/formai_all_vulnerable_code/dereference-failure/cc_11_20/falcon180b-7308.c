//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 64
#define MAX_LINE_LENGTH 256
#define MAX_NUM_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency *word_frequency_table;
    int num_words = 0;
    int i;

    // Open the input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Allocate memory for the word frequency table
    word_frequency_table = (WordFrequency *) malloc(MAX_NUM_WORDS * sizeof(WordFrequency));
    if (word_frequency_table == NULL) {
        printf("Error allocating memory for word frequency table.\n");
        exit(1);
    }

    // Initialize the word frequency table
    for (i = 0; i < MAX_NUM_WORDS; i++) {
        word_frequency_table[i].word[0] = '\0';
        word_frequency_table[i].count = 0;
    }

    // Read the input file and count the frequency of each word
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v.?!;:");
        while (token!= NULL) {
            // Convert the word to lowercase and ignore punctuation
            int j;
            for (j = 0; j < strlen(token); j++) {
                if (!isalpha(token[j])) {
                    token[j] = '\0';
                    break;
                }
                token[j] = tolower(token[j]);
            }
            // Check if the word is already in the frequency table
            int k;
            for (k = 0; k < num_words; k++) {
                if (strcmp(word_frequency_table[k].word, token) == 0) {
                    word_frequency_table[k].count++;
                    break;
                }
            }
            // If the word is not in the frequency table, add it
            if (k == num_words) {
                strcpy(word_frequency_table[num_words].word, token);
                word_frequency_table[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " \t\n\r\f\v.?!;:");
        }
    }

    // Print the word frequency table
    printf("Word Frequency Table:\n");
    printf("---------------------\n");
    printf("Word\t\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t\t%d\n", word_frequency_table[i].word, word_frequency_table[i].count);
    }

    // Free the memory allocated for the word frequency table
    free(word_frequency_table);

    // Close the input file
    fclose(file);

    return 0;
}