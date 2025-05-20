//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to store
#define MAX_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Create a struct to store a word and its count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Create an array to store the words and their counts
Word words[MAX_WORDS];

// Create a variable to store the number of words in the array
int num_words = 0;

// Create a function to add a word to the array
void add_word(char *word) {
    // Check if the word is already in the array
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            // If the word is already in the array, increment its count
            words[i].count++;
            return;
        }
    }

    // If the word is not in the array, add it to the array
    if (num_words < MAX_WORDS) {
        strcpy(words[num_words].word, word);
        words[num_words].count = 1;
        num_words++;
    }
}

// Create a function to print the words and their counts
void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

// Create a function to read a file and count the words in the file
void count_words(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Split the line into words
        char *word = strtok(line, " ");
        while (word != NULL) {
            // Add the word to the array
            add_word(word);
            // Get the next word
            word = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);
}

// Main function
int main() {
    // Get the filename from the user
    char filename[1024];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Count the words in the file
    count_words(filename);

    // Print the words and their counts
    print_words();

    return 0;
}