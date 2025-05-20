//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %s %s %s", questions[i].question, questions[i].options[0], questions[i].options[1], questions[i].options[2])!= EOF) {
        questions[i].answer[0] = tolower(questions[i].options[0][0]);
        i++;
    }
    fclose(fp);
}

int main() {
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];
    int numStudents, numQuestions, i, j, correctAnswers, score;
    char input[MAX_ANSWER_LENGTH];
    char name[MAX_NAME_LENGTH];

    loadQuestions(questions);
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    for (i = 0; i < numStudents; i++) {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", students[i].name);
    }
    printf("Examination started.\n");
    for (i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].options[j]);
        }
        printf("Enter your answer: ");
        scanf("%s", input);
        correctAnswers = 0;
        for (j = 0; j < MAX_OPTIONS; j++) {
            if (strcmp(input, questions[i].options[j]) == 0) {
                correctAnswers++;
                students[0].score++;
            }
        }
        if (correctAnswers == 0) {
            printf("Incorrect answer.\n");
        } else {
            printf("Correct answer.\n");
        }
    }
    printf("\nExamination finished.\n");
    for (i = 0; i < numStudents; i++) {
        score = students[i].score;
        printf("Student %s's score: %d\n", students[i].name, score);
    }
    return 0;
}