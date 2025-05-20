//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
// Romeo and Juliet inspired C Text Summarizer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find frequency of each word in the input string
void wordFrequency(char* input, int* freq, char** words, int* totalWords) {
    char* word = strtok(input, " \n\t");
    int index;

    while (word != NULL) {
        index = -1;

        // check if the word already exists in the array
        for (int i = 0; i < *totalWords; i++) {
            if (strcmp(words[i], word) == 0) {
                index = i;
                break;
            }
        }
        
        // if the word doesn't exist, add it to the array
        if (index == -1) {
            index = *totalWords;
            words[index] = (char*) malloc(strlen(word) + 1);
            strcpy(words[index], word);
            (*totalWords)++;
        }

        freq[index]++;
        word = strtok(NULL, " \n\t");
    }
}

// Function to summarize the text by selecting the most frequent words
void summarizeText(char* text, int percentage) {
    int freq[1000] = {0};
    char* words[1000] = {NULL};
    int totalWords = 0;

    // count the frequency of each word in the input string
    wordFrequency(text, freq, words, &totalWords);

    // calculate the number of words to keep based on the percentage parameter
    int numWords = strlen(text) * percentage / 100;
    int currentWords = 0;
    int maxFreqIndex = 0;
    
    // keep adding the word with the highest frequency until the word limit is reached
    while (currentWords < numWords && currentWords < totalWords) {
        for (int i = 0; i < totalWords; i++) {
            if (freq[i] > freq[maxFreqIndex]) {
                maxFreqIndex = i;
            }
        }

        printf("%s ", words[maxFreqIndex]);
        currentWords += strlen(words[maxFreqIndex]) + 1;
        freq[maxFreqIndex] = 0;
    }
}

int main() {
    char text[10000];
    printf("Enter the text to be summarized:\n");
    fgets(text, 10000, stdin);

    int percentage;
    printf("\nEnter the percentage of words to keep (integer value): ");
    scanf("%d", &percentage);

    // remove newline character from the input buffer
    getchar();

    printf("\n\nThe summarized text is:\n");
    summarizeText(text, percentage);

    return 0;
}