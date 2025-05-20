//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: creative
// Welcome to the Spam Hunter Command Center!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the threshold for spamminess
#define SPAM_THRESHOLD 0.75

// Define the list of spammy words
char *spammyWords[] = {
    "free", "offer", "discount", "sale", "click", "subscribe",
    "win", "prize", "urgent", "limited time", "act now"
};

// Define the function to calculate the spamminess of a given text
double calculateSpamminess(char *text) {
    // Count the number of spammy words in the text
    int spammyWordCount = 0;
    for (int i = 0; i < strlen(spammyWords); i++) {
        if (strstr(text, spammyWords[i]) != NULL) {
            spammyWordCount++;
        }
    }

    // Calculate the spamminess of the text
    double spamminess = (double) spammyWordCount / (double) strlen(text);

    // Return the spamminess
    return spamminess;
}

// Define the main function
int main() {
    // Get the text to check for spam
    char text[1024];
    printf("Enter the text to check for spam: ");
    gets(text);

    // Calculate the spamminess of the text
    double spamminess = calculateSpamminess(text);

    // Print the results
    if (spamminess >= SPAM_THRESHOLD) {
        printf("*** Warning: This text is highly likely to be spam! ***\n");
    } else {
        printf("This text is not likely to be spam.\n");
    }

    return 0;
}