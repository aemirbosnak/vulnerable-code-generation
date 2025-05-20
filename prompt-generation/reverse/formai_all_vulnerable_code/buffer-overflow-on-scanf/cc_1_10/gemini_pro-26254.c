//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a word
typedef struct Word {
    char *word;
    int count;
} Word;

// A function to compare two words
int compareWords(const void *a, const void *b) {
    const Word *word1 = (const Word *)a;
    const Word *word2 = (const Word *)b;

    return strcmp(word1->word, word2->word);
}

// A function to read a file and count the occurrences of each word
int countWords(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Create an array to store the words
    Word *words = NULL;
    int numWords = 0;

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Check if the word is already in the array
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            // If the word is not in the array, add it
            if (!found) {
                words = realloc(words, (numWords + 1) * sizeof(Word));
                words[numWords].word = strdup(token);
                words[numWords].count = 1;
                numWords++;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Sort the words by their count
    qsort(words, numWords, sizeof(Word), compareWords);

    // Print the words and their counts
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free the memory allocated for the words
    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}

int main() {
    // Get the filename from the user
    char filename[1024];
    printf("Enter the name of the file to be processed: ");
    scanf("%s", filename);

    // Count the words in the file
    int result = countWords(filename);

    // Check if there was an error
    if (result == -1) {
        return 1;
    }

    return 0;
}