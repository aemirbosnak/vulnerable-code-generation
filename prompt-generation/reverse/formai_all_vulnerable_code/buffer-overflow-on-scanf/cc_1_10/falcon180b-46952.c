//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char word[100];
    int length, correctWords = 0, wrongWords = 0, totalWords = 0, score = 0;
    int i, j, k;
    float accuracy;
    clock_t start, end;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the number of words you want to type: ");
    scanf("%d", &length);

    srand(time(NULL));
    for (i = 0; i < length; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[length] = '\0';

    printf("\nThe word is: %s\n", word);
    printf("Press enter to start the test.\n");
    getchar();

    start = clock();

    while (1) {
        printf("\n");
        for (j = 0; j < length; j++) {
            printf("_");
        }
        printf("\n");
        for (j = 0; j < length; j++) {
            printf("_");
        }
        printf("\n");

        for (k = 0; k < length; k++) {
            if (word[k] == getchar()) {
                correctWords++;
            } else {
                wrongWords++;
            }
            totalWords++;
        }

        if (totalWords == length) {
            break;
        }
    }

    end = clock();

    accuracy = (float)correctWords / totalWords * 100;

    printf("\nTest completed!\n");
    printf("You typed %d correct words and %d wrong words.\n", correctWords, wrongWords);
    printf("Your accuracy is %.2f%%.\n", accuracy);
    printf("Your score is %d.\n", score);

    return 0;
}