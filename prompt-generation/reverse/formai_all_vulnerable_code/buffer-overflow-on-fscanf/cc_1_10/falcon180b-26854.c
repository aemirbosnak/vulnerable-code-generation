//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WORD_LENGTH 50
#define MAX_FILE_SIZE 1000000

// Function to count the frequency of each word in the given file
void count_word_frequency(FILE* file, char* filename) {
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    int word_count = 0;

    // Read the file and count the frequency of each word
    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
            word[word_length - 1] = '\0'; // Add null terminator to the word
            if (isalpha(word[0])) { // Check if the word starts with a letter
                word_count++;
            }
        }
    }

    // Print the word frequency count
    printf("Word frequency count for %s:\n", filename);
    printf("Total words: %d\n", word_count);
}

// Function to split the string into words
void split_string(char* string, char** words) {
    int i = 0;
    int j = 0;
    int word_count = 0;

    // Split the string into words
    while (string[i]!= '\0') {
        if (isalpha(string[i])) { // Check if the character is a letter
            words[j] = malloc(MAX_WORD_LENGTH * sizeof(char));
            strncpy(words[j], &string[i], MAX_WORD_LENGTH);
            words[j][MAX_WORD_LENGTH - 1] = '\0'; // Add null terminator to the word
            j++;
            word_count++;
        }
        i++;
    }

    // Print the word count
    printf("Total words: %d\n", word_count);
}

int main() {
    char filename[MAX_FILE_SIZE];
    FILE* file;
    char* words[10000]; // Maximum 10000 words

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file and split it into words
    char* string = malloc(MAX_FILE_SIZE * sizeof(char));
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    fread(string, sizeof(char), file_size, file);
    split_string(string, words);

    // Count the frequency of each word
    count_word_frequency(file, filename);

    // Close the file
    fclose(file);

    return 0;
}