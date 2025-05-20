//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char choices[MAX_CHOICES][MAX_ANSWER_LENGTH];
    int answer;
} Question;

int main() {
    int numStudents, numQuestions;
    scanf("%d %d", &numStudents, &numQuestions);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < numQuestions; i++) {
        scanf("%s", questions[i].question);
        scanf("%s", questions[i].choices[0]);
        for (int j = 1; j < MAX_CHOICES; j++) {
            scanf("%s", questions[i].choices[j]);
        }
        scanf("%d", &questions[i].answer);
    }

    int numCorrectAnswers = 0;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            int choice = 0;
            scanf("%d", &choice);
            if (choice == questions[j].answer) {
                numCorrectAnswers++;
            }
        }
    }

    printf("Number of correct answers: %d\n", numCorrectAnswers);

    return 0;
}