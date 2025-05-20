//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100  // maximum size of input string
#define MAX_WORD_SIZE 20    // maximum size of each word

int main() {
    
    char input[MAX_INPUT_SIZE];
    char word[MAX_WORD_SIZE];
    int i, j, k;
    int wordCount = 0;
    float averageLength = 0.0;
    
    // Prompt user for input string
    printf("Enter a sentence: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    // Remove newline character from input string
    input[strcspn(input, "\n")] = 0;
    
    // Process input string to count number of words and calculate average length
    for (i = 0; i < strlen(input); i++) {
        if (input[i] != ' ') {
            // Add character to word
            word[j] = input[i];
            j++;
        }
        else {
            // Add null terminator to word
            word[j] = '\0';
            // Calculate length of word and add to average length
            averageLength += strlen(word);
            // Reset word array and index
            memset(word, 0, sizeof(word));
            j = 0;
            // Increment word count
            wordCount++;
        }
    }
    // Add last word to average length calculation
    averageLength += strlen(word);
    // Calculate average length
    averageLength = averageLength / (float)(wordCount + 1);
    
    // Print results
    printf("Number of words: %d\n", wordCount + 1);
    printf("Average word length: %.2f\n", averageLength);
    
    return 0;
}