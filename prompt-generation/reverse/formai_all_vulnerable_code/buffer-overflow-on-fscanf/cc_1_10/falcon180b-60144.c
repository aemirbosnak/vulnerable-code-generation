//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_ANSWERS 26
#define PASS_SCORE 80

typedef struct {
    char question[100];
    char choiceA[50];
    char choiceB[50];
    char choiceC[50];
    char choiceD[50];
    char answer[26];
    int score;
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s %d", questions[count].question, questions[count].choiceA, questions[count].choiceB, questions[count].choiceC, questions[count].choiceD, &questions[count].score)!= EOF) {
        count++;
        if (count >= MAX_QUESTIONS) {
            printf("Error: Too many questions.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void takeExam(Question questions[], int numQuestions, char answers[]) {
    int score = 0;

    for (int i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i].question);
        printf("A: %s\n", questions[i].choiceA);
        printf("B: %s\n", questions[i].choiceB);
        printf("C: %s\n", questions[i].choiceC);
        printf("D: %s\n", questions[i].choiceD);

        char choice;
        scanf(" %c", &choice);

        if (choice == questions[i].answer[0]) {
            score++;
        }
    }

    printf("Your score is: %d\n", score);
}

int main() {
    Question questions[MAX_QUESTIONS];
    loadQuestions(questions);

    int numQuestions;
    printf("How many questions do you want to answer? (1-%d) ", MAX_QUESTIONS);
    scanf("%d", &numQuestions);

    char answers[MAX_ANSWERS];
    takeExam(questions, numQuestions, answers);

    return 0;
}