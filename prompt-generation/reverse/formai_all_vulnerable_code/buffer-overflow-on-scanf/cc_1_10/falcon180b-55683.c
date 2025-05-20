//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30
#define MAX_USER_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateWords(Word words[], int numWords) {
    srand(time(NULL));
    for (int i = 0; i < numWords; i++) {
        int length = rand() % (MAX_WORD_LENGTH - 3) + 3;
        words[i].length = length;
        for (int j = 0; j < length; j++) {
            char c = rand() % 26 + 'a';
            words[i].word[j] = c;
        }
        words[i].word[length] = '\0';
    }
}

int main() {
    Word words[MAX_WORDS];
    int numWords;
    char userName[MAX_USER_LENGTH];

    printf("Enter your name: ");
    scanf("%s", userName);

    printf("Welcome, %s! Let's test your typing speed.\n", userName);

    printf("How many words do you want to type? (1-100): ");
    scanf("%d", &numWords);

    generateWords(words, numWords);

    int correctWords = 0;
    int totalWords = 0;
    int totalChars = 0;
    int correctChars = 0;

    for (int i = 0; i < numWords; i++) {
        printf("Type word %d: ", i + 1);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
            correctChars += words[i].length;
        } else {
            printf("Incorrect: %s\n", words[i].word);
        }

        totalWords++;
        totalChars += words[i].length;
    }

    double accuracy = (double)correctChars / (double)totalChars * 100;
    double wpm = (double)correctWords / (5.0 * (double)totalWords);

    printf("Results:\n");
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Words per minute: %.2f\n", wpm);

    return 0;
}