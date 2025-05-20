//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 50
#define MAX_ANSWERS 4
#define MAX_NAME_LENGTH 50
#define MAX_QUESTION_LENGTH 200
#define MAX_ANSWER_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Student;

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char answer1[MAX_ANSWER_LENGTH];
    char answer2[MAX_ANSWER_LENGTH];
    char answer3[MAX_ANSWER_LENGTH];
    char answer4[MAX_ANSWER_LENGTH];
    int correctAnswer;
} Question;

void readStudents(Student students[], int *numStudents) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open students.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d\n", students[i].name, &students[i].id)!= EOF) {
        i++;
    }

    *numStudents = i;
    fclose(fp);
}

void readQuestions(Question questions[], int numQuestions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open questions.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %s %s %d\n", questions[i].question, questions[i].answer1, questions[i].answer2, questions[i].answer3, &questions[i].correctAnswer)!= EOF) {
        i++;
    }

    fclose(fp);
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents;
    readStudents(students, &numStudents);

    Question questions[MAX_QUESTIONS];
    int numQuestions;
    readQuestions(questions, numQuestions);

    int scores[MAX_STUDENTS];
    memset(scores, 0, sizeof(scores));

    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        for (int j = 0; j < numStudents; j++) {
            printf("Student %d: %s\n", students[j].id, students[j].name);
            int choice;
            scanf("%d", &choice);

            if (choice == questions[i].correctAnswer) {
                scores[students[j].id-1]++;
            }
        }
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: %d\n", students[i].id, scores[i]);
    }

    return 0;
}