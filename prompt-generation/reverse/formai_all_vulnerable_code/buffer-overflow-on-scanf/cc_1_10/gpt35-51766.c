//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int level = 1;
    int score = 0;
    int total_questions = 0;
    int correct_answers = 0;
    int num1, num2, answer, user_answer;

    printf("Welcome to Math Exercise Game! Let's Play!\n");

    while (1) {
        printf("\nLevel %d\n", level);
        printf("Score: %d\n", score);
        printf("Total Questions: %d\n", total_questions);
        printf("Correct Answers: %d\n", correct_answers);

        num1 = rand() % ((int) pow(10, level));
        num2 = rand() % ((int) pow(10, level));

        answer = num1 * num2;

        printf("\n%d x %d = ?\n", num1, num2);

        scanf("%d", &user_answer);

        total_questions++;

        if (user_answer == answer) {
            printf("Correct!\n");
            score += 10;
            correct_answers++;
        } else {
            printf("Wrong!\n");
        }

        if (total_questions == 10 + level) {
            if (correct_answers >= 8 + level) {
                printf("\nCongratulations! You've passed level %d. Moving on to the next level...\n", level);
                level++;
                total_questions = 0;
                correct_answers = 0;
            } else {
                printf("\nOops! You did not pass level %d. Try again...\n", level);
                total_questions = 0;
                correct_answers = 0;
            }
        }
    }

    return 0;
}