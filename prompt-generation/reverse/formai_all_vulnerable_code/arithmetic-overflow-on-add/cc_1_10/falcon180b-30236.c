//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    int i = 0, j = 0;
    WordCount words[MAX_WORDS];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        for (i = 0; line[i]!= '\0'; i++) {
            if (isalpha(line[i])) {
                for (j = 0; j < MAX_WORDS; j++) {
                    if (strcmp(words[j].word, word) == 0) {
                        words[j].count++;
                        break;
                    }
                }
                if (j == MAX_WORDS) {
                    strcpy(words[j].word, word);
                    words[j].count = 1;
                    j++;
                }
            }
            else {
                word[0] = '\0';
            }
        }
    }

    fclose(fp);

    printf("Word Count:\n");
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}