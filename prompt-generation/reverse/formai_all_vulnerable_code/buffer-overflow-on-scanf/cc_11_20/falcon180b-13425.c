//Falcon-180B DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 500

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char sentence[MAX_SENTENCE_LENGTH];
    WordCount words[100];
    int numWords = 0;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", sentence);

    // Open input file
    file = fopen(sentence, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read in sentences from input file
    while (fgets(sentence, MAX_SENTENCE_LENGTH, file)!= NULL) {
        // Remove newline character from end of sentence
        sentence[strcspn(sentence, "\n")] = '\0';

        // Convert sentence to lowercase
        for (int i = 0; i < strlen(sentence); i++) {
            sentence[i] = tolower(sentence[i]);
        }

        // Count words in sentence
        char *word = strtok(sentence, " ");
        while (word!= NULL) {
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strncpy(words[numWords].word, word, MAX_WORD_LENGTH);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Close input file
    fclose(file);

    // Sort words by frequency
    for (int i = 0; i < numWords-1; i++) {
        for (int j = i+1; j < numWords; j++) {
            if (words[i].count < words[j].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Display top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free memory
    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}