//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Define the maximum number of characters in a word
    int MAX_WORD_LENGTH = 10;
    
    // Define the maximum number of words to keep
    int MAX_WORDS = 10;
    
    // Define the frequency threshold for keeping a word
    int MIN_FREQUENCY = 2;
    
    // Define the file name to read from
    char* filename = "input.txt";
    
    // Initialize the hash table with an array of 26 slots for the 26 English letters
    int* hashTable = malloc(sizeof(int) * 26);
    for (int i = 0; i < 26; i++) {
        hashTable[i] = 0;
    }
    
    // Read the input file and process each line
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH + 1, file)) {
        // Remove any whitespace characters at the beginning and end of the line
        line[strcspn(line, " \t\n\r")] = '\0';
        
        // Tokenize the line into individual words
        char* word = strtok(line, " \t\n\r");
        while (word!= NULL) {
            // Check if the word is within the maximum length
            if (strlen(word) <= MAX_WORD_LENGTH) {
                // Check if the word is a letter
                if (isalpha(word[0])) {
                    // Convert the word to lowercase
                    int lowercase = tolower(word[0]);
                    
                    // Increment the frequency of the word in the hash table
                    hashTable[lowercase]++;
                }
            }
            
            // Get the next word
            word = strtok(NULL, " \t\n\r");
        }
    }
    
    // Close the input file
    fclose(file);
    
    // Sort the hash table by frequency in descending order
    int i = 0;
    for (int j = 0; j < 26; j++) {
        if (hashTable[j]!= 0) {
            for (i = j; i < 26; i++) {
                if (hashTable[i] == 0) {
                    int temp = hashTable[j];
                    hashTable[j] = hashTable[i];
                    hashTable[i] = temp;
                }
            }
        }
    }
    
    // Print the top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int j = 0; j < 10; j++) {
        if (hashTable[j]!= 0) {
            printf("%s: %d\n", &line[j], hashTable[j]);
        }
    }
    
    // Free the memory allocated for the hash table
    free(hashTable);
    
    return 0;
}