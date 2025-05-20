//GEMINI-pro DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_STRING_SIZE 100

// Define the maximum number of words in the input string
#define MAX_WORDS 10

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the delimiter used to separate words in the input string
#define DELIMITER " "

// Define the function to count the number of words in a string
int count_words(char *string) {
    int count = 0;
    char *word = strtok(string, DELIMITER);
    while (word != NULL) {
        count++;
        word = strtok(NULL, DELIMITER);
    }
    return count;
}

// Define the function to find the longest word in a string
char *find_longest_word(char *string) {
    char *longest_word = NULL;
    int longest_word_length = 0;
    char *word = strtok(string, DELIMITER);
    while (word != NULL) {
        int word_length = strlen(word);
        if (word_length > longest_word_length) {
            longest_word = word;
            longest_word_length = word_length;
        }
        word = strtok(NULL, DELIMITER);
    }
    return longest_word;
}

// Define the function to reverse a string
char *reverse_string(char *string) {
    int length = strlen(string);
    char *reversed_string = malloc(length + 1);
    int i = 0;
    int j = length - 1;
    while (i < length) {
        reversed_string[i] = string[j];
        i++;
        j--;
    }
    reversed_string[length] = '\0';
    return reversed_string;
}

// Define the main function
int main() {
    // Get the input string from the user
    char input_string[MAX_STRING_SIZE];
    printf("Enter a string: ");
    gets(input_string);

    // Count the number of words in the input string
    int word_count = count_words(input_string);
    printf("The number of words in the string is: %d\n", word_count);

    // Find the longest word in the input string
    char *longest_word = find_longest_word(input_string);
    printf("The longest word in the string is: %s\n", longest_word);

    // Reverse the input string
    char *reversed_string = reverse_string(input_string);
    printf("The reversed string is: %s\n", reversed_string);

    // Free the allocated memory
    free(reversed_string);

    return 0;
}