//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100

struct question {
    char questionText[MAX_QUESTIONS];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char correctAnswer[MAX_ANSWER_LENGTH];
    int numOptions;
};

struct student {
    char name[MAX_ANSWER_LENGTH];
    int score;
};

void loadQuestions(struct question *questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open questions file\n");
        exit(1);
    }

    int numQuestions = 0;
    while (fscanf(fp, "%s\n", questions[numQuestions].questionText)!= EOF) {
        int numOptions = 0;
        char optionText[MAX_ANSWER_LENGTH];
        while (fscanf(fp, "%s\n", optionText)!= EOF) {
            strcpy(questions[numQuestions].options[numOptions], optionText);
            numOptions++;
        }
        strcpy(questions[numQuestions].correctAnswer, optionText);
        numQuestions++;
    }

    fclose(fp);
}

int main() {
    struct question questions[MAX_QUESTIONS];
    loadQuestions(questions);

    int numStudents;
    scanf("%d", &numStudents);

    struct student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }

    int numCorrectAnswers = 0;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(questions[j].questionText, "") == 0) {
                break;
            }

            printf("%s: ", questions[j].questionText);
            for (int k = 0; k < questions[j].numOptions; k++) {
                printf("%d. %s\n", k + 1, questions[j].options[k]);
            }

            char answer[MAX_ANSWER_LENGTH];
            scanf("%s", answer);

            if (strcmp(answer, questions[j].correctAnswer) == 0) {
                numCorrectAnswers++;
            }
        }

        printf("\n%s's score: %d out of %d\n", students[i].name, numCorrectAnswers, MAX_QUESTIONS);
        numCorrectAnswers = 0;
    }

    return 0;
}