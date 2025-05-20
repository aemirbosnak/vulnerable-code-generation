//Falcon-180B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

// Function to count number of words in a line
int countWords(char *line) {
    int count = 0;
    char *token;
    token = strtok(line, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to print frequency of words in a file
void printFrequency(char *filename, int *wordCounts) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *word;
    int i;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            i = 0;
            while (i < 26 && wordCounts[i]!= 0) {
                i++;
            }
            if (i == 26) {
                printf("All 26 letters are already used.\n");
                exit(1);
            }
            wordCounts[i]++;
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);
}

// Function to sort words in alphabetical order
void sortWords(char *filename, int *wordCounts) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *word;
    int i;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            i = 0;
            while (i < 26 && wordCounts[i]!= 0) {
                i++;
            }
            if (i == 26) {
                printf("All 26 letters are already used.\n");
                exit(1);
            }
            wordCounts[i]++;
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    int wordCounts[26] = { 0 };
    printFrequency(filename, wordCounts);
    sortWords(filename, wordCounts);
    printf("Sorted frequency:\n");
    for (int i = 0; i < 26; i++) {
        if (wordCounts[i]!= 0) {
            printf("%c: %d\n", i + 'a', wordCounts[i]);
        }
    }
    return 0;
}