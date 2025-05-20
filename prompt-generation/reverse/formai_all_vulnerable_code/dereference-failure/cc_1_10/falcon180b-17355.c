//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024 // Maximum length of a line in the file
#define MAX_WORD_SIZE 50 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compareWords(const void *word1, const void *word2) {
    return strcmp(*(char **)word1, *(char **)word2);
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char *word;
    char *end;
    int lineNumber = 0;
    int totalWords = 0;

    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        lineNumber++;

        // Remove any trailing newline character
        end = line + strlen(line) - 1;
        if (*end == '\n') {
            *end = '\0';
        }

        // Count the total number of words in the file
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            totalWords++;
            word = strtok(NULL, ",.!?;:");
        }

        // Count the frequency of each word in the file
        WordCount words[MAX_WORD_SIZE];
        memset(words, 0, sizeof(WordCount) * MAX_WORD_SIZE);
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            int index = 0;
            while (index < totalWords && strcmp(word, words[index].word)!= 0) {
                index++;
            }
            if (index == totalWords) {
                if (index == MAX_WORD_SIZE) {
                    printf("Error: Too many unique words in the file.\n");
                    return 1;
                }
                strcpy(words[index].word, word);
                words[index].count = 1;
            } else {
                words[index].count++;
            }
            word = strtok(NULL, ",.!?;:");
        }

        // Sort the words by frequency
        qsort(words, totalWords, sizeof(WordCount), compareWords);

        // Print the word count and frequency for each word
        printf("Line %d: ", lineNumber);
        for (int i = 0; i < totalWords; i++) {
            printf("%s (%d): %s\n", words[i].word, words[i].count, words[i].word);
        }
        printf("\n");
    }

    // Close the file
    fclose(file);
    return 0;
}