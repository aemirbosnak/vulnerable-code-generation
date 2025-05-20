//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[MAX_NAME_LENGTH];
    char answers[MAX_ANSWERS][MAX_NAME_LENGTH];
    int correct_answer_index;
} Question;

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i].question);

        printf("Enter the correct answer index (1 - %d) for question %d: ", MAX_ANSWERS, i + 1);
        scanf("%d", &questions[i].correct_answer_index);

        printf("Enter answer 1 for question %d: ", i + 1);
        scanf("%s", questions[i].answers[0]);

        printf("Enter answer 2 for question %d: ", i + 1);
        scanf("%s", questions[i].answers[1]);

        printf("Enter answer 3 for question %d: ", i + 1);
        scanf("%s", questions[i].answers[2]);

        printf("Enter answer 4 for question %d: ", i + 1);
        scanf("%s", questions[i].answers[3]);
    }

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j + 1, questions[i].answers[j]);
        }
        int answer_choice;
        printf("Enter your answer choice for question %d: ", i + 1);
        scanf("%d", &answer_choice);
        if (answer_choice == questions[i].correct_answer_index) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Your score is: %d out of %d\n", score, num_questions);
    return 0;
}