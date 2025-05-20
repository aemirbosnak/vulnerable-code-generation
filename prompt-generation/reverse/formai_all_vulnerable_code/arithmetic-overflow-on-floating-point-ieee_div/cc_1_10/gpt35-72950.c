//FormAI DATASET v1.0 Category: Text Summarizer ; Style: post-apocalyptic
/* Post-Apocalyptic Text Summarizer */

#include <stdio.h>
#include <string.h>

int main() {
    // Introduce the program to the user
    printf("Welcome to the Post-Apocalyptic Text Summarizer!\n");
    printf("Enter your text below to receive a summarized version.\n");

    // Get user input
    char input[1000];
    fgets(input, 1000, stdin);

    // Remove punctuation marks
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?') {
            input[i] = ' ';
        }
    }

    // Split input into words
    char *word = strtok(input, " ");

    // Initialize variables
    int wordCount = 0;
    int sentenceCount = 0;
    int paragraphCount = 1;

    while (word != NULL) {
        wordCount++;

        // Check for end of sentence
        if (word[strlen(word) - 1] == '.') {
            sentenceCount++;
        }

        // Check for end of paragraph
        if (wordCount % 50 == 0) {
            paragraphCount++;
        }

        word = strtok(NULL, " ");
    }

    // Calculate summary statistics
    double avgWordsPerSentence = (double) wordCount / (double) sentenceCount;
    double avgSentencesPerParagraph = (double) sentenceCount / (double) paragraphCount;

    // Print summary statistics
    printf("\nSUMMARY STATISTICS:\n");
    printf("Number of words: %d\n", wordCount);
    printf("Number of sentences: %d\n", sentenceCount);
    printf("Number of paragraphs: %d\n", paragraphCount);
    printf("Average words per sentence: %.2f\n", avgWordsPerSentence);
    printf("Average sentences per paragraph: %.2f\n", avgSentencesPerParagraph);

    // End program
    printf("\nThank you for using the Post-Apocalyptic Text Summarizer!");
    return 0;
}