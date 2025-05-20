//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    WordCount words[MAX_WORD_SIZE];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        numWords = 0;
        char *p = strtok(line, ",.?!;:-\"()[]{}<>");
        while (p!= NULL) {
            strcpy(word, p);
            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
            p = strtok(NULL, ",.?!;:-\"()[]{}<>");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}