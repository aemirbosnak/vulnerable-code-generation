//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char ch, line[1000];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, sizeof(line), file)!= NULL) {
        int len = strlen(line);

        // Remove newline character
        line[len-1] = '\0';

        // Convert all characters to lowercase
        for (int i = 0; i < len; i++) {
            ch = tolower(line[i]);
            line[i] = ch;
        }

        // Split line into words
        char *token = strtok(line, ",.?!");
        while (token!= NULL) {
            int wordLen = strlen(token);

            // Check if word is already in array
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            // Add new word to array
            if (!found) {
                strncpy(words[numWords].word, token, MAX_WORD_LEN-1);
                words[numWords].word[MAX_WORD_LEN-1] = '\0';
                words[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, ",.?!");
        }
    }

    // Sort array by word frequency
    qsort(words, numWords, sizeof(WordCount), compare);

    // Print results
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}