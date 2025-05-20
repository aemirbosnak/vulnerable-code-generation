//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int studentID;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char options[MAX_OPTIONS][MAX_NAME_LENGTH];
    int answer;
} Question;

int main() {
    int numStudents, numQuestions;
    Student *students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    Question *questions = (Question *)malloc(MAX_QUESTIONS * sizeof(Question));

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter the student names and IDs:\n");
    for (int i = 0; i < numStudents; i++) {
        students[i].studentID = i + 1;
        scanf("%s", students[i].name);
    }

    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    printf("Enter the questions and options:\n");
    for (int i = 0; i < numQuestions; i++) {
        scanf("%s", questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            scanf("%s", questions[i].options[j]);
        }
        questions[i].answer = i % MAX_OPTIONS + 1;
    }

    printf("Enter the student answers:\n");
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            int answer;
            scanf("%d", &answer);
            if (answer == questions[j].answer) {
                printf("%s got question %d correct\n", students[i].name, j + 1);
            } else {
                printf("%s got question %d wrong\n", students[i].name, j + 1);
            }
        }
    }

    free(students);
    free(questions);

    return 0;
}