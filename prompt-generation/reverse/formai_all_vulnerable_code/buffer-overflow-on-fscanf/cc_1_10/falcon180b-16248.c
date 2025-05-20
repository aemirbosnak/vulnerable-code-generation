//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
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
    char correctAnswer[MAX_NAME_LENGTH];
} Question;

Question questions[MAX_QUESTIONS];
int numQuestions;

void loadQuestions(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading questions file.\n");
        exit(1);
    }

    numQuestions = 0;
    while (fscanf(fp, "%s %s %s %s %s %s", questions[numQuestions].question, questions[numQuestions].answer1, questions[numQuestions].answer2, questions[numQuestions].answer3, questions[numQuestions].answer4, questions[numQuestions].correctAnswer)!= EOF) {
        numQuestions++;
    }

    fclose(fp);
}

int main() {
    loadQuestions("questions.txt");

    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
    }

    int numCorrectAnswers[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        numCorrectAnswers[i] = 0;
    }

    for (int i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < numStudents; j++) {
            printf("%d. %s\n", j+1, students[j].name);
            char answer[MAX_NAME_LENGTH];
            scanf("%s", answer);

            if (strcmp(answer, questions[i].correctAnswer) == 0) {
                numCorrectAnswers[j]++;
            }
        }
    }

    printf("\nResults:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d correct answers\n", students[i].name, numCorrectAnswers[i]);
    }

    return 0;
}