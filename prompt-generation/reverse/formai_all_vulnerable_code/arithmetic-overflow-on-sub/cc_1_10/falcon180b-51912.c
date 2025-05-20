//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define WORD_LENGTH 10
#define MAX_TIME 30 // seconds

char words[MAX_WORDS][WORD_LENGTH];
int num_words;

void generateWords(int num_words) {
    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        int length = rand() % WORD_LENGTH + 1;
        char word[length];
        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        strcpy(words[i], word);
    }
}

void printWords(int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
}

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Enter the number of words you want to type: ");
    scanf("%d", &num_words);
    generateWords(num_words);
    printf("\nHere are your words:\n");
    printWords(num_words);
    printf("\nYou have %d seconds to type all the words.\n", MAX_TIME);

    long start_time = time(NULL);
    int num_correct = 0;
    while (time(NULL) - start_time < MAX_TIME) {
        char input[WORD_LENGTH];
        printf("\nType the next word: ");
        scanf("%s", input);
        if (strcmp(input, words[num_correct]) == 0) {
            num_correct++;
        } else {
            printf("\nIncorrect! Try again.\n");
        }
    }

    printf("\nTime's up! You typed %d words correctly.\n", num_correct);
    return 0;
}