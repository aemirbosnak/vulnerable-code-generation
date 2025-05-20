//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int roll_number;
    float marks[3];
} Student;

void swap_students(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int compare_students(const void* a, const void* b) {
    Student* student_a = (Student*) a;
    Student* student_b = (Student*) b;

    if (student_a->roll_number < student_b->roll_number) {
        return -1;
    } else if (student_a->roll_number > student_b->roll_number) {
        return 1;
    } else {
        for (int i = 0; i < 3; i++) {
            if (student_a->marks[i] < student_b->marks[i]) {
                return -1;
            } else if (student_a->marks[i] > student_b->marks[i]) {
                return 1;
            }
        }
        return 0;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("\nEnter student data:\n");

    for (int i = 0; i < num_students; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number);

        printf("\nSubject Marks:\n");
        for (int j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
    }

    qsort(students, num_students, sizeof(Student), compare_students);

    printf("\nSorted Student Records:\n");

    for (int i = 0; i < num_students; i++) {
        printf("\nName: %s", students[i].name);
        printf("\nRoll Number: %d", students[i].roll_number);
        printf("\nSubject Marks: ");
        for (int j = 0; j < 3; j++) {
            printf("\nSubject %d: %.2f", j + 1, students[i].marks[j]);
        }
    }

    return 0;
}