//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <string.h>

// A structure to hold a word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// A function to compare two WordCount structures
int compareWordCounts(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;
    return wc2->count - wc1->count;
}

// A function to count the words in a string
int countWords(char *string) {
    int wordCount = 0;
    char *word = strtok(string, " ,.-!?;:");
    while (word != NULL) {
        wordCount++;
        word = strtok(NULL, " ,.-!?;:");
    }
    return wordCount;
}

// A function to create an array of WordCount structures
WordCount *createWordCountArray(char *string) {
    int wordCount = countWords(string);
    WordCount *wordCounts = malloc(sizeof(WordCount) * wordCount);
    char *word = strtok(string, " ,.-!?;:");
    int i = 0;
    while (word != NULL) {
        wordCounts[i].word = malloc(strlen(word) + 1);
        strcpy(wordCounts[i].word, word);
        wordCounts[i].count = 1;
        i++;
        word = strtok(NULL, " ,.-!?;:");
    }
    return wordCounts;
}

// A function to count the occurrences of each word in an array of WordCount structures
int countWordOccurrences(char *string, WordCount *wordCounts, int wordCount) {
    char *word = strtok(string, " ,.-!?;:");
    while (word != NULL) {
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        word = strtok(NULL, " ,.-!?;:");
    }
}

// A function to print the top 10 most frequently used words in an array of WordCount structures
void printTop10Words(WordCount *wordCounts, int wordCount) {
    qsort(wordCounts, wordCount, sizeof(WordCount), compareWordCounts);
    for (int i = 0; i < 10 && i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    // Get the text from the user
    char string[1000];
    printf("Enter some text: ");
    gets(string);

    // Create an array of WordCount structures
    WordCount *wordCounts = createWordCountArray(string);

    // Count the occurrences of each word in the array
    countWordOccurrences(string, wordCounts, countWords(string));

    // Print the top 10 most frequently used words
    printTop10Words(wordCounts, countWords(string));

    // Free the memory allocated for the WordCount structures
    for (int i = 0; i < countWords(string); i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}