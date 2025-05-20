//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_MARK 50

typedef struct {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[2];
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp;
    char filename[50] = "questions.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error loading questions!\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s", questions[count].question, questions[count].option1, questions[count].option2, questions[count].option3, questions[count].option4)!= EOF) {
        questions[count].answer[0] = questions[count].option1[0];
        questions[count].answer[1] = '\0';
        count++;
    }

    fclose(fp);
}

int evaluateAnswer(char answer[], char correctAnswer[]) {
    if (strcmp(answer, correctAnswer) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void displayResults(int score, int totalQuestions) {
    printf("You scored %d out of %d!\n", score, totalQuestions);
}

int main() {
    Question questions[MAX_QUESTIONS];
    loadQuestions(questions);

    int numQuestions = 0;
    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (questions[i].question[0]!= '\0') {
            numQuestions++;
        } else {
            break;
        }
    }

    int randomIndex;
    srand(time(NULL));
    for (int i = 0; i < numQuestions; i++) {
        randomIndex = rand() % numQuestions;
        printf("%s\n", questions[randomIndex].question);

        char answer[MAX_ANSWERS];
        scanf("%s", answer);

        if (evaluateAnswer(answer, questions[randomIndex].answer)) {
            score++;
        }
    }

    displayResults(score, numQuestions);

    return 0;
}