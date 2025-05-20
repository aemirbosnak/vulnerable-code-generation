//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 100
#define MAX_STUDENTS 100
#define MAX_SCORE 100

typedef struct {
    char name[50];
    int score;
} student;

typedef struct {
    char question[100];
    char answer[100];
} question;

question questions[MAX_QUESTIONS];
student students[MAX_STUDENTS];

void readquestions() {
    FILE *fp = fopen("questions.txt", "r");
    int count = 0;
    while (fscanf(fp, "%s %s", questions[count].question, questions[count].answer)!= EOF) {
        count++;
        if (count >= MAX_QUESTIONS) {
            break;
        }
    }
    fclose(fp);
}

void readstudents() {
    FILE *fp = fopen("students.txt", "r");
    int count = 0;
    while (fscanf(fp, "%s", students[count].name)!= EOF) {
        count++;
        if (count >= MAX_STUDENTS) {
            break;
        }
    }
    fclose(fp);
}

void exam() {
    int correctanswers = 0;
    printf("\nWelcome to the Medieval Online Examination System!\n\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        char answer[100];
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            correctanswers++;
        }
    }
    printf("\nYou have answered %d out of %d questions correctly.\n", correctanswers, MAX_QUESTIONS);
    printf("Your score is %d out of %d.\n", correctanswers, MAX_SCORE);
    printf("Thank you for taking the exam!\n");
}

int main() {
    readquestions();
    readstudents();
    int choice;
    do {
        printf("\nEnter 1 to take the exam or 0 to exit:\n");
        scanf("%d", &choice);
        if (choice == 1) {
            exam();
        }
    } while (choice == 1);
    return 0;
}