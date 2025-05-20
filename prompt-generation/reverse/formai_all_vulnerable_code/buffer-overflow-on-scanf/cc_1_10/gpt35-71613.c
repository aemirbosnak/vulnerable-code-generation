//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADES 10
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_grades;
    int grades[MAX_GRADES];
    float avg_grade;
} student_t;

int main() {
    student_t students[MAX_STUDENTS];
    int num_students = 0;
    char input[MAX_NAME_LENGTH];
    int i;

    while (1) {
        printf("Enter student name (or quit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0)
            break;

        student_t new_student;
        strcpy(new_student.name, input);
        new_student.num_grades = 0;
        new_student.avg_grade = 0;

        printf("Enter grades (up to %d, -1 to stop): ", MAX_GRADES);
        for (i = 0; i < MAX_GRADES; i++) {
            int grade;
            scanf("%d", &grade);
            if (grade == -1)
                break;
            new_student.grades[i] = grade;
            new_student.num_grades++;
        }

        float sum = 0;
        for (i = 0; i < new_student.num_grades; i++)
            sum += new_student.grades[i];
        new_student.avg_grade = sum / new_student.num_grades;

        students[num_students++] = new_student;
    }

    printf("Student\t\tGrades\t\tAvg Grade\n");
    printf("------------------------------------\n");
    for (i = 0; i < num_students; i++) {
        printf("%s\t", students[i].name);
        int j;
        for (j = 0; j < students[i].num_grades; j++)
            printf("%d ", students[i].grades[j]);
        printf("\t\t%.2f\n", students[i].avg_grade);
    }

    return 0;
}