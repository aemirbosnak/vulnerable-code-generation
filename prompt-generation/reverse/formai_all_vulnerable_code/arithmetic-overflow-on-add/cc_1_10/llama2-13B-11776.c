//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define a struct to hold the word count data
struct word_count {
    char *word;
    int count;
};

// Function to count the number of words in a given string
int count_words(const char *str) {
    // Initialize an empty array to store the word counts
    struct word_count words[10];

    // Iterate through the string and count the words
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        // If the current character is a space, start a new word
        if (isspace(*ptr)) {
            // If the previous character was not a space, start a new word
            if (*(ptr - 1) != ' ') {
                // Initialize a new word count struct
                struct word_count *word = &words[0];

                // Set the word and count values
                word->word = ptr;
                word->count = 1;

                // Add the new word to the array
                words[0] = *word;
            }
        } else {
            // If the current character is not a space, increment the current word count
            words[0].count++;
        }
    }

    // Return the number of words in the string
    return sizeof(words) / sizeof(words[0]);
}

// Function to print the word count data
void print_word_counts(const char *str) {
    struct word_count *words = count_words(str);

    // Print the word counts
    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        printf("%d: %s\n", words[i].count, words[i].word);
    }
}

int main() {
    // Test the word count function
    char str[] = "Hello, world! How are you today?";
    int word_count = count_words(str);
    printf("Word count: %d\n", word_count);

    // Print the word counts for a funky string
    char funky_str[] = "Hello, world! How are you today? Funky monkey!";
    print_word_counts(funky_str);

    return 0;
}