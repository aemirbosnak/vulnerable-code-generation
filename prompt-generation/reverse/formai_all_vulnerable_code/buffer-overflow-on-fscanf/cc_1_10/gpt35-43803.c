//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// a struct to hold the word counts
struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

// a function to convert a string to lowercase
void toLowercase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

// a function to compare two strings ignoring case
int stricmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (tolower(s1[i]) != tolower(s2[i]))
            return (tolower(s1[i]) < tolower(s2[i])) ? -1 : 1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else
        return (s1[i] == '\0') ? -1 : 1;
}

int main(int argc, char *argv[]) {
    // check if the input file is provided
    if (argc < 2) {
        printf("Usage: %s input_file_name\n", argv[0]);
        return 1;
    }
    // open the input file
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Cannot open input file: %s\n", argv[1]);
        return 2;
    }
    // read the input file word by word
    char word[MAX_WORD_LENGTH] = "";
    struct WordCount wordCounts[1000];
    int wordCount = 0;
    while (fscanf(inputFile, "%s", word) != EOF) {
        // convert the word to lowercase
        toLowercase(word);
        // check if the word already exists in the wordCounts array
        int i;
        for (i = 0; i < wordCount; i++) {
            if (stricmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        // if the word does not exist, add it to the wordCounts array
        if (i == wordCount) {
            strncpy(wordCounts[wordCount].word, word, strlen(word) + 1);
            wordCounts[wordCount].count = 1;
            wordCount++;
        }
    }
    // close the input file
    fclose(inputFile);
    // print the word count results
    printf("Word Counts:\n");
    int totalWordCount = 0;
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        totalWordCount += wordCounts[i].count;
    }
    printf("Total Words: %d\n", totalWordCount);
    return 0;
}