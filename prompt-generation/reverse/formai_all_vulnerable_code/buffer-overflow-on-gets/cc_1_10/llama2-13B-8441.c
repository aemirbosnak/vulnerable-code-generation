//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAGIC_WORD "curious"

// Structure to store word information
typedef struct {
    char *word;
    size_t length;
} word_t;

// Function to count words in a string
size_t count_words(const char *str) {
    size_t word_count = 0;
    word_t *words = NULL;

    // Tokenize the input string into words
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Check if the token is a word or not
        if (strchr(token, 'a') || strchr(token, 'e') || strchr(token, 'i') ||
                strchr(token, 'o') || strchr(token, 'u')) {
            // Add the word to the word list
            words = realloc(words, (word_count + 1) * sizeof(word_t));
            words[word_count].word = token;
            words[word_count].length = strcspn(token, " ");
            word_count++;
        }
        token = strtok(NULL, " ");
    }

    // Free the memory allocated for the word list
    free(words);

    return word_count;
}

// Function to print the word count
void print_word_count(size_t word_count) {
    printf("Word Count: %zu\n", word_count);
}

// Main function
int main() {
    // Set the input string
    char input_str[MAX_LENGTH];
    gets(input_str);

    // Count the words in the input string
    size_t word_count = count_words(input_str);

    // Print the word count
    print_word_count(word_count);

    // Add some magic to the program
    if (word_count % 2 == 0) {
        printf("The word count is even! Maybe you should try again? :P\n");
    }

    return 0;
}