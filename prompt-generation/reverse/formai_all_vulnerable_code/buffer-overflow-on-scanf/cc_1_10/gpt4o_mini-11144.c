//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 10000

// Structure to hold word counts
typedef struct {
    char word[50];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || 
           ch == ',' || ch == '.' || ch == '!' || 
           ch == '?' || ch == ';' || ch == ':'; 
}

int addWord(WordCount *wordCounts, int *totalWords, const char *word) {
    for (int i = 0; i < *totalWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return 0; // Word found; incremented count
        }
    }

    // If not found, add new word
    strcpy(wordCounts[*totalWords].word, word);
    wordCounts[*totalWords].count = 1;
    (*totalWords)++;
    return 1; // Word added
}

void printWordCounts(WordCount *wordCounts, int totalWords) {
    printf("Word Count Results:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void freeWordCounts(WordCount *wordCounts) {
    free(wordCounts);
}

int main() {
    FILE *file;
    char filename[100];
    char line[MAX_LINE_LENGTH];
    
    printf("Enter the filename to count words from: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount *wordCounts = (WordCount *)malloc(sizeof(WordCount) * MAX_WORDS);
    if (wordCounts == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    int totalWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            char cleanedWord[50];
            int j = 0;

            // Clean and lower the token
            for (int i = 0; token[i]; i++) {
                if (!isDelimiter(token[i])) {
                    cleanedWord[j++] = token[i];
                }
            }
            cleanedWord[j] = '\0';
            toLowerCase(cleanedWord);

            // Only add non-empty words
            if (strlen(cleanedWord) > 0) {
                addWord(wordCounts, &totalWords, cleanedWord);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    printWordCounts(wordCounts, totalWords);
    freeWordCounts(wordCounts);

    return EXIT_SUCCESS;
}