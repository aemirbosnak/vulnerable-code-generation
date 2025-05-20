//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords;

void generateWords() {
    printf("Enter the number of words (max %d): ", MAX_WORDS);
    scanf("%d", &numWords);

    printf("Enter the words:\n");
    for (int i = 0; i < numWords; i++) {
        scanf(" %s", words[i].word);
        words[i].length = strlen(words[i].word);
    }
}

void shuffleWords() {
    srand(time(NULL));
    for (int i = 0; i < numWords; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void test() {
    printf("Type the words as fast as you can!\n");
    for (int i = 0; i < numWords; i++) {
        char input[MAX_WORD_LENGTH];
        printf("Word %d: ", i + 1);
        fflush(stdout);
        scanf("%s", input);

        if (strcmp(input, words[i].word) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }

        fflush(stdout);
        usleep(500000); // Pause for 0.5 seconds
    }

    printf("Test complete.\n");
}

int main() {
    generateWords();
    shuffleWords();
    test();

    return 0;
}