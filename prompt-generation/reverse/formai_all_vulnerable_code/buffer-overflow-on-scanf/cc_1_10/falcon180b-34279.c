//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_ANSWER_LEN 50

struct question {
    char question[MAX_ANSWER_LEN];
    char options[MAX_OPTIONS][MAX_ANSWER_LEN];
    char answer[MAX_ANSWER_LEN];
};

void generate_questions() {
    int i, j;
    struct question questions[MAX_QUESTIONS];

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d:\n", i+1);
        scanf("%s", questions[i].question);

        printf("Enter answer:\n");
        scanf("%s", questions[i].answer);

        printf("Enter options (up to %d):\n", MAX_OPTIONS);
        for (j = 0; j < MAX_OPTIONS; j++) {
            scanf("%s", questions[i].options[j]);
        }
    }
}

void take_exam(struct question questions[], int num_questions) {
    int i, j, correct_answers = 0;

    for (i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }

        char answer[MAX_ANSWER_LEN];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            correct_answers++;
        }
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);
}

int main() {
    struct question questions[MAX_QUESTIONS];
    int num_questions;

    printf("Enter number of questions (up to %d):\n", MAX_QUESTIONS);
    scanf("%d", &num_questions);

    generate_questions();
    take_exam(questions, num_questions);

    return 0;
}