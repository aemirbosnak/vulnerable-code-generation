//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 10
#define WPM_THRESHOLD 50

char* words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "the", "cat", "sat", "on", "the", "mat", "the", "cow", "jumped", "over", "the", "moon", "the", "end"};
int numWords = sizeof(words) / sizeof(words[0]);

void generateRandomWords(char* words[], int numWords)
{
    for (int i = 0; i < numWords; i++) {
        char* randomWord = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
        int randomIndex = rand() % numWords;
        strcpy(randomWord, words[randomIndex]);
        words[i] = randomWord;
    }
}

int main()
{
    srand(time(NULL));
    generateRandomWords(words, numWords);

    int numCorrectWords = 0;
    int numIncorrectWords = 0;
    int numWordsTyped = 0;
    int numIncorrectLetters = 0;
    double wpm = 0.0;

    printf("Welcome to the Typing Speed Test!\n");

    for (int i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcmp(input, words[i]) == 0) {
            numCorrectWords++;
        } else {
            numIncorrectWords++;
        }

        int j = 0;
        while (j < strlen(input)) {
            if (input[j]!= words[i][j]) {
                numIncorrectLetters++;
            }
            j++;
        }

        numWordsTyped += strlen(input);
    }

    wpm = (double)numWordsTyped / (5.0 * numWords);

    printf("\nResults:\n");
    printf("Correct words: %d\n", numCorrectWords);
    printf("Incorrect words: %d\n", numIncorrectWords);
    printf("Incorrect letters: %d\n", numIncorrectLetters);
    printf("Words per minute: %.2f\n", wpm);

    if (wpm >= WPM_THRESHOLD) {
        printf("Congratulations! You passed the typing speed test.\n");
    } else {
        printf("Sorry, you did not pass the typing speed test.\n");
    }

    return 0;
}