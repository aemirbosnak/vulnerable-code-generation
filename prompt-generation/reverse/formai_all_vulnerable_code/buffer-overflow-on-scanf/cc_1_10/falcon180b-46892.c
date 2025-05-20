//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    char answer[MAX_ANSWER_LENGTH];
    int numChoices;
    int correctAnswerIndex;
} Question;

void generateQuestion(Question *question) {
    int numChoices = rand() % (MAX_CHOICES - 1) + 2;
    question->numChoices = numChoices;
    for (int i = 0; i < numChoices; i++) {
        strcpy(question->choices[i], "Choice " + i);
    }
    strcpy(question->answer, "Answer");
    question->correctAnswerIndex = rand() % numChoices;
}

int main() {
    int numStudents, numQuestions;
    scanf("%d %d", &numStudents, &numQuestions);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < numQuestions; i++) {
        generateQuestion(&questions[i]);
    }

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            int choiceIndex = rand() % questions[j].numChoices;
            strcpy(questions[j].choices[choiceIndex], "Choice " + choiceIndex);
        }
        int numCorrectAnswers = 0;
        for (int j = 0; j < numQuestions; j++) {
            char answer[MAX_ANSWER_LENGTH];
            scanf("%s", answer);
            if (strcmp(answer, questions[j].answer) == 0) {
                numCorrectAnswers++;
            }
        }
        students[i].score = numCorrectAnswers;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}