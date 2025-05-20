//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a word in the text
struct Word {
    char* word;
    int count;
};

// A function to compare two words based on their count
int compareWords(const void* a, const void* b) {
    const struct Word* word1 = (const struct Word*)a;
    const struct Word* word2 = (const struct Word*)b;
    return word2->count - word1->count;
}

// A function to count the occurrences of each word in the text
void countWords(char* text, struct Word* words, int* wordCount) {
    // Split the text into words using strtok()
    char* token = strtok(text, " ,.-");
    while (token != NULL) {
        // Allocate memory for the word
        char* word = malloc(strlen(token) + 1);
        strcpy(word, token);

        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            words[*wordCount].word = word;
            words[*wordCount].count = 1;
            (*wordCount)++;
        }

        // Get the next word
        token = strtok(NULL, " ,.-");
    }
}

// A function to print the top 10 most frequent words in the text
void printTop10Words(struct Word* words, int wordCount) {
    // Sort the words based on their count
    qsort(words, wordCount, sizeof(struct Word), compareWords);

    // Print the top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    // Allocate memory for the text
    char* text = malloc(1000);

    // Get the text from the user
    printf("Enter the text: ");
    scanf("%[^\n]s", text);

    // Allocate memory for the array of words
    struct Word* words = malloc(1000 * sizeof(struct Word));

    // Initialize the word count to 0
    int wordCount = 0;

    // Count the occurrences of each word in the text
    countWords(text, words, &wordCount);

    // Print the top 10 most frequent words in the text
    printTop10Words(words, wordCount);

    // Free the allocated memory
    free(text);
    for (int i = 0; i < wordCount; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}