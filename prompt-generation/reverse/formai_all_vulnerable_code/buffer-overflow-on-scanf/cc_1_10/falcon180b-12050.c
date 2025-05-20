//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
    int correct_answer;
} Question;

void generate_question(Question *q) {
    strcpy(q->question, "What is the capital of France?");
    strcpy(q->options[0], "Paris");
    strcpy(q->options[1], "London");
    strcpy(q->options[2], "Berlin");
    strcpy(q->options[3], "Madrid");
    q->correct_answer = 0;
}

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions;
    int i;
    int total_correct = 0;

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (i = 0; i < num_questions; i++) {
        generate_question(&questions[i]);
    }

    printf("Online Examination System\n");
    printf("------------------------\n\n");

    for (i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);

        int j;
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].options[j]);
        }

        char answer[MAX_ANSWERS];
        scanf("%s", answer);

        int correct = 0;
        int len = strlen(answer);

        for (j = 0; j < MAX_ANSWERS; j++) {
            if (answer[j] == questions[i].answer[j]) {
                correct++;
            }
        }

        if (correct == len) {
            printf("Correct!\n");
            total_correct++;
        } else {
            printf("Incorrect. The correct answer is: %s\n", questions[i].answer);
        }
    }

    printf("\nTotal correct answers: %d out of %d\n", total_correct, num_questions);

    return 0;
}