//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

// Function to count the number of occurrences of a word in a text file
void count_word_frequency(FILE *file, char word[MAX_NUM_WORDS][MAX_WORD_LENGTH], int frequency[MAX_NUM_WORDS], int *num_words) {
    char curr_word[MAX_WORD_LENGTH];
    int i, j;

    // Loop through each word in the file
    while (fscanf(file, "%s", curr_word) != EOF) {

        // Convert the current word to lowercase
        for (i = 0; curr_word[i]; i++) {
            curr_word[i] = tolower(curr_word[i]);
        }

        // Check if the current word is already in our list of words
        for (j = 0; j < *num_words; j++) {
            if (strcmp(word[j], curr_word) == 0) {
                // If the word is already in the list, increment its frequency
                frequency[j]++;
                break;
            }
        }
        
        // If the word is not in the list, add it
        if (j == *num_words) {
            strcpy(word[j], curr_word);
            frequency[j]++;
            (*num_words)++;
        }
    }
}

// Function to sort the words and frequencies in descending order
void sort_word_frequency(char word[MAX_NUM_WORDS][MAX_WORD_LENGTH], int frequency[MAX_NUM_WORDS], int num_words) {
    int i, j, temp_freq;
    char temp_word[MAX_WORD_LENGTH];
    
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (frequency[i] < frequency[j]) {
                // Swap the frequencies
                temp_freq = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp_freq;
                
                // Swap the words
                strcpy(temp_word, word[i]);
                strcpy(word[i], word[j]);
                strcpy(word[j], temp_word);
            }
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH], word[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_NUM_WORDS], num_words = 0, i;
    
    // Prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file %s", filename);
        return 1;
    }
    
    // Count the word frequency
    count_word_frequency(file, word, frequency, &num_words);
    
    // Sort the word frequency in descending order
    sort_word_frequency(word, frequency, num_words);

    // Print the result
    printf("Word frequency in file %s:\n", filename);
    printf("%-20s %s\n", "Word", "Frequency");
    printf("---------------------------------\n");

    for (i = 0; i < num_words; i++) {
        printf("%-20s %d\n", word[i], frequency[i]);
    }

    // Close the file
    fclose(file);

    return 0;
}