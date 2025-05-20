//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 10
#define WORD_LENGTH 10
#define TIMER_SECONDS 10

char words[NUM_WORDS][WORD_LENGTH] = {
    "programming",
    "typing",
    "speed",
    "test",
    "example",
    "introspective",
    "style",
    "unique",
    "creative",
    "code"
};

int main() {
    srand(time(NULL));
    int wordIndex = rand() % NUM_WORDS;
    char word[WORD_LENGTH + 1] = "";
    strncat(word, words[wordIndex], WORD_LENGTH);
    printf("Type the word: %s\n", word);

    int lettersTyped = 0;
    int correctLetters = 0;
    int incorrectLetters = 0;
    int i = 0;
    int startTime = time(NULL);

    while (i < WORD_LENGTH) {
        char c = getchar();
        if (c == word[i]) {
            correctLetters++;
        } else if (c!= '\b' && c!= '\r' && c!= '\n') {
            incorrectLetters++;
        }
        lettersTyped++;
        i++;
    }

    int endTime = time(NULL);
    int elapsedTime = endTime - startTime;

    if (elapsedTime > TIMER_SECONDS) {
        printf("Time limit exceeded.\n");
    } else {
        double wpm = (double)WORD_LENGTH * 60 / (double)elapsedTime;
        printf("You typed %d correct letters and %d incorrect letters.\n", correctLetters, incorrectLetters);
        printf("Your typing speed is %.2f WPM.\n", wpm);
    }

    return 0;
}