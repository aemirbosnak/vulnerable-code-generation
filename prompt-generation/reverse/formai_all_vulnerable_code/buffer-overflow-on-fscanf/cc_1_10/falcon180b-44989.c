//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int length;
    int correct;
    int wrong;
} Word;

void generateWords(Word words[MAX_WORDS]) {
    FILE *file = fopen("words.txt", "r");
    int count = 0;

    while (fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

int checkInput(char input, char correct) {
    if (tolower(input) == tolower(correct)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;
    int numAttempts = 0;
    int numCorrect = 0;
    int numWrong = 0;
    int numMissed = 0;
    int numBackspaces = 0;
    int score = 0;
    int accuracy = 0;
    int speed = 0;
    char input;
    time_t start, end;

    srand(time(NULL));

    generateWords(words);
    numWords = rand() % MAX_WORDS;

    for (int i = 0; i < numWords; i++) {
        words[i].correct = 0;
        words[i].wrong = 0;
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a series of words to type.\n");
    printf("Press Enter to begin.\n");
    getchar();

    start = time(NULL);

    for (int i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", words[i].word);

        numAttempts++;

        while (words[i].length > strlen(words[i].word)) {
            printf("Incorrect. Try again.\n");
            scanf("%s", words[i].word);
            numBackspaces++;
        }

        if (strlen(words[i].word) == words[i].length) {
            numCorrect++;
        } else {
            numWrong++;
        }

        if (i == numWords - 1) {
            end = time(NULL);
            speed = (int) (numWords * 60 / (end - start));
        }
    }

    accuracy = (int) ((float) numCorrect / numWords * 100);

    printf("\nTest complete!\n");
    printf("You typed %d words correctly.\n", numCorrect);
    printf("You typed %d words incorrectly.\n", numWrong);
    printf("You missed %d words.\n", numMissed);
    printf("You used backspace %d times.\n", numBackspaces);
    printf("Your accuracy is %d%%.\n", accuracy);
    printf("Your speed is %d WPM.\n", speed);
    printf("Your score is %d.\n", score);

    return 0;
}