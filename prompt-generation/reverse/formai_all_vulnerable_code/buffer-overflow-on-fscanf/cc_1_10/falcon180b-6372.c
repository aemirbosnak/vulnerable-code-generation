//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_ANSWERS 26
#define MAX_STUDENTS 100
#define MAX_NAME 50

typedef struct {
    char question[MAX_QUESTIONS];
    char choiceA[MAX_ANSWERS];
    char choiceB[MAX_ANSWERS];
    char choiceC[MAX_ANSWERS];
    char choiceD[MAX_ANSWERS];
    char answer[MAX_ANSWERS];
} Question;

typedef struct {
    char name[MAX_NAME];
    int score;
} Student;

void loadQuestions(Question questions[]) {
    FILE *fp;
    char filename[50] = "questions.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s", questions[count].question, questions[count].choiceA, questions[count].choiceB, questions[count].choiceC, questions[count].choiceD)!= EOF) {
        strcpy(questions[count].answer, "A");
        count++;
    }

    fclose(fp);
}

void loadStudents(Student students[], int numStudents) {
    FILE *fp;
    char filename[50] = "students.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s", students[count].name)!= EOF) {
        count++;
    }

    fclose(fp);
}

void saveStudents(Student students[], int numStudents) {
    FILE *fp;
    char filename[50] = "students.txt";
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(fp, "%s\n", students[i].name);
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    int numStudents;

    loadQuestions(questions);
    printf("Loading students...\n");
    scanf("%d", &numStudents);
    loadStudents(students, numStudents);

    int score = 0;
    char choice;
    int numCorrect = 0;

    for (int i = 0; i < numStudents; i++) {
        printf("Student %s's score: %d\n", students[i].name, score);
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            printf("%s)\n", questions[j].question);
            printf("A: %s\n", questions[j].choiceA);
            printf("B: %s\n", questions[j].choiceB);
            printf("C: %s\n", questions[j].choiceC);
            printf("D: %s\n", questions[j].choiceD);
            printf("Your answer: ");
            scanf(" %c", &choice);

            if (choice == questions[j].answer[0]) {
                score++;
                numCorrect++;
            }
        }
    }

    printf("Your final score is: %d\n", score);
    printf("You got %d questions correct.\n", numCorrect);

    saveStudents(students, numStudents);

    return 0;
}