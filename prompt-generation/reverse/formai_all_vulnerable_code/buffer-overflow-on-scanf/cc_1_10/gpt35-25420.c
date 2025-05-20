//FormAI DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define variables
    char email[100];
    int numLinks = 0;
    int numWords = 0;
    int numSpam = 0;

    // Get user input
    printf("Enter an email to check for spam: ");
    scanf("%s", email);

    // Check for spam links
    char *spamLinks[] = {"click here", "buy now", "limited offer", "viagra", "free money"};
    for (int i = 0; i < sizeof(spamLinks)/sizeof(spamLinks[0]); i++) {
        if (strstr(email, spamLinks[i]) != NULL) {
            numLinks++;
        }
    }

    // Check for spam words
    char *spamWords[] = {"enlarge", "discount", "earn", "million", "prize"};
    char *word = strtok(email, " ");
    while (word != NULL) {
        for (int i = 0; i < sizeof(spamWords)/sizeof(spamWords[0]); i++) {
            if (strcmp(word, spamWords[i]) == 0) {
                numWords++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Determine if email is spam
    if (numLinks >= 2 || numWords >= 3) {
        numSpam++;
    }

    // Print results
    printf("Number of spam links found: %d\n", numLinks);
    printf("Number of spam words found: %d\n", numWords);
    if (numSpam > 0) {
        printf("This email is classified as spam.\n");
    } else {
        printf("This email is not classified as spam.\n");
    }

    return 0;
}