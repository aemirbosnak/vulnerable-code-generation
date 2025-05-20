//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SPAM_WORDS     1000
#define MAX_WORD_LENGTH    100

// Spam word list
static char *spamWords[MAX_SPAM_WORDS];

// Number of spam words in the list
static int numSpamWords = 0;

// Initialize the spam word list
void initSpamWordList() {
    // Open the spam word list file
    FILE *fp = fopen("spamWords.txt", "r");
    if (fp == NULL) {
        perror("Error opening spam word list file");
        exit(EXIT_FAILURE);
    }

    // Read the spam words from the file
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        // Remove the newline character from the word
        line[strlen(line) - 1] = '\0';

        // Add the word to the spam word list
        spamWords[numSpamWords++] = strdup(line);
    }

    // Close the spam word list file
    fclose(fp);
}

// Check if a word is in the spam word list
int isSpamWord(char *word) {
    // Convert the word to lowercase
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the spam word list
    for (int i = 0; i < numSpamWords; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1;
        }
    }

    // The word is not in the spam word list
    return 0;
}

// Calculate the spam score of a message
int calculateSpamScore(char *message) {
    // Convert the message to lowercase
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = tolower(message[i]);
    }

    // Tokenize the message
    char *tokens[MAX_SPAM_WORDS];
    int numTokens = 0;
    char *token = strtok(message, " ");
    while (token != NULL) {
        tokens[numTokens++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the spam score
    int spamScore = 0;
    for (int i = 0; i < numTokens; i++) {
        if (isSpamWord(tokens[i])) {
            spamScore += 1;
        }
    }

    // Return the spam score
    return spamScore;
}

// Classify a message as spam or not spam
int classifyMessage(char *message) {
    // Calculate the spam score of the message
    int spamScore = calculateSpamScore(message);

    // Classify the message as spam or not spam
    if (spamScore > 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize the spam word list
    initSpamWordList();

    // Get the message from the user
    char message[1024];
    printf("Enter your message: ");
    gets(message);

    // Classify the message as spam or not spam
    int isSpam = classifyMessage(message);

    // Print the result
    if (isSpam) {
        printf("Your message is spam.\n");
    } else {
        printf("Your message is not spam.\n");
    }

    // Return 0 to indicate success
    return 0;
}