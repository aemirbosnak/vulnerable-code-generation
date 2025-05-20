//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 5

typedef struct student {
    char name[50];
    int roll_number;
    int marks[MAX_SUBJECTS];
    float avg_marks;
    float percentage;
} Student;

int main() {
    int num_students, i;
    Student *students;
    float max_percentage, total_marks, avg_marks;
    char highest_student_name[50];

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    students = (Student *) malloc(num_students * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);
        scanf("%s", students[i].name);
        scanf("%d", &students[i].roll_number);

        for (int j = 0; j < MAX_SUBJECTS; j++) {
            scanf("%d", &students[i].marks[j]);
            total_marks += students[i].marks[j];
        }

        students[i].avg_marks = total_marks / MAX_SUBJECTS;
        students[i].percentage = students[i].avg_marks * 100.0 / 500.0;
    }

    printf("\nStudent Information:\n");
    for (i = 0; i < num_students; i++) {
        printf("\nName: %s\nRoll Number: %d\n", students[i].name, students[i].roll_number);
        printf("Marks:\n");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%d\t", students[i].marks[j]);
        }

        printf("\nAverage Marks: %.2f\nPercentage: %.2f%%", students[i].avg_marks, students[i].percentage);

        if (students[i].percentage > max_percentage) {
            strcpy(highest_student_name, students[i].name);
            max_percentage = students[i].percentage;
        }
    }

    printf("\nStudent with highest percentage: %s (%d%%)", highest_student_name, (int) (max_percentage + 0.5));

    free(students);

    return 0;
}