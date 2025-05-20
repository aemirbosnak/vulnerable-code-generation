//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *token;
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    // Open the file for reading
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        // Convert the line to lowercase
        for (i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize the line into words
        token = strtok(line, " ");
        while (token!= NULL) {
            // Check if the word is already in the list of words
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    // If it is, increment the count
                    words[i].count++;
                    break;
                }
            }

            // If the word is not in the list, add it
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: too many unique words in file.\n");
                    fclose(fp);
                    return 1;
                }

                words[num_words].word = strdup(token);
                words[num_words].count = 1;
                num_words++;
            }

            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(fp);

    // Sort the words by frequency
    for (i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print the word count
    printf("Word count:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}