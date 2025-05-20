//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    // Create an array of word counts
    WordCount words[MAX_WORDS];

    // Read the dictionary into the array
    FILE *dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        fprintf(stderr, "Error: could not open dictionary file\n");
        return EXIT_FAILURE;
    }

    int i = 0;
    while (fscanf(dict, "%s", words[i].word) == 1) {
        words[i].count = 0;
        i++;
    }
    fclose(dict);

    // Read the text file to be checked
    FILE *text = fopen("text.txt", "r");
    if (text == NULL) {
        fprintf(stderr, "Error: could not open text file\n");
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LEN];
    while (fscanf(text, "%s", word) == 1) {
        // Remove punctuation from the word
        int len = strlen(word);
        for (int j = 0; j < len; j++) {
            if (!isalpha(word[j])) {
                word[j] = '\0';
                break;
            }
        }

        // Check if the word is in the dictionary
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the dictionary, print it out
        if (!found) {
            printf("%s\n", word);
        }
    }
    fclose(text);

    return EXIT_SUCCESS;
}