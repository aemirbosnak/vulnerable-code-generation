//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
    const WordCount *wordCountA = (const WordCount *)a;
    const WordCount *wordCountB = (const WordCount *)b;

    return strcmp(wordCountA->word, wordCountB->word);
}

// Function to count the number of words in a string
int countWords(const char *string) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalpha(string[i]) || isdigit(string[i])) {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    return count;
}

// Function to get the unique words in a string
char **getUniqueWords(const char *string, int *n) {
    // Count the number of words in the string
    int numWords = countWords(string);

    // Allocate memory for the array of unique words
    char **uniqueWords = (char **)malloc(sizeof(char *) * numWords);

    // Initialize the array of unique words
    for (int i = 0; i < numWords; i++) {
        uniqueWords[i] = NULL;
    }

    // Get the unique words from the string
    int index = 0;
    int start = 0;
    int inWord = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalpha(string[i]) || isdigit(string[i])) {
            if (!inWord) {
                start = i;
                inWord = 1;
            }
        } else {
            if (inWord) {
                // Get the word
                int length = i - start + 1;
                char *word = (char *)malloc(sizeof(char) * length);
                strncpy(word, string + start, length - 1);
                word[length - 1] = '\0';

                // Add the word to the array of unique words
                uniqueWords[index++] = word;
                inWord = 0;
            }
        }
    }

    // If the last character is a letter, add the last word to the array of unique words
    if (inWord) {
        int length = strlen(string) - start + 1;
        char *word = (char *)malloc(sizeof(char) * length);
        strncpy(word, string + start, length - 1);
        word[length - 1] = '\0';

        uniqueWords[index++] = word;
    }

    // Return the array of unique words
    *n = numWords;
    return uniqueWords;
}

// Function to count the occurrences of each word in a string
int *countWordOccurrences(const char *string, char **uniqueWords, int numWords) {
    // Allocate memory for the array of word occurrences
    int *wordOccurrences = (int *)malloc(sizeof(int) * numWords);

    // Initialize the array of word occurrences
    for (int i = 0; i < numWords; i++) {
        wordOccurrences[i] = 0;
    }

    // Count the occurrences of each word in the string
    int index = 0;
    int start = 0;
    int inWord = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalpha(string[i]) || isdigit(string[i])) {
            if (!inWord) {
                start = i;
                inWord = 1;
            }
        } else {
            if (inWord) {
                // Get the word
                int length = i - start + 1;
                char *word = (char *)malloc(sizeof(char) * length);
                strncpy(word, string + start, length - 1);
                word[length - 1] = '\0';

                // Find the index of the word in the array of unique words
                int wordIndex = -1;
                for (int j = 0; j < numWords; j++) {
                    if (strcmp(word, uniqueWords[j]) == 0) {
                        wordIndex = j;
                        break;
                    }
                }

                // If the word is found in the array of unique words, increment its count
                if (wordIndex != -1) {
                    wordOccurrences[wordIndex]++;
                }

                free(word);
                inWord = 0;
            }
        }
    }

    // If the last character is a letter, count the occurrence of the last word
    if (inWord) {
        int length = strlen(string) - start + 1;
        char *word = (char *)malloc(sizeof(char) * length);
        strncpy(word, string + start, length - 1);
        word[length - 1] = '\0';

        // Find the index of the word in the array of unique words
        int wordIndex = -1;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(word, uniqueWords[j]) == 0) {
                wordIndex = j;
                break;
            }
        }

        // If the word is found in the array of unique words, increment its count
        if (wordIndex != -1) {
            wordOccurrences[wordIndex]++;
        }

        free(word);
    }

    // Return the array of word occurrences
    return wordOccurrences;
}

// Function to print the word frequencies
void printWordFrequencies(char **uniqueWords, int *wordOccurrences, int numWords) {
    // Sort the unique words in alphabetical order
    qsort(uniqueWords, numWords, sizeof(char *), compareWordCount);

    // Print the word frequencies
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", uniqueWords[i], wordOccurrences[i]);
    }
}

int main() {
    // Get the input string from the user
    char string[1000];
    printf("Enter a string: ");
    gets(string);

    // Get the unique words from the string
    int numWords;
    char **uniqueWords = getUniqueWords(string, &numWords);

    // Count the occurrences of each word in the string
    int *wordOccurrences = countWordOccurrences(string, uniqueWords, numWords);

    // Print the word frequencies
    printWordFrequencies(uniqueWords, wordOccurrences, numWords);

    // Free the allocated memory
    for (int i = 0; i < numWords; i++) {
        free(uniqueWords[i]);
    }
    free(uniqueWords);
    free(wordOccurrences);

    return 0;
}