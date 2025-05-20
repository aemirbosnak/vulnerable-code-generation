//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char choices[MAX_CHOICES][MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

int main() {
    int numStudents, numQuestions;
    scanf("%d", &numStudents);
    scanf("%d", &numQuestions);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < numQuestions; i++) {
        scanf("%s", questions[i].question);
        scanf("%s", questions[i].answer);
        for (int j = 0; j < MAX_CHOICES; j++) {
            scanf("%s", questions[i].choices[j]);
        }
    }

    int numCorrectAnswers = 0;
    for (int i = 0; i < numStudents; i++) {
        int score = 0;
        for (int j = 0; j < numQuestions; j++) {
            printf("%s - ", questions[j].question);
            for (int k = 0; k < MAX_CHOICES; k++) {
                printf("%s ", questions[j].choices[k]);
            }
            printf("\n");

            char answer[MAX_ANSWER_LENGTH];
            scanf("%s", answer);

            if (strcmp(answer, questions[j].answer) == 0) {
                score++;
            }
        }
        students[i].score = score;
        numCorrectAnswers += score;
    }

    printf("Number of correct answers: %d\n", numCorrectAnswers);

    return 0;
}