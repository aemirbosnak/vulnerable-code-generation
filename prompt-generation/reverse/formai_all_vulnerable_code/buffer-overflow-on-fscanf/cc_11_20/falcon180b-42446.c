//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    char input[MAX_WORD_LEN];
    char *token;
    FILE *fp;
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    // Open the input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    // Read in words and update word counts
    while (fscanf(fp, "%s", input)!= EOF) {
        token = strtok(input, ",.?!;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                // New word encountered
                if (num_words >= MAX_WORDS) {
                    printf("Error: maximum number of words reached\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, token);
                word_counts[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    // Close the input file
    fclose(fp);

    // Sort the word counts in descending order
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_counts[j].count > word_counts[i].count) {
                WordCount temp = word_counts[i];
                word_counts[i] = word_counts[j];
                word_counts[j] = temp;
            }
        }
    }

    // Print the word counts
    printf("Word Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}