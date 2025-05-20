//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float grade;
} student_t;

int main() {
    int n, i;
    student_t *students;

    // read number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // allocate memory for students
    students = malloc(n * sizeof(student_t));

    // read student details
    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);

        printf("Enter age of student %s: ", students[i].name);
        scanf("%d", &students[i].age);

        printf("Enter grade of student %s: ", students[i].name);
        scanf("%f", &students[i].grade);
    }

    // sort students by age in ascending order
    for (i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (students[j].age < students[i].age) {
                student_t temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // print sorted list of students
    printf("\nSorted list of students:\n");
    for (i = 0; i < n; i++) {
        printf("%s (%d years old) - Grade: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    // free memory
    for (i = 0; i < n; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}