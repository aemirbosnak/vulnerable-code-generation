//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50   // Maximum word length
#define MAX_WORDS 10000      // Maximum number of unique words to store
#define MAX_OCCURRENCES 100  // Maximum number of occurrences of a word

#define TRUE 1
#define FALSE 0

// Word struct to store word and its occurrence count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Function to check if the word is already in the words array
int word_exists(char* word, Word* words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Array of words and their occurrence count
    Word words[MAX_WORDS];

    int num_words = 0;

    char c;
    char word[MAX_WORD_LENGTH] = "";
    int word_index = 0;
    int in_word = FALSE;

    // Read characters from file and convert them to lowercase
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            in_word = TRUE;
            // Convert character to lowercase and add to word
            word[word_index++] = tolower(c);
        } else {
            if (in_word) {
                // Terminate the word and reset index
                word[word_index] = '\0';
                word_index = 0;

                // Check if word already exists
                int index = word_exists(word, words, num_words);
                if (index == -1) {
                    // Add new word to the array
                    strcpy(words[num_words].word, word);
                    words[num_words++].count = 1;
                } else {
                    // Increment occurrence count of existing word
                    words[index].count++;
                }

                in_word = FALSE;
            }
        }
    }

    fclose(fp);

    // Sort words array in descending order of occurrence count
    int i, j;
    Word temp;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[i].count < words[j].count) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print top 10 words by occurrence count
    printf("Top 10 words by frequency:\n");
    for (i = 0; i < 10 && i < num_words; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    return 0;
}