//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15

void printWords(char words[MAX_WORDS][MAX_WORD_LENGTH], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");
}

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;
    int score = 0;
    char ch, input;

    while (numWords < 5) {
        int wordLength = rand() % MAX_WORD_LENGTH + 1;
        char word[wordLength];
        int i;

        for (i = 0; i < wordLength - 1; i++) {
            word[i] = 'a' + (rand() % 26);
        }

        word[i] = '\0';

        if (numWords < MAX_WORDS) {
            strcpy(words[numWords++], word);
        }
        
        printf("%s ", word);
    }

    printf("\n\nType the words as fast as you can:\n");

    for (int i = 0; i < numWords; i++) {
        while ((ch = getchar()) != '\n') {
            if (ch == EOF) {
                printf("\n\nProgram terminated by user.\n");
                return 0;
            }
            else if (isalpha(ch)) {
                input = tolower(ch);
            }
            
            if (words[i][score] == input) {
                score++;
                printf("%c", input);
            }
        }

        printf(" ");
    }

    printf("\n\nYour score is: %d\n", score);

    return 0;
}