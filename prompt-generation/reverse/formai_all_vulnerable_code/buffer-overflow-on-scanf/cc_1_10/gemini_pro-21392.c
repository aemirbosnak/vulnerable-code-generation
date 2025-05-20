//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
typedef struct Student {
    char name[50];
    char rollNo[20];
    int marks;
} Student;

// Function to compare two students based on their marks
int compareStudents(const void *a, const void *b) {
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    return s2->marks - s1->marks;  // Descending order
}

// Function to print student data
void printStudent(Student s) {
    printf("Name: %s\n", s.name);
    printf("Roll No: %s\n", s.rollNo);
    printf("Marks: %d\n\n", s.marks);
}

// Function to conduct the examination
void conductExamination() {
    // Initialize students array
    Student students[10];

    // Get student data from user
    for (int i = 0; i < 10; i++) {
        printf("Enter student %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%s", students[i].rollNo);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Sort students based on marks
    qsort(students, 10, sizeof(Student), compareStudents);

    // Print student data in descending order of marks
    printf("Student data in descending order of marks:\n");
    for (int i = 0; i < 10; i++) {
        printStudent(students[i]);
    }
}

int main() {
    // Conduct the examination
    conductExamination();

    return 0;
}