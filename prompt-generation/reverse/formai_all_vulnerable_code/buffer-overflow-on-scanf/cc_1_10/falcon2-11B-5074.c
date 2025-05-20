//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 20
#define MAX_SCORE 10

int main() {
    int score = 0;
    int num_questions = 0;
    int num_correct = 0;
    int num_incorrect = 0;
    int question[NUM_QUESTIONS][3];
    int answer[NUM_QUESTIONS][3];
    int guess[NUM_QUESTIONS][3];
    char buffer[100];

    srand(time(NULL));
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        question[i][0] = rand() % 8;
        question[i][1] = rand() % 8;
        question[i][2] = rand() % 8;
        answer[i][0] = rand() % 8;
        answer[i][1] = rand() % 8;
        answer[i][2] = rand() % 8;
    }

    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Guess the element with the following properties:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%d. %d. %d\n", question[i][0], question[i][1], question[i][2]);
    }

    while (num_questions < NUM_QUESTIONS) {
        printf("Guess the element:\n");
        for (int i = 0; i < 3; i++) {
            scanf("%d", &guess[num_questions][i]);
        }
        if (guess[num_questions][0] == answer[num_questions][0] &&
            guess[num_questions][1] == answer[num_questions][1] &&
            guess[num_questions][2] == answer[num_questions][2]) {
            printf("Correct!\n");
            num_correct++;
            score += 1;
        } else {
            printf("Incorrect!\n");
            num_incorrect++;
        }
        printf("Score: %d/%d\n", score, MAX_SCORE);
        printf("Correct answers: %d\n", num_correct);
        printf("Incorrect answers: %d\n", num_incorrect);
        printf("Total questions: %d\n", num_questions);
        printf("Press any key to continue...\n");
        getchar();
        num_questions++;
    }

    if (score == MAX_SCORE) {
        printf("Congratulations! You got %d out of %d questions correct!\n", score, MAX_SCORE);
    } else {
        printf("Sorry, you got %d out of %d questions correct. Better luck next time!\n", score, MAX_SCORE);
    }

    return 0;
}