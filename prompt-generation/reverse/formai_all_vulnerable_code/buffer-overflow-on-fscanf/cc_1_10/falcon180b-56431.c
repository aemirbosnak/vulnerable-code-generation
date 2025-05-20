//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_PERCENTAGE 60

typedef struct {
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char answer[2];
} question;

void readQuestions(question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");

    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s %s\n", questions[count].question, questions[count].optionA, questions[count].optionB, questions[count].optionC, questions[count].optionD, questions[count].answer)!= EOF) {
        count++;
    }

    if (count == 0) {
        printf("No questions found in the file.\n");
        exit(1);
    }

    fclose(fp);
}

int checkAnswer(char userAnswer[], char correctAnswer[]) {
    if (strcmp(userAnswer, correctAnswer) == 0)
        return 1;

    return 0;
}

int main() {
    question questions[MAX_QUESTIONS];
    readQuestions(questions);

    int numQuestions = 0;
    while (questions[numQuestions].question[0]!= '\0') {
        numQuestions++;
    }

    int score = 0;
    int correctAnswers = 0;

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        printf("A. %s\n", questions[i].optionA);
        printf("B. %s\n", questions[i].optionB);
        printf("C. %s\n", questions[i].optionC);
        printf("D. %s\n", questions[i].optionD);

        char userAnswer[MAX_ANSWERS];
        scanf("%s", userAnswer);

        if (checkAnswer(userAnswer, questions[i].answer)) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect.\n");
        }

        score++;
    }

    if (score == 0) {
        printf("You did not answer any questions.\n");
    } else {
        int percentage = (correctAnswers * 100) / score;

        if (percentage >= PASS_PERCENTAGE) {
            printf("Congratulations! You passed with %d%%.\n", percentage);
        } else {
            printf("Sorry, you failed with %d%%.\n", percentage);
        }
    }

    return 0;
}