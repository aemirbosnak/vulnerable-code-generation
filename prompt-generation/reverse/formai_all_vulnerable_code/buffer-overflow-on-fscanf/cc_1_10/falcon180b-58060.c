//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100
#define MAX_QUESTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWERS][MAX_ANSWER_LENGTH];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS];
int numQuestions;

void readQuestions(FILE *fp) {
    numQuestions = 0;
    while (fscanf(fp, "%s", questions[numQuestions].question)!= EOF) {
        numQuestions++;
    }
    rewind(fp);
    for (int i = 0; i < numQuestions; i++) {
        int numAnswers = 0;
        while (fscanf(fp, "%s", questions[i].answer[numAnswers])!= EOF) {
            numAnswers++;
        }
        questions[i].correctAnswer = rand() % numAnswers;
    }
}

int compareAnswers(char *studentAnswer, char *correctAnswer) {
    int len1 = strlen(studentAnswer);
    int len2 = strlen(correctAnswer);
    int minLen = len1 < len2? len1 : len2;
    for (int i = 0; i < minLen; i++) {
        if (tolower(studentAnswer[i])!= tolower(correctAnswer[i])) {
            return 0;
        }
    }
    return 1;
}

void takeExam(Student *student) {
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);
        if (compareAnswers(answer, questions[i].answer[questions[i].correctAnswer])) {
            score++;
        }
    }
    student->score = score;
}

void printResults(Student *students, int numStudents) {
    printf("Results:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %s: %d/%d\n", students[i].name, students[i].score, numQuestions);
    }
}

int main() {
    srand(time(NULL));
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: questions.txt not found.\n");
        return 1;
    }
    readQuestions(fp);
    fclose(fp);

    int numStudents;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);
    }

    takeExam(students);

    printResults(students, numStudents);

    return 0;
}