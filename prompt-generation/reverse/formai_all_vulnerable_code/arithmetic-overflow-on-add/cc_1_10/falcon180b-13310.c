//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char *word;
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    int i, j;

    // Open the file for reading
    fp = fopen("post-apocalyptic.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read each line of the file
    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        // Convert line to lowercase
        for (i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Count the number of words in the line
        word = strtok(line, " ");
        while (word!= NULL) {
            num_words++;

            // Check if we have reached the maximum number of words
            if (num_words >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(1);
            }

            // Initialize the word count for this word
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, word_counts[j].word) == 0) {
                    word_counts[j].count++;
                    break;
                }
            }

            // If this word has not been seen before, add it to the array
            if (j == num_words) {
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }

            word = strtok(NULL, " ");
        }
    }

    // Print the word counts
    printf("Word Counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Close the file
    fclose(fp);

    return 0;
}