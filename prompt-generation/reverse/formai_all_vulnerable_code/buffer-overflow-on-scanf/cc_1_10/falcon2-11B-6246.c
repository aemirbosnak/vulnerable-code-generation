//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_QUESTIONS 100
#define MAX_NUM_OPTIONS 5
#define MAX_NUM_LETTERS 26

typedef struct {
    char question[MAX_NUM_QUESTIONS][MAX_NUM_OPTIONS][MAX_NUM_LETTERS];
    int correct_answer;
    int user_answer;
    int score;
} Exam;

int main() {
    Exam exam;
    int num_questions = 0;
    int user_answer;

    while (1) {
        printf("Question %d: ", num_questions + 1);
        printf("A) ");
        for (int i = 0; i < MAX_NUM_OPTIONS; i++) {
            printf("%c", exam.question[num_questions][i][0]);
        }
        printf("\nB) ");
        for (int i = 0; i < MAX_NUM_OPTIONS; i++) {
            printf("%c", exam.question[num_questions][i][1]);
        }
        printf("\nC) ");
        for (int i = 0; i < MAX_NUM_OPTIONS; i++) {
            printf("%c", exam.question[num_questions][i][2]);
        }
        printf("\nD) ");
        for (int i = 0; i < MAX_NUM_OPTIONS; i++) {
            printf("%c", exam.question[num_questions][i][3]);
        }
        printf("\n");

        scanf("%d", &user_answer);

        if (user_answer == exam.correct_answer) {
            exam.score++;
        } else {
            exam.score = 0;
        }

        printf("Your answer: %d\n", user_answer);
        printf("Correct answer: %d\n", exam.correct_answer);
        printf("Score: %d/%d\n", exam.score, num_questions + 1);

        if (exam.score == num_questions + 1) {
            break;
        }

        num_questions++;
    }

    return 0;
}