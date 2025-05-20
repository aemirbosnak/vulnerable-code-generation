//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: immersive
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

void loadWords(char* filename, WordCount words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                found = 1;
                words[j].count++;
                break;
            }
        }
        if (!found) {
            strcpy(words[j].word, word);
            words[j].count = 1;
            j++;
        }
    }

    fclose(file);
}

void printWords(WordCount words[], int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    char* inputFile = argv[1];
    char* outputFile = argv[2];

    WordCount words[MAX_WORDS];
    loadWords(inputFile, words);

    FILE* outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        printf("Error: Unable to open file %s\n", outputFile);
        exit(1);
    }

    printWords(words, MAX_WORDS);

    fclose(outFile);

    return 0;
}