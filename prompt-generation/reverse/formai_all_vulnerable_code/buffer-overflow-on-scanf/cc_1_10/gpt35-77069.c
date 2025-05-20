//FormAI DATASET v1.0 Category: Text Summarizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CHARACTERS 1000
#define MAX_SUMMARY 100

typedef struct wordSummary {
    char word[20];
    int frequency;
} WordSummary;

void strToLower(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

void sortSummary(WordSummary* summary, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            if (summary[i].frequency < summary[j].frequency) {
                WordSummary temp = summary[i];
                summary[i] = summary[j];
                summary[j] = temp;
            }
        }
    }
}

int countWords(char* text) {
    int totalCount = 0;
    char* token = strtok(text, " ");
    
    while (token != NULL) {
        totalCount++;
        token = strtok(NULL, " ");
    }
    
    return totalCount;
}

bool isDuplicate(WordSummary* summary, int len, char* word) {
    for (int i = 0; i < len; i++) {
        if (strcmp(summary[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

void addToSummary(WordSummary* summary, int* len, char* word) {
    for (int i = 0; i < *len; i++) {
        if (strcmp(summary[i].word, word) == 0) {
            summary[i].frequency++;
            return;
        }
    }
    
    strcpy(summary[*len].word, word);
    summary[*len].frequency = 1;
    (*len)++;
}

void generateSummary(char* text, int totalWords, int desiredSummaryLength) {
    WordSummary summary[MAX_CHARACTERS/2];
    int summaryLength = 0;
    
    char* token = strtok(text, " ");
    
    while (token != NULL) {
        strToLower(token);
        
        if (!isDuplicate(summary, summaryLength, token)) {
            addToSummary(summary, &summaryLength, token);
        }
        
        token = strtok(NULL, " ");
    }
    
    sortSummary(summary, summaryLength);
    printf("Here is your summary of %d words:\n", desiredSummaryLength);
    
    int wordsAdded = 0, i = 0;
    while (wordsAdded < desiredSummaryLength && i < summaryLength) {
        if (strlen(summary[i].word) > 1) {
            printf("%s ", summary[i].word);
            wordsAdded++;
        }
        i++;
    }
    
    printf("\n");
}

void readFile(char* filename, char* text) {
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }
    
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (i >= MAX_CHARACTERS-1) break;
        text[i] = c;
        i++;
    }
    text[i] = '\0';
    fclose(fp);
}

int main() {
    char text[MAX_CHARACTERS];
    char filename[50];
    printf("Enter filename to read: ");
    scanf("%s", filename);
    
    readFile(filename, text);
    
    int totalWords = countWords(text);
    int desiredSummaryLength;
    
    printf("Enter the number of words desired in summary: ");
    scanf("%d", &desiredSummaryLength);
    
    generateSummary(text, totalWords, desiredSummaryLength);
    
    return 0;
}