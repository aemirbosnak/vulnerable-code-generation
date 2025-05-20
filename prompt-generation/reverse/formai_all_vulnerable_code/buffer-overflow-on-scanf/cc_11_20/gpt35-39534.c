//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// define the maximum length of a word
#define MAX_WORD_LENGTH 100

// define the maximum number of words
#define MAX_NUM_WORDS 5000

// define the struct to keep track of each word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

int main() {
    // create an array to store each Word struct
    Word words[MAX_NUM_WORDS];
    int numWords = 0;

    // create an array to keep track of which words have already been added
    int added[MAX_NUM_WORDS] = {0};

    // read in the text from a file
    FILE *fp;
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open the file.\n");
        exit(1);
    }

    char currentWord[MAX_WORD_LENGTH];
    char c;
    int i = 0;
    int wordLength = 0;

    // read in each character and build up words
    while ((c = fgetc(fp)) != EOF) {
        // if the character is a letter or a hyphen, add it to the current word
        if (isalpha(c) || c == '-') {
            currentWord[i] = tolower(c);
            i++;
        // if the character is a space or a newline, finish the word
        } else if (isspace(c) || c == '\n') {
            // ensure the word is not too long
            if (i > MAX_WORD_LENGTH - 1) {
                printf("The word %s is too long and has been skipped.\n", currentWord);
                i = 0;
                continue;
            }
            currentWord[i] = '\0';
            i = 0;

            // check if the word has already been added, if so, increase its frequency
            int alreadyAdded = 0;
            for (int j = 0; j < numWords; j++) {
                if (strcmp(words[j].word, currentWord) == 0) {
                    words[j].frequency++;
                    alreadyAdded = 1;
                    break;
                }
            }

            // if the word has not already been added, create a new Word struct for it
            if (!alreadyAdded) {
                strcpy(words[numWords].word, currentWord);
                words[numWords].frequency = 1;
                numWords++;
            }
        }
    }

    // close the file
    fclose(fp);

    // output the results
    printf("\nFrequency of words in file %s:\n", filename);
    for (int i = 0; i < numWords; i++) {
        int maxFrequency = -1;
        int maxIndex = -1;
        for (int j = 0; j < numWords; j++) {
            if (words[j].frequency > maxFrequency && !added[j]) {
                maxFrequency = words[j].frequency;
                maxIndex = j;
            }
        }
        if (maxIndex != -1) {
            printf("%s: %d\n", words[maxIndex].word, maxFrequency);
            added[maxIndex] = 1;
        }
    }

    return 0;
}