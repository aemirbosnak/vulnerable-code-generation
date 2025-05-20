//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of words in a sentence
int countWords(char* sentence) {
    int count = 0;
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count the number of sentences in a paragraph
int countSentences(char* paragraph) {
    int count = 0;
    char* sentence = strtok(paragraph, ".");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// Function to count the number of paragraphs in a text file
int countParagraphs(FILE* file) {
    int count = 0;
    char line[256];
    while (fgets(line, 256, file)!= NULL) {
        if (line[strlen(line) - 1] == '.') {
            count++;
        }
    }
    return count;
}

// Function to print the analysis results
void printAnalysis(int wordCount, int sentenceCount, int paragraphCount) {
    printf("Word count: %d\n", wordCount);
    printf("Sentence count: %d\n", sentenceCount);
    printf("Paragraph count: %d\n", paragraphCount);
}

int main() {
    char filename[256];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Count the number of words, sentences, and paragraphs
    int wordCount = 0;
    int sentenceCount = 0;
    int paragraphCount = 0;
    char line[256];
    while (fgets(line, 256, file)!= NULL) {
        wordCount += countWords(line);
        sentenceCount += countSentences(line);
        if (line[strlen(line) - 1] == '.') {
            paragraphCount++;
        }
    }

    // Print the analysis results
    printAnalysis(wordCount, sentenceCount, paragraphCount);

    // Close the file
    fclose(file);
    return 0;
}