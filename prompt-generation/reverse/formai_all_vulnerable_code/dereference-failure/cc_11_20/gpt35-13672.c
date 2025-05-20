//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000 // Maximum number of unique words
#define MAX_WORD_LENGTH 50 // Maximum length of a word

// Structure to hold information about each unique word
typedef struct {
    char* word; // The word itself
    int frequency; // The number of times the word appears
} Word;

int main() {
    // Initialize variables
    int num_words = 0; // The number of unique words encountered
    Word word_list[MAX_WORDS]; // The array of unique words
    char input_string[MAX_WORD_LENGTH + 1]; // Buffer to hold input string
    char c = getchar(); // Read the first character

    // Loop through input, character by character
    while (c != EOF) {
        // If we have reached the end of a word, add it to the list
        if (isspace(c) || ispunct(c)) {
            // Strip any trailing punctuation from the word
            int i = strlen(input_string) - 1;
            while (i >= 0 && ispunct(input_string[i])) {
                input_string[i] = '\0';
                i--;
            }

            // Check if the word is already in the list
            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(input_string, word_list[j].word) == 0) {
                    word_list[j].frequency++;
                    break;
                }
            }

            // If not, add it to the list
            if (j == num_words) {
                word_list[num_words].word = strdup(input_string);
                word_list[num_words].frequency = 1;
                num_words++;
            }

            // Reset the input string
            memset(input_string, 0, MAX_WORD_LENGTH + 1);
        }
        // If we haven't reached the end of a word, add the character to the input string
        else {
            strncat(input_string, &c, 1);
        }

        c = getchar(); // Get the next character
    }

    // Print out the list of unique words and their frequencies
    printf("Word\t\tFrequency\n");
    printf("=======================\n");
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%-15s%d\n", word_list[i].word, word_list[i].frequency);
    }

    // Free memory for word strings
    for (i = 0; i < num_words; i++) {
        free(word_list[i].word);
    }

    return 0;
}