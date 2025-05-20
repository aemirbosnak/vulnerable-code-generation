//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100
#define PASS_MARK 50

struct question {
    char question_text[MAX_QUESTIONS];
    char options[MAX_OPTIONS][MAX_OPTIONS];
    char answer[MAX_ANSWER_LENGTH];
};

void read_questions(struct question *questions, int num_questions) {
    FILE *fp;
    int i, j;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open questions file.\n");
        exit(1);
    }

    for (i = 0; i < num_questions; i++) {
        fscanf(fp, "%s", questions[i].question_text);
        for (j = 0; j < MAX_OPTIONS; j++) {
            fscanf(fp, "%s", questions[i].options[j]);
        }
        fscanf(fp, "%s", questions[i].answer);
    }

    fclose(fp);
}

int main() {
    int num_questions, i, j, correct_answers = 0;
    struct question questions[MAX_QUESTIONS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    read_questions(questions, num_questions);

    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question_text);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }

        char answer[MAX_ANSWER_LENGTH];
        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            correct_answers++;
        }
    }

    printf("\nYou got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}