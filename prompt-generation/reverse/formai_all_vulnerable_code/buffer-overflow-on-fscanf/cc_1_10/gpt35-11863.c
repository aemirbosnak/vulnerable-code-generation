//FormAI DATASET v1.0 Category: Text processing ; Style: calm
/*
* This program takes in a text file, counts the number of occurrences for each word in the file
* and displays the most frequent words along with their frequency in descending order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to read words from the file and store them in the words array
// Returns the number of words read
int readWords(FILE* file, Word* words) {
    int count = 0;
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) == 1) {
        // Convert the word to lower case
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        // Check if the word is already in the words array, if yes, increase its frequency
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(buffer, words[i].word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        // If the word is not already in the words array, add it
        if (!found) {
            strcpy(words[count].word, buffer);
            words[count].frequency = 1;
            count++;
        }
        // If we have read MAX_WORDS, break out of the loop
        if (count == MAX_WORDS) {
            break;
        }
    }
    return count;
}

// Bubble sort function to sort the words array in descending order of frequency
void sortWords(Word* words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (words[j].frequency < words[j+1].frequency) {
                Word temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are passed
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }
    // Allocate memory for the words array
    Word* words = (Word*) malloc(MAX_WORDS * sizeof(Word));
    if (words == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    // Read the words from the file and store them in the words array
    int count = readWords(file, words);
    // Close the file
    fclose(file);
    // Sort the words array in descending order of frequency
    sortWords(words, count);
    // Display the most frequent words and their frequencies
    printf("Most frequent words:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
    // Free the memory allocated for the words array
    free(words);
    return 0;
}