//Falcon-180B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *input_file;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    WordCount word_counts[MAX_NUM_WORDS];

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read sentences from input file
    while (fscanf(input_file, "%[^\n]", sentence)!= EOF) {
        // Convert sentence to lowercase
        for (int i = 0; i < strlen(sentence); i++) {
            sentence[i] = tolower(sentence[i]);
        }

        // Tokenize sentence into words
        char *token = strtok(sentence, " ");
        while (token!= NULL) {
            // Check if word is already in word_counts array
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, token) == 0) {
                    word_counts[i].count++;
                    found = 1;
                    break;
                }
            }

            // If word is not in word_counts array, add it
            if (!found) {
                strcpy(word_counts[num_words].word, token);
                word_counts[num_words].count = 1;
                num_words++;
            }

            token = strtok(NULL, " ");
        }
    }

    // Print word counts
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    // Close input file
    fclose(input_file);

    return 0;
}