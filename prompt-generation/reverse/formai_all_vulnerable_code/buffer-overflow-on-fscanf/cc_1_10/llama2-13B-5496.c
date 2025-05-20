//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_VALUE 100

typedef struct student {
    char name[MAX_NAME_LENGTH];
    int grade;
} Student;

void sortStudentsByGrade(Student students[], int numStudents) {
    int i, j, min_index;
    for (i = 0; i < numStudents - 1; i++) {
        min_index = i;
        for (j = i + 1; j < numStudents; j++) {
            if (students[j].grade > students[min_index].grade) {
                min_index = j;
            }
        }
        if (min_index != i) {
            Student temp = students[i];
            students[i] = students[min_index];
            students[min_index] = temp;
        }
    }
}

int main() {
    int numStudents, i;
    Student students[10];

    // Initialize students
    for (i = 0; i < 10; i++) {
        printf("Enter name and grade: ");
        fscanf(stdin, "%19s %d", students[i].name, &students[i].grade);
    }

    // Sort students by grade
    sortStudentsByGrade(students, 10);

    // Print sorted list of students
    for (i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, students[i].name);
    }

    return 0;
}