//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is spelled correctly
int spellCheck(char* word, char* dictFile) {
    FILE* fp;
    char line[256];
    int found = 0;

    // Open dictionary file
    fp = fopen(dictFile, "r");

    // Check each line in the dictionary if it matches the word
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, word) == 0) {
            found = 1;
            break;
        }
    }

    // Close dictionary file
    fclose(fp);

    return found;
}

int main() {
    char sentence[256], word[256];
    char dictFile[256];
    int i, j, wordStart, len, correct;
    char c;

    // Prompt user to enter a sentence to be spell checked and the name of the dictionary file
    printf("Enter a sentence to be spell checked:\n");
    fgets(sentence, sizeof(sentence), stdin);
    printf("Enter the name of the dictionary file:\n");
    scanf("%s", dictFile);

    // Check each word in the sentence
    i = 0;
    while (sentence[i] != '\0') {
        // If current character is a letter, start of a new word
        if (isalpha(sentence[i])) {
            wordStart = i;
            len = 0;

            // Get the length of the word
            while (isalpha(sentence[i])) {
                word[len] = sentence[i];
                len++;
                i++;
            }

            // Add null terminator to the end of the word
            word[len] = '\0';

            // Check if the word is spelled correctly
            correct = spellCheck(word, dictFile);

            // If word is spelled incorrectly, print it out
            if (!correct) {
                printf("Misspelled word: %s\n", word);
            }

        }
        i++;
    }

    return 0;
}