//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function to convert a string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to remove punctuation from a word
void removePunctuation(char *word) {
    char temp[MAX_WORD_LENGTH];
    int j = 0;
    for (int i = 0; word[i]; i++) {
        if (isalpha(word[i])) { // Check if the character is an alphabet
            temp[j++] = word[i];
        }
    }
    temp[j] = '\0'; // Null-terminate the cleaned word
    strcpy(word, temp);
}

// Function to count words in a line and calculate frequency
void processLine(char *line, char words[MAX_WORDS][MAX_WORD_LENGTH], int *wordCount) {
    char *token = strtok(line, " \n");
    
    while (token != NULL) {
        removePunctuation(token);
        if (strlen(token) > 0) { // Only consider non-empty words
            toLowerCase(token);
            strcpy(words[*wordCount], token); // Store the word
            (*wordCount)++;
        }
        token = strtok(NULL, " \n");
    }
}

// Function to find the most frequent word
void findMostFrequentWord(char words[MAX_WORDS][MAX_WORD_LENGTH], int wordCount) {
    int maxCount = 0;
    char mostFrequent[MAX_WORD_LENGTH];
    for (int i = 0; i < wordCount; i++) {
        int count = 1;
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            strcpy(mostFrequent, words[i]);
        }
    }
    if (maxCount > 1) {
        printf("Most frequent word: '%s' (occurs %d times)\n", mostFrequent, maxCount);
    } else {
        printf("No repeating words.\n");
    }
}

int main() {
    FILE *file;
    char filename[100];
    char line[256];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;
    int lineCount = 0, charCount = 0;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r"); // Open the specified file

    if (file == NULL) { // Check for file open error
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        lineCount++; // Count lines
        charCount += strlen(line); // Count characters

        processLine(line, words, &wordCount); // Process the line to count words
    }

    fclose(file); // Close the file

    printf("Total lines: %d\n", lineCount);
    printf("Total characters: %d\n", charCount);
    printf("Total words: %d\n", wordCount);

    findMostFrequentWord(words, wordCount); // Find the most frequent word

    return EXIT_SUCCESS;
}