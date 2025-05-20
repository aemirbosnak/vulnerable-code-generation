//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char *word) {
    if (numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        return;
    }
    strcpy(words[numWords].word, word);
    words[numWords].length = strlen(word);
    numWords++;
}

void loadWords(char *filename) {
    FILE *fp;
    char line[MAX_WORD_LENGTH + 1];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    for (i = 0; i < MAX_WORDS && fgets(line, MAX_WORD_LENGTH + 1, fp)!= NULL; i++) {
        addWord(line);
    }

    fclose(fp);
}

void generateRandomWord() {
    int i, j;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < numWords; i++) {
        j = rand() % numWords;
        strcpy(word, words[j].word);
        words[j].word[0] = '\0';
        break;
    }
    printf("%s\n", word);
}

int main() {
    char filename[MAX_WORD_LENGTH];
    int i, j, correct, incorrect;

    printf("Enter filename: ");
    scanf("%s", filename);
    loadWords(filename);

    printf("Press Enter to start the test...\n");
    getchar();

    srand(time(NULL));
    for (i = 0; i < numWords; i++) {
        generateRandomWord();
        printf("Word: ");
        scanf("%s", words[i].word);
        if (strcmp(words[i].word, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
    }

    printf("\nResults:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Accuracy: %.2f%%\n", (float)correct / numWords * 100);

    return 0;
}