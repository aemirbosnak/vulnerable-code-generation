//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void swap(Student* a, Student* b) {
    Student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudents(Student students[], int numStudents) {
    int i, j;
    for (i = 0; i < numStudents; i++) {
        for (j = i + 1; j < numStudents; j++) {
            if (students[i].gpa < students[j].gpa) {
                swap(&students[i], &students[j]);
            }
        }
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    Student* students = malloc(numStudents * sizeof(Student));

    for (int i = 0; i < numStudents; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter student %d age: ", i + 1);
        scanf("%d", &students[i].age);
        printf("Enter student %d GPA: ", i + 1);
        scanf("%f", &students[i].gpa);
    }

    sortStudents(students, numStudents);

    printf("\nStudents sorted by GPA:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %s (GPA: %.2f, Age: %d)\n", students[i].name, students[i].gpa, students[i].age);
    }

    free(students);
    return 0;
}