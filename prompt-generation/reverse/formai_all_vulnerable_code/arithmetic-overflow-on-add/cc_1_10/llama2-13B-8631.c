//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the word count struct
typedef struct {
    int words;
    int characters;
} word_count_t;

// Define the function to count the words
word_count_t count_words(char *str) {
    word_count_t count;
    char *ptr = str;
    int i = 0;

    // Loop through each character in the string
    while (*ptr != '\0') {
        // If we find a space, increment the word count
        if (*ptr == ' ') {
            count.words++;
            i++;
        }
        ptr++;
    }

    // Calculate the character count
    count.characters = i;

    return count;
}

// Define the function to print the word count
void print_word_count(word_count_t count) {
    printf("The word count for the given string is:\n");
    printf("  Words: %d\n", count.words);
    printf("  Characters: %d\n", count.characters);
}

int main() {
    // Prompt the user for a string to count
    printf("Enter a string to count the words: ");
    char str[100];
    fgets(str, 100, stdin);

    // Count the words and characters
    word_count_t count = count_words(str);

    // Print the word count
    print_word_count(count);

    return 0;
}