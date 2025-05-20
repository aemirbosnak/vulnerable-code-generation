//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateWords(Word words[], int numWords) {
    char vowels[] = "aeiouAEIOU";
    int i, j, k;

    for (i = 0; i < numWords; i++) {
        k = rand() % (sizeof(vowels) - 1);
        words[i].word[0] = vowels[k];
        for (j = 1; j < MAX_WORD_LENGTH; j++) {
            k = rand() % 26;
            if (k < 5) {
                words[i].word[j] = vowels[k];
            } else {
                words[i].word[j] = 'a' + rand() % 25;
            }
        }
        words[i].length = strlen(words[i].word);
    }
}

void printWords(Word words[], int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

int main() {
    int numWords, i, correctWords = 0;
    char input[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    time_t start, end;

    printf("Enter the number of words to type: ");
    scanf("%d", &numWords);

    generateWords(words, numWords);

    start = time(NULL);

    for (i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        fflush(stdout);
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        }
    }

    end = time(NULL);

    printf("You typed %d out of %d words correctly in %ld seconds.\n", correctWords, numWords, end - start);

    return 0;
}