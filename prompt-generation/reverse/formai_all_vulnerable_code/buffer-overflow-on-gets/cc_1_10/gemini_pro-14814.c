//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Spam Detection Threshold
#define SPAM_THRESHOLD 0.8

// Keywords Associated with Spam
char *spamKeywords[] = {
    "Viagra", "Casino", "Lottery", "Weight Loss", "Cheap Rolex"
};

// Initialize the Keyword Counts
int keywordCounts[5] = {0, 0, 0, 0, 0};

// Function to Check for Spam Keywords
int checkForKeywords(char *message) {
    int numKeywordsFound = 0;
    for (int i = 0; i < 5; i++) {
        if (strstr(message, spamKeywords[i]) != NULL) {
            numKeywordsFound++;
            keywordCounts[i]++;
        }
    }
    return numKeywordsFound;
}

// Function to Calculate Spam Probability
double calculateSpamProbability(int numKeywordsFound) {
    return (double)numKeywordsFound / 5;
}

// Function to Determine Spam
int determineSpam(double spamProbability) {
    return spamProbability >= SPAM_THRESHOLD;
}

// Main Function to Receive and Analyze Input
int main() {
    // Welcome the User
    printf("Welcome to the Spam Detection System!\n");

    // Get the Input Message
    char message[256];
    printf("Enter the email message: ");
    gets(message);

    // Check for Spam Keywords
    int numKeywordsFound = checkForKeywords(message);

    // Calculate Spam Probability
    double spamProbability = calculateSpamProbability(numKeywordsFound);

    // Determine Spam
    int isSpam = determineSpam(spamProbability);

    // Display the Results
    printf("Number of Keywords Found: %d\n", numKeywordsFound);
    printf("Spam Probability: %.2f\n", spamProbability);
    printf("Spam: %s\n", isSpam ? "Yes" : "No");

    // Reveal the Spy Network
    printf("\nSecret Spy Report:\n");
    for (int i = 0; i < 5; i++) {
        printf("- Keyword %s: Found %d times\n", spamKeywords[i], keywordCounts[i]);
    }

    return 0;
}