//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_TEST_TIME 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void loadWords(Word *words, int numWords) {
    FILE *file = fopen("words.txt", "r");
    int i = 0;
    while (i < numWords && fscanf(file, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
    }
    fclose(file);
}

int main() {
    srand(time(NULL));

    int numWords = rand() % MAX_WORDS + 1;
    Word words[MAX_WORDS];
    loadWords(words, numWords);

    int score = 0;
    int correctWords = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", MAX_TEST_TIME);
    printf("Press enter to begin...\n");
    getchar();

    clock_t startTime = clock();
    while (clock() - startTime < MAX_TEST_TIME * CLOCKS_PER_SEC) {
        Word currentWord = words[rand() % numWords];
        char input[MAX_WORD_LENGTH];
        fflush(stdin);
        printf("Type the word '%s': ", currentWord.word);
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, currentWord.word) == 0) {
            score += currentWord.length;
            correctWords++;
        }

        printf("\r%d/%d correct, %d WPM", correctWords, numWords, (int)((double)score / (clock() - startTime) * 60));
        fflush(stdout);
    }

    printf("\n\nTest complete!\n");
    printf("Score: %d\n", score);
    printf("Words per minute: %d\n", (int)((double)score / MAX_TEST_TIME * 60));

    return 0;
}