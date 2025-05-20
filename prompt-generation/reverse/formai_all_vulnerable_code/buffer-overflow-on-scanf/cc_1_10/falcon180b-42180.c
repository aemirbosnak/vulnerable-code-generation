//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int count = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(words[count].word, word);
                words[count].count = 1;
                count++;
            }
        }
    }
}

void printWords(WordCount words[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int count = 0;

    readWords(file, words);
    fclose(file);

    printWords(words, count);

    return 0;
}