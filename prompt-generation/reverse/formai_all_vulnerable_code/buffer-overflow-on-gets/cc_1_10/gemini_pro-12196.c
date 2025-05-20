//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Function to find the longest word in a string
char *find_longest_word(char *str) {
    // Initialize the longest word and its length
    char *longest_word = NULL;
    int longest_word_length = 0;

    // Iterate over each word in the string
    char *word = strtok(str, " ");
    while (word != NULL) {
        // Get the length of the current word
        int word_length = strlen(word);

        // If the current word is longer than the longest word so far, update the longest word and its length
        if (word_length > longest_word_length) {
            longest_word = word;
            longest_word_length = word_length;
        }

        // Get the next word in the string
        word = strtok(NULL, " ");
    }

    // Return the longest word
    return longest_word;
}

// Function to find the shortest word in a string
char *find_shortest_word(char *str) {
    // Initialize the shortest word and its length
    char *shortest_word = NULL;
    int shortest_word_length = MAX_WORD_LENGTH;

    // Iterate over each word in the string
    char *word = strtok(str, " ");
    while (word != NULL) {
        // Get the length of the current word
        int word_length = strlen(word);

        // If the current word is shorter than the shortest word so far, update the shortest word and its length
        if (word_length < shortest_word_length) {
            shortest_word = word;
            shortest_word_length = word_length;
        }

        // Get the next word in the string
        word = strtok(NULL, " ");
    }

    // Return the shortest word
    return shortest_word;
}

// Function to find the average word length in a string
float find_average_word_length(char *str) {
    // Initialize the total word length and the number of words
    int total_word_length = 0;
    int number_of_words = 0;

    // Iterate over each word in the string
    char *word = strtok(str, " ");
    while (word != NULL) {
        // Get the length of the current word
        int word_length = strlen(word);

        // Add the word length to the total word length
        total_word_length += word_length;

        // Increment the number of words
        number_of_words++;

        // Get the next word in the string
        word = strtok(NULL, " ");
    }

    // Calculate the average word length
    float average_word_length = (float)total_word_length / number_of_words;

    // Return the average word length
    return average_word_length;
}

// Function to print the statistics of a string
void print_string_statistics(char *str) {
    // Find the longest word, shortest word, and average word length
    char *longest_word = find_longest_word(str);
    char *shortest_word = find_shortest_word(str);
    float average_word_length = find_average_word_length(str);

    // Print the statistics
    printf("Longest word: %s\n", longest_word);
    printf("Shortest word: %s\n", shortest_word);
    printf("Average word length: %.2f\n", average_word_length);
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Print the statistics of the string
    print_string_statistics(str);

    return 0;
}