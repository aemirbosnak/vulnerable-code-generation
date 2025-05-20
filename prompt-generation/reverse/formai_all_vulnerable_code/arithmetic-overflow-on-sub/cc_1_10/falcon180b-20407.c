//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS] = {
    {"abandoned", 9},
    {"apocalypse", 9},
    {"barricade", 9},
    {"dystopia", 7},
    {"famine", 6},
    {"mutant", 6},
    {"radiation", 9},
    {"ruins", 5},
    {"survival", 8},
    {"wasteland", 9}
};

int main() {
    srand(time(NULL));
    int wordIndex = rand() % MAX_WORDS;
    Word word = words[wordIndex];
    char wordToType[MAX_WORD_LENGTH + 1];
    strcpy(wordToType, word.word);
    int wordLength = word.length;
    int correctCount = 0;
    int incorrectCount = 0;
    int totalCount = 0;
    int timeLimit = 30;
    int elapsedTime = 0;
    int startTime = time(NULL);
    int i;

    printf("Welcome to the Post-Apocalyptic Typing Speed Test!\n");
    printf("You will have %d seconds to type the following word:\n", timeLimit);
    printf("%s\n", wordToType);
    printf("Press enter to begin...\n");
    fflush(stdin);
    fgets(wordToType, MAX_WORD_LENGTH + 1, stdin);
    totalCount = strlen(wordToType);

    for (i = 0; i < totalCount; i++) {
        if (wordToType[i] == word.word[i]) {
            correctCount++;
        } else {
            incorrectCount++;
        }
    }

    elapsedTime = time(NULL) - startTime;
    printf("\nYou typed %d correct characters and %d incorrect characters.\n", correctCount, incorrectCount);
    printf("Your accuracy is %.2f%% and your WPM is %.2f.\n", (float)correctCount / totalCount * 100, (float)totalCount / (elapsedTime / 60.0));
    printf("Thank you for participating in the Post-Apocalyptic Typing Speed Test!\n");
    return 0;
}