//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_OPTIONS 4
#define PASS_MARK 60

struct question {
    char question[100];
    char correct_answer;
    char options[MAX_OPTIONS][100];
};

void generate_question(struct question *q) {
    int i;
    printf("Enter question: ");
    scanf("%s", q->question);
    printf("Enter correct answer (A/B/C/D): ");
    scanf(" %c", &q->correct_answer);
    printf("Enter option A: ");
    scanf("%s", q->options[0]);
    printf("Enter option B: ");
    scanf("%s", q->options[1]);
    printf("Enter option C: ");
    scanf("%s", q->options[2]);
    printf("Enter option D: ");
    scanf("%s", q->options[3]);
}

int main() {
    srand(time(NULL));
    int num_questions;
    printf("Enter number of questions (1-%d): ", MAX_QUESTIONS);
    scanf("%d", &num_questions);
    struct question questions[MAX_QUESTIONS];
    for (int i = 0; i < num_questions; i++) {
        generate_question(&questions[i]);
    }
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        int correct_answers = 0;
        printf("\nQuestion %d:\n%s", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("\n%c. %s", 'A' + j, questions[i].options[j]);
        }
        char answer;
        scanf(" %c", &answer);
        if (answer == questions[i].correct_answer) {
            correct_answers++;
        }
        score += correct_answers;
    }
    if (score >= PASS_MARK) {
        printf("\nCongratulations! You passed the exam with a score of %d out of %d.", score, num_questions * MAX_OPTIONS);
    } else {
        printf("\nSorry, you failed the exam with a score of %d out of %d.", score, num_questions * MAX_OPTIONS);
    }
    return 0;
}