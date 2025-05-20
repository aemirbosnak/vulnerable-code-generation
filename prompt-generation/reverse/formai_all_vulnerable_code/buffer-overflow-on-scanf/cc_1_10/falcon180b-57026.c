//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void loadWords(Word words[], int count) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
        if (i >= count) {
            break;
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    int wordCount;
    printf("Enter the number of words to type: ");
    scanf("%d", &wordCount);

    Word words[MAX_WORDS];
    loadWords(words, wordCount);

    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    int correctWords = 0;
    int totalWords = 0;
    int timeElapsed = 0;

    printf("Press enter to start the test.\n");
    getchar();

    clock_t startTime = clock();
    for (int i = 0; i < wordCount; i++) {
        Word word = words[i];
        printf("%s\n", word.word);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, word.word) == 0) {
            correctWords++;
        }

        totalWords++;
    }

    clock_t endTime = clock();
    timeElapsed = (int)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nResults:\n");
    printf("Name: %s\n", name);
    printf("Words per minute: %d\n", (int)((double)correctWords / timeElapsed * 60));

    return 0;
}