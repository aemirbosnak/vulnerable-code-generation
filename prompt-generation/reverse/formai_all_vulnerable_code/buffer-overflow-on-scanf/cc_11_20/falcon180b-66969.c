//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

int main() {
    FILE *fp;
    Word words[MAX_WORDS];
    int numWords = 0;
    int totalWords = 0;
    int correctWords = 0;
    int wrongWords = 0;
    int totalChars = 0;
    int correctChars = 0;
    int wrongChars = 0;
    int numErrors = 0;
    int i, j;
    char filename[100];
    char ch;
    time_t start, end;
    double elapsedTime;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            break;
        }
    }

    fclose(fp);

    totalWords = numWords;
    totalChars = 0;

    for (i = 0; i < numWords; i++) {
        totalChars += words[i].length;
    }

    srand(time(NULL));
    for (i = 0; i < numWords; i++) {
        j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    printf("Words: %d\n", numWords);
    printf("Total characters: %d\n", totalChars);

    start = time(NULL);
    for (i = 0; i < numWords; i++) {
        printf("Word %d: ", i+1);
        for (j = 0; j < words[i].length; j++) {
            printf("%c", words[i].word[j]);
        }
        printf("\n");
        fflush(stdout);
        if (system("clear") == -1) {
            printf("Error executing system call.\n");
            exit(1);
        }

        while ((ch = getchar())!= '\n') {
            if (ch == words[i].word[j]) {
                correctChars++;
            } else {
                wrongChars++;
            }
        }

        if (correctChars == words[i].length) {
            correctWords++;
        } else {
            wrongWords++;
        }

        totalChars += words[i].length;
    }

    end = time(NULL);
    elapsedTime = difftime(end, start);

    printf("\n");
    printf("Correct words: %d\n", correctWords);
    printf("Wrong words: %d\n", wrongWords);
    printf("Total characters typed: %d\n", totalChars);
    printf("Correct characters: %d\n", correctChars);
    printf("Wrong characters: %d\n", wrongChars);
    printf("Elapsed time: %.2f seconds\n", elapsedTime);

    return 0;
}