//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_SCORE 100
#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    char answer1[50];
    char answer2[50];
    char answer3[50];
    char answer4[50];
    char correctAnswer;
} Question;

void generateQuestions(Question questions[], int numQuestions) {
    srand(time(0));
    for (int i = 0; i < numQuestions; i++) {
        int numAnswers = rand() % MAX_ANSWERS + 1;
        questions[i].correctAnswer = 'A' + rand() % numAnswers;
        for (int j = 0; j < numAnswers; j++) {
            questions[i].answer1[j] = 'A' + j;
        }
    }
}

void takeExam(Student students[], int numStudents, Question questions[], int numQuestions) {
    for (int i = 0; i < numStudents; i++) {
        students[i].score = 0;
    }
    printf("Welcome to the Online Examination System!\n");
    for (int i = 0; i < numQuestions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%c. %s\n", questions[i].answer1[j], questions[i].answer1[j]);
        }
    }
    for (int i = 0; i < numStudents; i++) {
        printf("Student %s, your score is %d.\n", students[i].name, students[i].score);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    int numQuestions, numStudents;

    printf("How many questions do you want to generate? ");
    scanf("%d", &numQuestions);

    printf("How many students will take the exam? ");
    scanf("%d", &numStudents);

    generateQuestions(questions, numQuestions);

    printf("Enter the names of the students:\n");
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }

    takeExam(students, numStudents, questions, numQuestions);

    return 0;
}