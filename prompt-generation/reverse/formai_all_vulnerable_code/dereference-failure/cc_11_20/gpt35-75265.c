//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 5000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./wordfreq [filename]\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char** words = (char**) malloc(sizeof(char*) * MAX_NUM_WORDS);
    int* counts = (int*) calloc(MAX_NUM_WORDS, sizeof(int));
    int num_words = 0;

    char current_word[MAX_WORD_LENGTH];
    int current_length = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            if (current_length < MAX_WORD_LENGTH) {
                current_word[current_length++] = tolower(c);
            }
        } else if (current_length > 0) {
            current_word[current_length] = '\0';
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i], current_word) == 0) {
                    counts[i]++;
                    break;
                }
            }
            if (i == num_words) {
                words[num_words] = (char*) malloc(sizeof(char) * (strlen(current_word) + 1));
                strcpy(words[num_words], current_word);
                counts[num_words++] = 1;
            }
            current_length = 0;
        }
    }

    fclose(file);

    int i, j;
    // Bubble sort words and counts together by count
    for (i = 0; i < num_words-1; i++) {
        for (j = 0; j < num_words-i-1; j++) {
            if (counts[j] < counts[j+1]) {
                int temp_count = counts[j];
                counts[j] = counts[j+1];
                counts[j+1] = temp_count;
                char* temp_word = words[j];
                words[j] = words[j+1];
                words[j+1] = temp_word;
            }
        }
    }

    // Print out the top 10 most common words
    printf("Word Frequency\n");
    printf("----------------------\n");
    for (i = 0; i < 10 && i < num_words; i++) {
        printf("%-15s %d\n", words[i], counts[i]);
    }

    // Free memory
    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    free(counts);

    return 0;
}