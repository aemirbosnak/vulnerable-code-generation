//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

struct question {
    char question_text[100];
    char options[MAX_OPTIONS][100];
    char correct_answer;
};

struct exam {
    struct question questions[MAX_QUESTIONS];
    int num_questions;
};

void load_exam(struct exam *exam) {
    FILE *fp;

    fp = fopen("exam.txt", "r");
    if (fp == NULL) {
        perror("Error opening exam file");
        exit(1);
    }

    fscanf(fp, "%d", &exam->num_questions);

    for (int i = 0; i < exam->num_questions; i++) {
        fscanf(fp, "%[^;];", exam->questions[i].question_text);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            fscanf(fp, "%[^;];", exam->questions[i].options[j]);
        }
        fscanf(fp, "%c\n", &exam->questions[i].correct_answer);
    }

    fclose(fp);
}

void take_exam(struct exam *exam) {
    char answer;

    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question_text);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", 'A' + j, exam->questions[i].options[j]);
        }

        scanf(" %c", &answer);
        if (answer == exam->questions[i].correct_answer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %c.\n", exam->questions[i].correct_answer);
        }
    }
}

int main() {
    struct exam exam;

    load_exam(&exam);
    take_exam(&exam);

    return 0;
}