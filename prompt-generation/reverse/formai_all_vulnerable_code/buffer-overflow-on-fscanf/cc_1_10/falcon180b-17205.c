//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_QUESTIONS 100
#define MAX_NUM_ANSWERS 4
#define MAX_ANSWER_LENGTH 100
#define MAX_QUESTION_LENGTH 200
#define PASS_SCORE 60

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char answer1[MAX_ANSWER_LENGTH];
    char answer2[MAX_ANSWER_LENGTH];
    char answer3[MAX_ANSWER_LENGTH];
    char answer4[MAX_ANSWER_LENGTH];
    char correct_answer;
} Question;

void read_questions(Question questions[], int num_questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    for (int i = 0; i < num_questions; i++) {
        fscanf(fp, "%s", questions[i].question);
        fscanf(fp, "%s", questions[i].answer1);
        fscanf(fp, "%s", questions[i].answer2);
        fscanf(fp, "%s", questions[i].answer3);
        fscanf(fp, "%s", questions[i].answer4);
        questions[i].correct_answer = tolower(questions[i].answer1[0]);
    }

    fclose(fp);
}

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    Question questions[MAX_NUM_QUESTIONS];
    read_questions(questions, num_questions);

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_NUM_ANSWERS; j++) {
            printf("%c. %s\n", 'A'+j, questions[i].answer1);
        }

        char answer;
        scanf("%c", &answer);
        answer = tolower(answer);

        if (answer == questions[i].correct_answer) {
            score++;
        }
    }

    printf("Your score is %d out of %d.\n", score, num_questions);

    if (score >= PASS_SCORE) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you did not pass the exam.\n");
    }

    return 0;
}