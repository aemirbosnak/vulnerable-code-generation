//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store student data
typedef struct Student {
    char name[20];
    int roll_no;
    float marks;
} Student;

// Function to compare two students
int compareStudents(Student *a, Student *b) {
    return strcmp(a->name, b->name);
}

// Function to calculate the average marks of a student
float calculateAverageMarks(Student *s) {
    return (s->marks) / 3;
}

// Main function
int main() {
    // Create an array of students
    Student students[100];

    // Initialize the students
    for (int i = 0; i < 100; i++) {
        students[i].name[0] = '\0';
        students[i].roll_no = 0;
        students[i].marks = 0.0f;
    }

    // Get the student data from the user
    printf("Enter the name of the student: ");
    scanf("%s", students[0].name);

    printf("Enter the roll number of the student: ");
    scanf("%d", &students[0].roll_no);

    printf("Enter the marks of the student: ");
    scanf("%f", &students[0].marks);

    // Calculate the average marks of the student
    float averageMarks = calculateAverageMarks(&students[0]);

    // Print the average marks of the student
    printf("The average marks of the student are: %.2f", averageMarks);

    // Sort the students in descending order
    qsort(students, 100, sizeof(Student), compareStudents);

    // Print the sorted students
    for (int i = 0; i < 100; i++) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    return 0;
}