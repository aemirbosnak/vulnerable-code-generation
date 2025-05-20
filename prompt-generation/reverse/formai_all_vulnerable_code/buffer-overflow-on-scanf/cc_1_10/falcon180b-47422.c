//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_CHOICES 4
#define MAX_STUDENTS 50
#define PASS_SCORE 60

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    int correctAnswer;
    char choices[MAX_CHOICES][100];
} Question;

void generateQuestion(Question* q) {
    int numChoices = rand() % MAX_CHOICES + 2;
    q->correctAnswer = rand() % numChoices;
    for (int i = 0; i < numChoices; i++) {
        sprintf(q->choices[i], "Choice %d", i + 1);
    }
}

int main() {
    srand(time(NULL));

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generateQuestion(&questions[i]);
    }

    int numStudents;
    scanf("%d", &numStudents);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }

    int numCorrectAnswers = 0;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            int answer = scanf("%d", &students[i].score);
            if (answer == EOF) {
                break;
            }
            if (answer == questions[j].correctAnswer) {
                numCorrectAnswers++;
            }
        }
    }

    int passCount = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].score >= PASS_SCORE) {
            passCount++;
        }
    }

    printf("Pass rate: %.2f%%\n", (float)passCount / numStudents * 100);

    return 0;
}