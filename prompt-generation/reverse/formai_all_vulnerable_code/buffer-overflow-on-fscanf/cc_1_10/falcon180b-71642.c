//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int correct;
} Word;

void loadWords(Word words[MAX_WORDS]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    loadWords(words);

    int numWords = rand() % MAX_WORDS;
    Word selectedWords[numWords];

    for (int i = 0; i < numWords; i++) {
        int index = rand() % MAX_WORDS;
        while (selectedWords[i].length == 0 || strcmp(selectedWords[i].word, words[index].word) == 0) {
            index = rand() % MAX_WORDS;
        }
        selectedWords[i] = words[index];
    }

    int totalCorrect = 0;
    for (int i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, selectedWords[i].word) == 0) {
            totalCorrect++;
        }
    }

    printf("Your typing speed is %d words per minute.\n", totalCorrect * 60 / (5 * numWords));

    return 0;
}