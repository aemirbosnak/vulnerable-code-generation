//Code Llama-13B DATASET v1.0 Category: Word Count Tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the word and its count
struct WordCount {
    char word[20];
    int count;
};

// Function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
    struct WordCount *wc1 = (struct WordCount *) a;
    struct WordCount *wc2 = (struct WordCount *) b;
    return wc1->count - wc2->count;
}

int main(int argc, char **argv) {
    // Check if the input file was provided
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Create a WordCount structure for each word
    struct WordCount *words = malloc(sizeof(struct WordCount) * 100);
    int num_words = 0;

    // Read each word from the input file
    char word[20];
    while (fscanf(fp, "%s", word) == 1) {
        // Check if the word is already in the list
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }

        // If the word is not in the list, add it
        if (i == num_words) {
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    // Sort the words by count
    qsort(words, num_words, sizeof(struct WordCount), compareWordCount);

    // Print the sorted words
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free the memory allocated for the words
    free(words);

    // Close the input file
    fclose(fp);

    return 0;
}