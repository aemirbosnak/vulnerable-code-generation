//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main() {
    // Create an array of words to store the spam words
    Word spamWords[MAX_WORDS];
    int numSpamWords = 0;

    // Open the spam words file
    FILE *spamFile = fopen("spam.txt", "r");
    if (spamFile == NULL) {
        perror("Error opening spam words file");
        return EXIT_FAILURE;
    }

    // Read the spam words from the file
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, spamFile) != NULL) {
        // Remove the newline character from the word
        line[strlen(line) - 1] = '\0';

        // Allocate memory for the word
        spamWords[numSpamWords].word = malloc(strlen(line) + 1);
        if (spamWords[numSpamWords].word == NULL) {
            perror("Error allocating memory for spam word");
            return EXIT_FAILURE;
        }

        // Copy the word into the array
        strcpy(spamWords[numSpamWords].word, line);

        // Increment the number of spam words
        numSpamWords++;
    }

    // Close the spam words file
    fclose(spamFile);

    // Sort the spam words in alphabetical order
    qsort(spamWords, numSpamWords, sizeof(Word), compareWords);

    // Open the email file
    FILE *emailFile = fopen("email.txt", "r");
    if (emailFile == NULL) {
        perror("Error opening email file");
        return EXIT_FAILURE;
    }

    // Read the email text
    char emailText[10000];
    fread(emailText, 1, 10000, emailFile);

    // Close the email file
    fclose(emailFile);

    // Tokenize the email text into words
    char *words[MAX_WORDS];
    int numWords = 0;
    char *token = strtok(emailText, " ");
    while (token != NULL) {
        words[numWords] = token;
        numWords++;
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each spam word in the email text
    int spamWordCounts[MAX_WORDS];
    for (int i = 0; i < numSpamWords; i++) {
        spamWordCounts[i] = 0;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(spamWords[i].word, words[j]) == 0) {
                spamWordCounts[i]++;
            }
        }
    }

    // Calculate the spam score for the email
    int spamScore = 0;
    for (int i = 0; i < numSpamWords; i++) {
        spamScore += spamWordCounts[i] * spamWords[i].count;
    }

    // Print the spam score
    printf("Spam score: %d\n", spamScore);

    // Free the memory allocated for the spam words
    for (int i = 0; i < numSpamWords; i++) {
        free(spamWords[i].word);
    }

    return EXIT_SUCCESS;
}