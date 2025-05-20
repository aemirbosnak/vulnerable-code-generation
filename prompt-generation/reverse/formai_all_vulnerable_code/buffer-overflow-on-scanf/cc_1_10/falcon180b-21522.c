//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void readWords(FILE *file) {
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, ",\n");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, ",\n");
        }
    }
}

void printWords() {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    readWords(file);
    fclose(file);
    printWords();
    return 0;
}