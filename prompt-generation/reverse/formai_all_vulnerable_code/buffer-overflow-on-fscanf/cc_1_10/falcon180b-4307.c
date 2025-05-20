//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 10
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char answer1[MAX_NAME_LENGTH];
    char answer2[MAX_NAME_LENGTH];
    char answer3[MAX_NAME_LENGTH];
    char answer4[MAX_NAME_LENGTH];
    char correctAnswer;
} Question;

int main() {
    int numQuestions, numAnswers, numStudents;
    char filename[MAX_NAME_LENGTH];
    FILE *fp;
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];

    // Read in the number of questions
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    // Read in the questions and answers
    printf("Enter the filename for the questions: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    for (int i = 0; i < numQuestions; i++) {
        fscanf(fp, "%s %s %s %s %c", questions[i].question, questions[i].answer1, questions[i].answer2, questions[i].answer3, questions[i].correctAnswer);
    }
    fclose(fp);

    // Read in the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Read in the student names
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
    }

    // Grade the exams
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            printf("%s's answer to question %d: ", students[i].name, j + 1);
            char answer[MAX_NAME_LENGTH];
            fgets(answer, MAX_NAME_LENGTH, stdin);
            answer[strcspn(answer, "\n")] = '\0'; // remove newline character
            if (tolower(answer[0]) == tolower(questions[j].correctAnswer)) {
                students[i].score++;
            }
        }
        printf("%s's score: %d\n", students[i].name, students[i].score);
    }

    return 0;
}