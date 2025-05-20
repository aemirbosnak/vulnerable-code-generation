//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 1000
#define MAX_ANSWERS 10
#define MAX_STUDENTS 1000
#define MAX_SCORE 1000

typedef struct {
    char name[50];
    int score;
} student;

typedef struct {
    char question[100];
    char answer[50];
    int correct_answer;
} question;

int main() {
    int num_questions, num_students, i, j, k, correct_answers = 0;
    char filename[50];
    FILE *fp;
    question questions[MAX_QUESTIONS];
    student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    for (i = 0; i < num_questions; i++) {
        fscanf(fp, "%s %s %d", questions[i].question, questions[i].answer, &questions[i].correct_answer);
    }

    fclose(fp);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_students; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    srand(time(NULL));

    for (i = 0; i < num_questions; i++) {
        for (j = 0; j < num_students; j++) {
            k = rand() % MAX_ANSWERS;
            strcpy(questions[i].answer, questions[i].answer + k);
        }
        printf("%s\n", questions[i].question);
        for (j = 0; j < num_students; j++) {
            printf("Student %s's answer: %s\n", students[j].name, questions[i].answer);
        }
        correct_answers += check_answer(questions[i].answer, questions[i].correct_answer);
    }

    printf("Total correct answers: %d\n", correct_answers);

    return 0;
}

int check_answer(char answer[50], int correct_answer) {
    if (strcmp(answer, "correct") == 0 && correct_answer == 1) {
        return 1;
    } else if (strcmp(answer, "incorrect") == 0 && correct_answer == 0) {
        return 1;
    } else {
        return 0;
    }
}