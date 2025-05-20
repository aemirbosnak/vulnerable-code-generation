//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000
#define MAX_NUM_WORDS 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int main(int argc, char* argv[]) {
    FILE* file = NULL;
    char line[MAX_LINE_SIZE];
    int numWords = 0;
    WordCount* wordCounts = (WordCount*)malloc(MAX_NUM_WORDS * sizeof(WordCount));
    memset(wordCounts, 0, MAX_NUM_WORDS * sizeof(WordCount));

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 2;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char* word = strtok(line, " \t\r\n\f");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords == MAX_NUM_WORDS) {
                    printf("Error: Too many words.\n");
                    fclose(file);
                    free(wordCounts);
                    return 3;
                }
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " \t\r\n\f");
        }
    }

    fclose(file);

    printf("Word Counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);
    return 0;
}