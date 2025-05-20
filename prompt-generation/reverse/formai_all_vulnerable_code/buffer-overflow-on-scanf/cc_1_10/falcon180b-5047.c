//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100

struct question {
    char question_text[MAX_QUESTIONS];
    char correct_answer[MAX_ANSWER_LENGTH];
    int num_options;
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
};

int main() {
    int num_questions;
    struct question questions[MAX_QUESTIONS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the questions:\n");
    for (int i = 0; i < num_questions; i++) {
        questions[i].num_options = 0;
        printf("Question %d: ", i + 1);
        scanf("%s", questions[i].question_text);
        
        printf("Enter the correct answer: ");
        scanf("%s", questions[i].correct_answer);

        printf("Enter the number of options: ");
        scanf("%d", &questions[i].num_options);

        for (int j = 0; j < questions[i].num_options; j++) {
            printf("Option %d: ", j + 1);
            scanf("%s", questions[i].options[j]);
        }
    }

    int score = 0;
    int num_correct = 0;

    printf("\nExamination begins:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n%s\n", i + 1, questions[i].question_text);

        for (int j = 0; j < questions[i].num_options; j++) {
            printf("%d: %s\n", j + 1, questions[i].options[j]);
        }

        printf("Enter your answer: ");
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);

        for (int j = 0; j < questions[i].num_options; j++) {
            if (strcmp(answer, questions[i].options[j]) == 0) {
                if (strcmp(answer, questions[i].correct_answer) == 0) {
                    printf("Correct!\n");
                    num_correct++;
                } else {
                    printf("Incorrect.\n");
                }
                break;
            }
        }
    }

    printf("\nYour score is %d out of %d.\n", num_correct, num_questions);

    return 0;
}