//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_ANSWERS 26
#define PASS_MARK 60

typedef struct {
    char question[100];
    char choice1[100];
    char choice2[100];
    char choice3[100];
    char choice4[100];
    char answer[3];
    int mark;
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error loading questions\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %s %s %s %s %s %d", questions[i].question, questions[i].choice1, questions[i].choice2, questions[i].choice3, questions[i].choice4, questions[i].answer, &questions[i].mark)!= EOF) {
        i++;
        if (i >= MAX_QUESTIONS) {
            printf("Too many questions\n");
            exit(1);
        }
    }
    fclose(fp);
}

int main() {
    srand(time(NULL));
    Question questions[MAX_QUESTIONS];
    loadQuestions(questions);
    int numQuestions = rand() % MAX_QUESTIONS + 1;
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        int choice;
        printf("Question %d: %s\n", i+1, questions[i].question);
        for (int j = 0; j < questions[i].mark; j++) {
            printf("%d. %s\n", j+1, questions[i].choice1);
        }
        printf("Answer: ");
        scanf("%d", &choice);
        if (choice == questions[i].mark) {
            score += questions[i].mark;
        } else if (choice < questions[i].mark) {
            printf("Wrong answer\n");
        } else {
            printf("Invalid answer\n");
        }
    }
    printf("Your score is %d out of %d\n", score, numQuestions * questions[0].mark);
    return 0;
}