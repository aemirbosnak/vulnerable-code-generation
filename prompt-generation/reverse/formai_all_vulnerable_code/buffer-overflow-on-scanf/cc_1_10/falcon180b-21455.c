//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void loadWords(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error loading words file.\n");
        exit(1);
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (length > MAX_WORD_LENGTH) {
            printf("Word too long: %s\n", line);
            continue;
        }
        if (numWords >= MAX_WORDS) {
            printf("Max number of words reached.\n");
            break;
        }
        words[numWords].length = length;
        strncpy(words[numWords].word, line, length);
        numWords++;
    }
    fclose(file);
}

void printWords() {
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter words file name: ");
    scanf("%s", filename);
    loadWords(filename);
    printf("Words loaded:\n");
    printWords();
    return 0;
}