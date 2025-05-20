//Falcon-180B DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to count number of words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

int main() {
    FILE* inputFile;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int totalWords = 0;
    
    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);
    
    // Open file
    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        lineNumber++;
        int wordsInLine = countWords(line);
        totalWords += wordsInLine;
        
        // Print line number and number of words in line
        printf("%d: %d words\n", lineNumber, wordsInLine);
    }
    
    // Close file
    fclose(inputFile);
    
    // Print total number of words in file
    printf("\nTotal words: %d\n", totalWords);
    
    return 0;
}