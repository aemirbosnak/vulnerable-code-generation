//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_CHOICES 4
#define MAX_ANSWERS 100
#define PASS_SCORE 60

struct question {
    char question[100];
    char choice1[100];
    char choice2[100];
    char choice3[100];
    char choice4[100];
    char answer[10];
};

void readQuestions(struct question questions[MAX_QUESTIONS]) {
    FILE *fp;
    int i = 0;
    fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error opening questions file\n");
        exit(1);
    }

    while (fscanf(fp, "%s\n%s\n%s\n%s\n%s\n", questions[i].question, questions[i].choice1, questions[i].choice2, questions[i].choice3, questions[i].choice4)!= EOF) {
        strcpy(questions[i].answer, "A");
        i++;
    }

    fclose(fp);
}

int main() {
    struct question questions[MAX_QUESTIONS];
    char answer[MAX_ANSWERS][10];
    int score = 0, i, j;

    readQuestions(questions);

    printf("Welcome to the Online Examination System\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        for (j = 0; j < MAX_CHOICES; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].choice1);
        }
        scanf("%s", answer[i]);
        if (strcmp(answer[i], questions[i].answer) == 0) {
            score++;
        }
    }

    if (score >= PASS_SCORE) {
        printf("Congratulations! You have passed the exam with a score of %d out of %d.\n", score, MAX_QUESTIONS);
    } else {
        printf("Sorry, you have failed the exam with a score of %d out of %d.\n", score, MAX_QUESTIONS);
    }

    return 0;
}