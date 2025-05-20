//Falcon-180B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE 1000000
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_LINE_SIZE];
    int count;
} WordCount;

int main() {
    char filename[MAX_LINE_SIZE];
    FILE *file;
    char line[MAX_LINE_SIZE];
    WordCount words[MAX_WORD_COUNT];
    int numWords = 0;
    int i, j;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        numWords = 0;
        char *token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            if (numWords >= MAX_WORD_COUNT) {
                printf("Error: too many words in file.\n");
                fclose(file);
                return 2;
            }
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    fclose(file);

    printf("Enter word to search for: ");
    scanf("%s", filename);

    for (i = 0; i < numWords; i++) {
        if (strcmp(filename, words[i].word) == 0) {
            printf("%s appears %d times in the file.\n", filename, words[i].count);
        }
    }

    return 0;
}