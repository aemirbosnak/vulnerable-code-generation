//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a structure to represent a word
typedef struct word {
    char* word;
    int count;
} word;

// Declare a function to compare two words
int compare_words(const void* a, const void* b) {
    word* word1 = (word*)a;
    word* word2 = (word*)b;
    return strcmp(word1->word, word2->word);
}

// Declare a function to print a word
void print_word(word* word) {
    printf("%s: %d\n", word->word, word->count);
}

// Declare a function to count the occurrences of each word in a string
int count_words(char* string, word** words) {
    // Allocate memory for the words array
    *words = malloc(sizeof(word) * 100);

    // Initialize the word count to 0
    int word_count = 0;

    // Split the string into words
    char* token = strtok(string, " ");
    while (token != NULL) {
        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(token, (*words)[i].word) == 0) {
                (*words)[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it to the array
        if (!found) {
            (*words)[word_count].word = token;
            (*words)[word_count].count = 1;
            word_count++;
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    // Return the word count
    return word_count;
}

int main() {
    // Get the input string from the user
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    // Count the occurrences of each word in the string
    word* words;
    int word_count = count_words(string, &words);

    // Sort the words in alphabetical order
    qsort(words, word_count, sizeof(word), compare_words);

    // Print the words and their counts
    printf("The words and their counts are:\n");
    for (int i = 0; i < word_count; i++) {
        print_word(&words[i]);
    }

    // Free the memory allocated for the words array
    free(words);

    return 0;
}