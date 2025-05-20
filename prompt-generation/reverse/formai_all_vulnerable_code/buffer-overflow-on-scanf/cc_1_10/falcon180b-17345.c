//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ANSWERS 1

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int answer;
} Question;

void display_question(Question *q) {
    printf("Question: %s\n", q->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i+1, q->options[i]);
    }
}

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < num_questions; i++) {
        printf("\nEnter question %d:\n", i+1);
        scanf(" %[^\n]", questions[i].question);

        int num_options = 0;
        printf("\nEnter the number of options: ");
        scanf("%d", &num_options);

        for (int j = 0; j < num_options; j++) {
            printf("\nEnter option %d: ", j+1);
            scanf(" %[^\n]", questions[i].options[j]);
        }

        printf("\nEnter the correct answer (1-4): ");
        scanf("%d", &questions[i].answer);
    }

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        int user_answer;
        printf("\nQuestion %d:\n", i+1);
        display_question(&questions[i]);
        printf("\nEnter your answer (1-4): ");
        scanf("%d", &user_answer);

        if (user_answer == questions[i].answer) {
            printf("\nCorrect!\n");
            score++;
        } else {
            printf("\nIncorrect. The correct answer is %d.\n", questions[i].answer);
        }
    }

    printf("\nYour final score is: %d out of %d\n", score, num_questions);

    return 0;
}