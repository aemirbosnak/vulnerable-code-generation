//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 1000

// Function to count the number of words in a sentence
int countWords(char sentence[]) {
    int count = 0;
    char *token;

    // Tokenize the sentence
    token = strtok(sentence, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to count the number of sentences in a paragraph
int countSentences(char paragraph[]) {
    int count = 0;
    char *token;

    // Tokenize the paragraph
    token = strtok(paragraph, ".");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, ".");
    }

    return count;
}

// Function to count the number of words and sentences in a text file
void countWordsAndSentences(FILE *file) {
    char sentence[MAX_WORD_LENGTH];
    int sentenceCount = 0;
    int wordCount = 0;

    while (fgets(sentence, MAX_WORD_LENGTH, file)!= NULL) {
        sentenceCount++;

        // Count the number of words in the sentence
        int wordsInSentence = countWords(sentence);
        wordCount += wordsInSentence;

        // Print the sentence and word count
        printf("Sentence %d: %s (%d words)\n", sentenceCount, sentence, wordsInSentence);
    }

    // Print the total word count
    printf("Total word count: %d\n", wordCount);
}

int main() {
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    countWordsAndSentences(file);

    fclose(file);
    return 0;
}