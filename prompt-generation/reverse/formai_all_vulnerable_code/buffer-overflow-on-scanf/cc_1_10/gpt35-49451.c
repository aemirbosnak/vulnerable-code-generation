//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_GRADE 100

typedef struct Student {
    char name[MAX_NAME_LENGTH];
    int grade;
} Student;

int main() {
    int num_students;

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    Student* students = (Student*) malloc(num_students * sizeof(Student));

    if (students == NULL) {
        printf("Unable to allocate memory for students.\n");
        return 1;
    }

    for (int i = 0; i < num_students; i++) {
        char name[MAX_NAME_LENGTH];

        printf("Enter name of student %d: ", i+1);
        scanf("%s", name);

        int grade;

        printf("Enter grade of student %d: ", i+1);
        scanf("%d", &grade);

        while (grade < 0 || grade > 100) {
            printf("Invalid grade, please enter between 0 and 100: ");
            scanf("%d", &grade);
        }

        strcpy(students[i].name, name);
        students[i].grade = grade;
    }

    int top_grade = -1;
    char top_name[MAX_NAME_LENGTH];

    for (int i = 0; i < num_students; i++) {
        if (students[i].grade > top_grade) {
            top_grade = students[i].grade;
            strcpy(top_name, students[i].name);
        }
    }

    printf("Student with highest grade: %s, %d\n", top_name, top_grade);

    free(students);

    return 0;
}