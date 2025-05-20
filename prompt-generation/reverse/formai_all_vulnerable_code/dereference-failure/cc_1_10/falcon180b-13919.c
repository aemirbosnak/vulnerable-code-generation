//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000

typedef struct {
    char word[100];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *w1 = (WordCount*)a;
    WordCount *w2 = (WordCount*)b;
    return strcmp(w1->word, w2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char ch;
    char word[100];
    int inWord = 0;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    if(argc!= 2) {
        printf("Usage:./wordcount <filename>\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while((ch = fgetc(file))!= EOF) {
        if(isalpha(ch)) {
            inWord = 1;
            word[0] = tolower(ch);
            word[1] = '\0';
        } else if(inWord) {
            inWord = 0;
            strcat(word, " ");
            strcat(word, &ch);
        }
    }

    if(inWord) {
        strcat(word, " ");
    }

    fclose(file);

    for(int i=0; i<numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}