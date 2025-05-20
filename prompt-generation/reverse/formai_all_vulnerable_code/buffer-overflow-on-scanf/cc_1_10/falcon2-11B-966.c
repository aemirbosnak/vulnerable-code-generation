//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    int age;
    int marks[5];
};

struct Student students[10];

int main() {
    int numStudents;
    int numQuestions;
    int questionIndex = 0;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numStudents; i++) {
        int id = i + 1;
        printf("Enter student %d's name: ", id);
        scanf("%s", students[i].name);

        printf("Enter student %d's age: ", id);
        scanf("%d", &students[i].age);

        printf("Enter student %d's marks: ", id);
        for (int j = 0; j < numQuestions; j++) {
            int mark;
            printf("Enter mark %d: ", questionIndex + 1);
            scanf("%d", &mark);
            students[i].marks[questionIndex] = mark;
            questionIndex++;
        }
    }

    printf("Online Examination System\n");
    printf("-------------------------\n");

    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks:\n");
        for (int j = 0; j < numQuestions; j++) {
            printf("%d. ", j + 1);
            printf("%d\n", students[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}