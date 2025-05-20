//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5
#define MIN_ANSWER 0
#define MAX_ANSWER 4
#define NUM_FORTUNES 5

int main() {
    int questions[NUM_QUESTIONS], answers[NUM_QUESTIONS], i, j;
    int fortune[NUM_FORTUNES][NUM_FORTUNES] = {
        {-1, -1, 3, 2, 1},
        {-1, 1, 1, 2, 4},
        {2, -1, 1, 4, 1},
        {3, 2, -1, 1, 4},
        {4, 1, 2, -1, 1}
    };

    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n");
    for (i = 0; i < NUM_QUESTIONS; i++) {
        do {
            printf("Please ask a yes or no question (1-5): ");
            scanf("%d", &questions[i]);
        } while (questions[i] < 1 || questions[i] > NUM_FORTUNES);

        answers[i] = rand() % NUM_FORTUNES;

        printf("Your answer: %d\n", answers[i]);

        for (j = 0; j < NUM_FORTUNES; j++) {
            if (questions[i] == j && answers[i] == fortune[j][answers[i]]) {
                printf("Your fortune: Great success is coming to you!\n");
                break;
            }
        }

        for (j = 0; j < NUM_FORTUNES; j++) {
            if (questions[i] == j && answers[i] != fortune[j][answers[i]]) {
                printf("Your fortune: Be careful of deception and misfortune.\n");
                break;
            }
        }
    }

    printf("Thank you for using the Automated Fortune Teller!");

    return 0;
}