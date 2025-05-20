//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_CHAR 100

typedef struct {
    char word[MAX_CHAR];
    int count;
} WordCount;

void readWords(FILE* fp, WordCount words[]) {
    char line[MAX_CHAR];
    char* token;
    int count = 0;

    while (fgets(line, MAX_CHAR, fp)!= NULL) {
        token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            strcpy(words[count].word, token);
            words[count].count++;
            count++;

            token = strtok(NULL, ",.?!;:");
        }
    }
}

void sortWords(WordCount words[], int n) {
    int i, j;
    WordCount temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (words[i].count < words[j].count) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordCount words[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* fp;
    char filename[MAX_CHAR];
    WordCount words[MAX_WORDS];
    int n;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    readWords(fp, words);
    fclose(fp);

    n = 0;
    while (words[n].count == 0) {
        n++;
    }

    sortWords(words, n);
    printWords(words, n);

    return 0;
}