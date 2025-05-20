//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_t;

// Function to check if a word is valid
int is_valid_word(const char *word) {
    if (strlen(word) > MAX_WORD_LENGTH) {
        return 0;
    }
    if (word[0] < 'a' || word[0] > 'z') {
        return 0;
    }
    for (int i = 1; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to count the frequency of each word in a file
int count_words(FILE *file, word_t *words, int num_words) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char *word = strtok(line, " ,.-\n");
        while (word != NULL) {
            int index = 0;
            while (words[index].word[0] != '\0' && strcmp(words[index].word, word) != 0) {
                index++;
            }
            if (words[index].word[0] == '\0') {
                strcpy(words[index].word, word);
                words[index].frequency = 1;
            } else {
                words[index].frequency++;
            }
            word = strtok(NULL, " ,.-\n");
        }
    }
    return num_words;
}

// Function to print the frequency of each word
void print_frequency(word_t *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Allocate memory for the array of words
    word_t *words = malloc(sizeof(word_t) * MAX_WORD_LENGTH);
    if (words == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    // Initialize the array of words
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        words[i].word[0] = '\0';
        words[i].frequency = 0;
    }

    // Count the frequency of each word
    int num_words = count_words(file, words, MAX_WORD_LENGTH);

    // Print the frequency of each word
    print_frequency(words, num_words);

    // Free the memory allocated for the array of words
    free(words);

    // Close the file
    fclose(file);

    return 0;
}