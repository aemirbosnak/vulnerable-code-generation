//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 50
#define MAX_WORDS 10

char words[MAX_LENGTH][MAX_WORDS];
int lengths[MAX_WORDS];
int numWords;

void loadWords(void) {
    FILE *fp;
    char ch;
    int i, j;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            words[i][j] = '\0';
            lengths[i] = j;
            i++;
            j = 0;
        } else {
            words[i][j++] = ch;
        }
    }

    numWords = i;
    fclose(fp);
}

void shuffleWords(void) {
    int i, j, k;
    char temp[MAX_LENGTH];

    for (i = 0; i < numWords; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (lengths[j] < lengths[i]) {
                for (k = 0; k < lengths[i]; k++) {
                    temp[k] = words[i][k];
                    words[i][k] = words[j][k];
                    words[j][k] = temp[k];
                }
                lengths[i] = lengths[j];
                lengths[j] = lengths[i];
            }
        }
    }
}

void printWords(void) {
    int i, j;

    for (i = 0; i < numWords; i++) {
        for (j = 0; j < lengths[i]; j++) {
            printf("%c", words[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int i, j, k, correct = 0, incorrect = 0;
    char input[MAX_LENGTH];
    clock_t start, end;

    loadWords();
    shuffleWords();
    printWords();

    printf("Enter the words as they appear:\n");
    fflush(stdin);
    scanf("%s", input);

    start = clock();
    for (i = 0; i < numWords; i++) {
        if (strncmp(words[i], input, lengths[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
    }
    end = clock();

    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    return 0;
}