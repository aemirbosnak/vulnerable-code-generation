//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *word1 = (WordCount *) a;
    WordCount *word2 = (WordCount *) b;
    return strcmp(word1->word, word2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int lineNumber = 0;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &len, file))!= -1) {
        lineNumber++;
        char *word = strtok(line, ",.?!;:\"'");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: Too many words in file (max %d)\n", MAX_WORDS);
                    exit(1);
                }
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Line numbers:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%d: %s (%d)\n", lineNumber, words[i].word, words[i].count);
    }

    return 0;
}