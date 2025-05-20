//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void CountWords(char* line, int* wordCount, WordCount words[]) {
    char* word = strtok(line, ",.?!;:");
    while (word!= NULL) {
        int index = 0;
        while (index < *wordCount && strcmp(words[index].word, word)!= 0) {
            index++;
        }
        if (index == *wordCount) {
            strcpy(words[*wordCount].word, word);
            (*wordCount)++;
        }
        word = strtok(NULL, ",.?!;:");
    }
}

void WriteWords(FILE* file, WordCount words[], int wordCount) {
    fprintf(file, "Total Words: %d\n", wordCount);
    fprintf(file, "Word\tCount\n");
    for (int i = 0; i < wordCount; i++) {
        fprintf(file, "%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* inputFile = NULL;
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", fileName);
    inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Error opening file: %s\n", fileName);
        return 1;
    }

    int wordCount = 0;
    WordCount words[MAX_WORD_LENGTH];

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        CountWords(line, &wordCount, words);
    }

    fclose(inputFile);

    FILE* outputFile = fopen("word_count.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating output file: word_count.txt\n");
        return 1;
    }

    WriteWords(outputFile, words, wordCount);

    fclose(outputFile);

    return 0;
}