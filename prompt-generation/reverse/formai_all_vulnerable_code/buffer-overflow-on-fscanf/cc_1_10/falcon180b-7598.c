//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 10
#define PASS_PERCENTAGE 50

struct question {
    char question[200];
    char options[MAX_OPTIONS][100];
    char answers[MAX_ANSWERS][20];
    int num_options;
    int num_answers;
    int correct_answer;
};

void load_questions(struct question *questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }

    int question_num = 0;
    while (fscanf(fp, "%s\n", questions[question_num].question)!= EOF) {
        questions[question_num].num_options = 0;
        char option[100];
        while (fscanf(fp, "%s\n", option)!= EOF) {
            strcpy(questions[question_num].options[questions[question_num].num_options], option);
            questions[question_num].num_options++;
        }
        questions[question_num].correct_answer = rand() % questions[question_num].num_options;
        for (int i = 0; i < questions[question_num].num_options; i++) {
            if (i == questions[question_num].correct_answer) {
                strcpy(questions[question_num].answers[i], "Correct");
            } else {
                strcpy(questions[question_num].answers[i], "Incorrect");
            }
        }
        question_num++;
    }

    fclose(fp);
}

int main() {
    struct question questions[MAX_QUESTIONS];
    int num_questions = 0;

    load_questions(questions);
    num_questions = sizeof(questions) / sizeof(questions[0]);

    int user_score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < questions[i].num_options; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        char answer[20];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answers[questions[i].correct_answer]) == 0) {
            printf("Correct!\n");
            user_score++;
        } else {
            printf("Incorrect. The correct answer is: %s\n", questions[i].answers[questions[i].correct_answer]);
        }
    }

    if (user_score >= num_questions * PASS_PERCENTAGE / 100) {
        printf("Congratulations! You passed the exam with a score of %d out of %d.\n", user_score, num_questions);
    } else {
        printf("Sorry, you failed the exam with a score of %d out of %d.\n", user_score, num_questions);
    }

    return 0;
}