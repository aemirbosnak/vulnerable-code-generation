//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

typedef struct wordfreq {
    char word[MAX_LENGTH];
    int frequency;
} wordfreq;

int main() {
    char input[MAX_WORDS][MAX_LENGTH];
    wordfreq wordfreqs[MAX_WORDS];
    int count[MAX_WORDS] = {0};
    int numwords = 0;
    int uniquewords = 0;
    int maxfreq = 0;

    printf("Enter some text (max %d words):\n", MAX_WORDS);

    /* read inputs */
    while (scanf("%s", input[numwords]) != EOF && numwords < MAX_WORDS) {
        numwords++;
    }

    /* count word frequency */
    for (int i = 0; i < numwords; i++) {
        int j;
        for (j = 0; j < uniquewords; j++) {
            if (strcmp(input[i], wordfreqs[j].word) == 0) {
                wordfreqs[j].frequency++;
                if (wordfreqs[j].frequency > maxfreq) {
                    maxfreq = wordfreqs[j].frequency;
                }
                break;
            }
        }
        if (j == uniquewords) {
            /* new word */
            strcpy(wordfreqs[j].word, input[i]);
            wordfreqs[j].frequency = 1;
            uniquewords++;
        }
    }

    /* print results */
    printf("\nWord frequency count:\n");
    printf("%-20s Frequency\n", "Word");
    for (int i = 0; i < uniquewords; i++) {
        printf("%-20s %d\n", wordfreqs[i].word, wordfreqs[i].frequency);
    }
    printf("\nTotal words: %d\n", numwords);
    printf("Unique words: %d\n", uniquewords);
    printf("Most frequent word(s):\n");
    for (int i = 0; i < uniquewords; i++) {
        if (wordfreqs[i].frequency == maxfreq) {
            printf("\t%s (%d times)\n", wordfreqs[i].word, maxfreq);
        }
    }

    return 0;
}