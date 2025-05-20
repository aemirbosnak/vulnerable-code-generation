//Falcon-180B DATASET v1.0 Category: Data mining ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} WordFrequency;

int compare(const void* a, const void* b) {
    WordFrequency* wf1 = (WordFrequency*)a;
    WordFrequency* wf2 = (WordFrequency*)b;
    if(wf1->count > wf2->count)
        return -1;
    else if(wf1->count < wf2->count)
        return 1;
    else
        return 0;
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordFrequency wf[MAX_WORDS];
    int numWords = 0;

    char word[WORD_LENGTH];
    while(fscanf(file, "%s", word)!= EOF) {
        int index = -1;
        for(int i = 0; i < numWords; i++) {
            if(strcmp(wf[i].word, word) == 0) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            if(numWords == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(wf[numWords].word, word);
            wf[numWords].count = 1;
            numWords++;
        } else {
            wf[index].count++;
        }
    }

    fclose(file);

    qsort(wf, numWords, sizeof(WordFrequency), compare);

    printf("Word\tFrequency\n");
    for(int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wf[i].word, wf[i].count);
    }

    return 0;
}