//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, " \t\r\n\f\v\"");
        while (word!= NULL) {
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
            word = strtok(NULL, " \t\r\n\f\v\"");
        }
    }

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}