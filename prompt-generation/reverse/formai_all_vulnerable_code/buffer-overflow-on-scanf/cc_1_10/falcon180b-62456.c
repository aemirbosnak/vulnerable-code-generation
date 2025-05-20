//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

typedef struct {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[MAX_ANSWERS];
} question_t;

typedef struct {
    int num_questions;
    int score;
} result_t;

void generate_questions(question_t questions[], int num_questions) {
    int i;
    for (i = 0; i < num_questions; i++) {
        sprintf(questions[i].question, "Question %d:", i + 1);
        sprintf(questions[i].answer, "%c", 'A' + rand() % 4);
        sprintf(questions[i].option1, "Option 1");
        sprintf(questions[i].option2, "Option 2");
        sprintf(questions[i].option3, "Option 3");
        sprintf(questions[i].option4, "Option 4");
    }
}

int main() {
    int num_questions = 0;
    question_t questions[MAX_QUESTIONS];
    result_t result;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions: ");
    scanf("%d", &num_questions);

    if (num_questions > MAX_QUESTIONS) {
        printf("Error: Maximum number of questions is %d.\n", MAX_QUESTIONS);
        return 1;
    }

    generate_questions(questions, num_questions);

    int i, j, correct_answers = 0;
    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s\n", i + 1, questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].option1);
        }
        printf("Enter your answer: ");
        char answer[MAX_ANSWERS];
        scanf("%s", answer);
        if (answer[0] == questions[i].answer[0]) {
            correct_answers++;
        }
    }

    result.num_questions = num_questions;
    result.score = correct_answers;

    printf("\nYour result:\n");
    printf("Number of questions: %d\n", num_questions);
    printf("Number of correct answers: %d\n", correct_answers);
    printf("Score: %.2f%%\n", (double)correct_answers / num_questions * 100);

    return 0;
}