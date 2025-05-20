//Falcon-180B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to read a file and return its content as a string
char* readFile(FILE* file) {
    char* content = NULL;
    size_t size = 0;

    // Get file size
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    // Allocate memory for file content
    content = malloc(size + 1);

    // Read file into memory
    fread(content, size, 1, file);
    content[size] = '\0';

    return content;
}

// Function to write content to a file
void writeFile(FILE* file, char* content) {
    fwrite(content, strlen(content), 1, file);
}

// Function to analyze file content and print statistics
void analyzeFile(char* content) {
    int numWords = countWords(content);
    int numSentences = 0;
    int avgWordLength = 0;

    // Count sentences
    char* sentence = strtok(content, ".");
    while (sentence!= NULL) {
        numSentences++;
        sentence = strtok(NULL, ".");
    }

    // Calculate average word length
    int wordCount = 0;
    char* word = strtok(content, " ");
    while (word!= NULL) {
        wordCount++;
        avgWordLength += strlen(word);
        word = strtok(NULL, " ");
    }
    avgWordLength /= wordCount;

    printf("Number of words: %d\n", numWords);
    printf("Number of sentences: %d\n", numSentences);
    printf("Average word length: %d\n", avgWordLength);
}

int main() {
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char* content = readFile(file);
    fclose(file);

    analyzeFile(content);

    free(content);
    return 0;
}