//Falcon-180B DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    char filename[MAX_FILE_SIZE];
    FILE* file;
    WordCount words[26];
} FileData;

void initWords(WordCount* words) {
    for (int i = 0; i < 26; i++) {
        strcpy(words[i].word, "");
        words[i].count = 0;
    }
}

int isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void readFile(FileData* fileData) {
    char ch;
    int index = 0;
    while ((ch = fgetc(fileData->file))!= EOF) {
        if (isAlpha(ch)) {
            if (index >= 26) {
                printf("Error: Too many unique words.\n");
                exit(1);
            }
            char* word = &(fileData->words[index].word[0]);
            while (isAlpha(ch)) {
                *word++ = tolower(ch);
                ch = fgetc(fileData->file);
            }
            *word = '\0';
            fileData->words[index].count++;
        } else {
            index++;
        }
    }
    fclose(fileData->file);
}

void printWords(WordCount* words) {
    for (int i = 0; i < 26; i++) {
        if (words[i].count > 0) {
            printf("%c: %s (%d)\n", i + 'a', words[i].word, words[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FileData fileData;
    strcpy(fileData.filename, argv[1]);
    fileData.file = fopen(fileData.filename, "r");

    if (fileData.file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    initWords(fileData.words);
    readFile(&fileData);
    printWords(fileData.words);

    return 0;
}