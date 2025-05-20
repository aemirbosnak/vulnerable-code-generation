//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ANSWERS 100

struct question {
    char question[100];
    char options[MAX_OPTIONS][100];
    int answer;
};

void init_question(struct question *q) {
    memset(q, 0, sizeof(struct question));
}

void add_option(struct question *q, char *option) {
    int i = 0;
    while (i < MAX_OPTIONS && q->options[i][0]!= '\0') {
        i++;
    }
    if (i == MAX_OPTIONS) {
        printf("Maximum number of options reached.\n");
        return;
    }
    strcpy(q->options[i], option);
}

void set_answer(struct question *q, int ans) {
    q->answer = ans;
}

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    struct question questions[MAX_QUESTIONS];
    for (int i = 0; i < num_questions; i++) {
        init_question(&questions[i]);
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        int num_options = 0;
        printf("Enter the number of options: ");
        scanf("%d", &num_options);

        for (int j = 0; j < num_options; j++) {
            char option[100];
            printf("Enter option %d: ", j+1);
            scanf("%s", option);
            add_option(&questions[i], option);
        }

        set_answer(&questions[i], rand() % num_options + 1);
    }

    int num_answers = 0;
    printf("Enter the number of answers to check: ");
    scanf("%d", &num_answers);

    int correct_answers = 0;
    for (int i = 0; i < num_answers; i++) {
        int qid;
        printf("Enter the question ID: ");
        scanf("%d", &qid);

        int aid;
        printf("Enter your answer: ");
        scanf("%d", &aid);

        if (aid == questions[qid-1].answer) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("You got %d out of %d correct.\n", correct_answers, num_answers);

    return 0;
}