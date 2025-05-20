//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define WORD_COUNT 100

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    FILE *fp;
    char filename[100], temp[MAX_WORD_LENGTH];
    int i, j, wordIndex;
    struct Word words[WORD_COUNT];

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    i = j = 0;
    while (fscanf(fp, "%s", temp) != EOF) {
        for (; isspace(temp[i]); i++);

        // Remove punctuation marks and convert to lowercase
        for (; isalnum(temp[i]) || ispunct(temp[i]); i++) {
            if (isalnum(temp[i]))
                words[j].word[i - (i > 0 && isspace(temp[i - 1]) ? 1 : 0)] = temp[i];
            if (ispunct(temp[i])) {
                words[j].word[i - (i > 0 && isspace(temp[i - 1]) ? 1 : 0)] = '\0';
                i--;
                break;
            }
        }

        words[j].word[i] = '\0';
        words[j].count = 1;

        for (wordIndex = 0; wordIndex < j; wordIndex++) {
            if (strcmp(words[j].word, words[wordIndex].word) == 0) {
                words[wordIndex].count += 1;
                break;
            }
        }

        if (wordIndex == j) {
            j++;
        }
    }

    fclose(fp);

    printf("\nWord frequencies:\n");
    for (i = 0; i < j; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    return 0;
}