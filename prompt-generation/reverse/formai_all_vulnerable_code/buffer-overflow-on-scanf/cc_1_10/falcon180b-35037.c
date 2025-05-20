//Falcon-180B DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORD 256

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
    char line[MAX_LINE];
    char word[MAX_WORD];
    WordCount words[100];
    int numWords = 0;
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", line);
        exit(1);
    }

    while (fgets(line, MAX_LINE, file)!= NULL) {
        numWords = 0;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                strncpy(word, &line[i], MAX_WORD);
                word[strcspn(word, " \n\r\t")] = '\0';
                if (strlen(word) > 0) {
                    numWords++;
                }
            }
        }
        if (numWords > 0) {
            qsort(words, numWords, sizeof(WordCount), compareWords);
            for (i = 0; i < numWords; i++) {
                printf("%s: %d\n", words[i].word, words[i].count);
            }
        }
    }

    fclose(file);
    return 0;
}