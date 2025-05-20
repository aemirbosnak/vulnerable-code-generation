//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];

void loadWords() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(0));

    loadWords();

    int index = rand() % MAX_WORDS;
    printf("Type the word: %s\n", words[index].word);

    char input[MAX_WORD_LENGTH];
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, words[index].word) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    return 0;
}