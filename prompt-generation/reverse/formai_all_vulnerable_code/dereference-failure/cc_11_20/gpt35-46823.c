//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Error: Please provide a filename as an argument.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    // Initialize the word frequency table
    int table_size = 100;
    char **words = malloc(table_size * sizeof(char *));
    int *freqs = calloc(table_size, sizeof(int));
    int num_words = 0;

    // Read in each word and update the frequency table
    char word[MAX_WORD_LEN];
    int c;
    int word_len = 0;

    while((c = fgetc(file)) != EOF) {
        if(isalpha(c)) {
            word[word_len++] = tolower(c);
        } else if(word_len > 0) {
            // Null-terminate the word
            word[word_len] = '\0';
            word_len = 0;

            // Check if the word already exists in the frequency table
            int index = -1;
            for(int i = 0; i < num_words; i++) {
                if(strcmp(words[i], word) == 0) {
                    index = i;
                    break;
                }
            }

            if(index == -1) {
                // Add the new word to the frequency table
                if(num_words >= table_size) {
                    // Expand the table if needed
                    table_size *= 2;
                    words = realloc(words, table_size * sizeof(char *));
                    freqs = realloc(freqs, table_size * sizeof(int));
                }

                words[num_words] = strdup(word);
                freqs[num_words] = 1;
                num_words++;
            } else {
                // Increment the frequency of the existing word
                freqs[index]++;
            }
        }
    }

    // Print the word frequency table
    for(int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], freqs[i]);
    }

    // Clean up
    for(int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    free(freqs);
    fclose(file);

    return 0;
}