//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

// Function to check if a word is in the spam dictionary
bool isSpamWord(char words[MAX_WORDS][WORD_LENGTH], int numWords, char* word) {
    for (int i = 0; i < numWords; i++) {
        if (strcasecmp(words[i], word) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char input[1024];
    int numWords = 0;
    char words[MAX_WORDS][WORD_LENGTH];

    // Load spam dictionary
    FILE *fp = fopen("spam.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open spam dictionary file.\n");
        return 1;
    }

    char word[WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Spam dictionary too large.\n");
            fclose(fp);
            return 1;
        }
        strcpy(words[numWords++], word);
    }

    fclose(fp);

    // Read email message
    printf("Enter the email message:\n");
    fgets(input, sizeof(input), stdin);

    // Tokenize email message into words
    char *token = strtok(input, " .,\n:;");
    int numTokens = 0;
    char tokens[100][WORD_LENGTH];

    while (token != NULL) {
        if (numTokens >= 100) {
            printf("Error: Email message too long.\n");
            return 1;
        }
        strcpy(tokens[numTokens++], token);
        token = strtok(NULL, " .,\n:;");
    }

    // Check each word against spam dictionary
    int numSpamWords = 0;
    for (int i = 0; i < numTokens; i++) {
        if (isSpamWord(words, numWords, tokens[i])) {
            numSpamWords++;
        }
    }

    // Determine if email is spam based on number of spam words
    if (numSpamWords > 5) {
        printf("This email is likely spam.\n");
    } else {
        printf("This email is not likely spam.\n");
    }

    return 0;
}