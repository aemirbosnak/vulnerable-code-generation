//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTS 1000

struct Student {
    char name[100];
    char roll_no[20];
    char question[100];
    char answer[100];
};

void addStudent(struct Student* students, int index, char* name, char* roll_no, char* question, char* answer) {
    strcpy(students[index].name, name);
    strcpy(students[index].roll_no, roll_no);
    strcpy(students[index].question, question);
    strcpy(students[index].answer, answer);
}

void displayStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s\nRoll No: %s\nQuestion: %s\nAnswer: %s\n\n", students[i].name, students[i].roll_no, students[i].question, students[i].answer);
    }
}

void quiz(struct Student* students, int size) {
    int numCorrect = 0;
    for (int i = 0; i < size; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", students[i].question);
        printf("Answer: ");
        scanf("%s", students[i].answer);
        printf("Your answer: ");
        scanf("%s", students[i].answer);
        if (strcmp(students[i].answer, students[i].answer) == 0) {
            numCorrect++;
        }
        printf("\n");
    }
    printf("You got %d questions correct.\n", numCorrect);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int size = 0;
    int numStudents;

    printf("How many students are taking the exam?\n");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        char name[100];
        char roll_no[20];
        char question[100];
        char answer[100];

        printf("Enter name for student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter roll no for student %d: ", i + 1);
        scanf("%s", roll_no);
        printf("Enter question for student %d: ", i + 1);
        scanf("%s", question);
        printf("Enter answer for student %d: ", i + 1);
        scanf("%s", answer);

        addStudent(students, size, name, roll_no, question, answer);
        size++;
    }

    printf("Students added successfully.\n");
    printf("Displaying students:\n");
    displayStudents(students, size);

    printf("Starting the quiz...\n");
    quiz(students, size);

    return 0;
}