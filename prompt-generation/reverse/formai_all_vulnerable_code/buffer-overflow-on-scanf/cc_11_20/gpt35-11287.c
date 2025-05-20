//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100  // Maximum length of a word
#define MAX_WORDS 10000   // Maximum number of words in the file

int main() {
    char fileName[100];
    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    int wordFreq[MAX_WORDS];          // Array to store frequency of each word
    char words[MAX_WORDS][MAX_WORD_LEN];  // Array to store all words in the file
    int numWords = 0;                 // Number of words in the file

    while (!feof(fp) && numWords < MAX_WORDS) {
        char word[MAX_WORD_LEN];
        int i = 0;
        while (!feof(fp)) {
            char c = fgetc(fp);
            if (isalpha(c)) {  // If character is an alphabet
                if (i < MAX_WORD_LEN - 1) { // If word is not too long
                    word[i] = tolower(c);   // Convert to lower case and add to word
                    i++;
                }
            } else if (i > 0 || isdigit(c)) {  // If word has ended
                break;
            }
        }
        word[i] = '\0';  // Null-terminate the word
        if (i > 0) {  // If word is non-empty
            // Check if word is already in the list of words
            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(words[j], word) == 0) {
                    break;
                }
            }
            if (j < numWords) {  // If word is in the list of words
                wordFreq[j]++;  // Increment frequency of the word
            } else {  // If word is not in the list of words
                strcpy(words[numWords], word);  // Copy word to the list of words
                wordFreq[numWords] = 1;  // Set frequency of the word to 1
                numWords++;  // Increment number of words in the list
            }
        }
    }

    fclose(fp);

    // Sort words and their frequencies in descending order of frequency
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (wordFreq[i] < wordFreq[j] ||
                (wordFreq[i] == wordFreq[j] && strcmp(words[i], words[j]) > 0)) {
                int tempFreq = wordFreq[i];
                wordFreq[i] = wordFreq[j];
                wordFreq[j] = tempFreq;

                char tempWord[MAX_WORD_LEN];
                strcpy(tempWord, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tempWord);
            }
        }
    }

    // Print the top 10 words and their frequencies
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < numWords; i++) {
        printf("%d. %s: %d\n", i + 1, words[i], wordFreq[i]);
    }

    return 0;
}