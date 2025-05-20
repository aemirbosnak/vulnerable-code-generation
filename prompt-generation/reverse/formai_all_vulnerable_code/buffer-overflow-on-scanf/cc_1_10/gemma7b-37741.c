//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS];

void readQuestions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        return;
    }

    int i = 0;
    while (fscanf(fp, "%[^\n]%n", questions[i].question) != EOF) {
        fscanf(fp, "%[^\n]%n", questions[i].answer);
        fscanf(fp, "%d", &questions[i].marks);
        i++;
    }

    fclose(fp);
}

void takeExam() {
    int marks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s", questions[i].question);
        printf("\n");

        char answer[256];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            marks += questions[i].marks;
        }
    }

    printf("Your total marks are: %d", marks);
}

int main() {
    readQuestions();
    takeExam();

    return 0;
}