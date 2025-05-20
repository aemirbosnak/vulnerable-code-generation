//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

// Structure to hold word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFreq;

// Function prototypes
void convert_to_lowercase(char *str);
int add_word(WordFreq *words, int count, const char *new_word);
void sort_words(WordFreq *words, int count);
void display_word_frequencies(WordFreq *words, int count);

int main() {
    FILE *file;
    char filename[100];
    char word[MAX_WORD_LENGTH];
    WordFreq words[MAX_WORDS];
    int word_count = 0;

    // Prompt user for file name
    printf("Enter the filename to count word frequencies: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    // Read the words from file
    while (fscanf(file, "%99s", word) == 1) {
        convert_to_lowercase(word);
        word_count = add_word(words, word_count, word);
    }

    fclose(file);

    // Sort the words by frequency
    sort_words(words, word_count);

    // Display the word frequencies
    display_word_frequencies(words, word_count);

    return EXIT_SUCCESS;
}

// Function to convert a string to lowercase
void convert_to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Function to add a new word to the frequency list
int add_word(WordFreq *words, int count, const char *new_word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].frequency++;
            return count; // No new word added, return current count
        }
    }
    
    // Add new word
    strcpy(words[count].word, new_word);
    words[count].frequency = 1;
    return count + 1; // Increment count
}

// Function to sort words based on frequency (descending)
void sort_words(WordFreq *words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (words[j].frequency < words[j + 1].frequency) {
                // Swap words
                WordFreq temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Function to display the word frequencies
void display_word_frequencies(WordFreq *words, int count) {
    printf("\nWord Frequencies:\n");
    printf("-----------------\n");
    for (int i = 0; i < count; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}