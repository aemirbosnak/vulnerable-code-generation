//Falcon-180B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a student
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to initialize a student with default values
void initStudent(Student* s) {
    strcpy(s->name, "Unknown");
    s->age = 0;
    s->gpa = 0.0;
}

// Function to print a student's information
void printStudent(Student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("GPA: %.2f\n", s.gpa);
}

// Function to compare two students based on their GPA
int compareStudents(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    if (studentA->gpa > studentB->gpa) {
        return 1;
    } else if (studentA->gpa < studentB->gpa) {
        return -1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student* students = malloc(numStudents * sizeof(Student));

    for (int i = 0; i < numStudents; i++) {
        initStudent(&students[i]);
    }

    printf("Enter student information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    qsort(students, numStudents, sizeof(Student), compareStudents);

    printf("\nStudents sorted by GPA:\n");
    for (int i = 0; i < numStudents; i++) {
        printStudent(students[i]);
    }

    free(students);
    return 0;
}