//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student data structure
typedef struct Student {
    char name[20];
    int rollno;
    float marks;
} Student;

// Function to compare students based on marks
int compareStudents(Student *a, Student *b) {
    return (int)(a->marks - b->marks);
}

// Function to print student data
void printStudent(Student *s) {
    printf("Name: %s\n", s->name);
    printf("Roll No: %d\n", s->rollno);
    printf("Marks: %.2f\n", s->marks);
}

// Main function
int main() {
    // Create an array of students
    Student students[10];

    // Initialize the students
    for (int i = 0; i < 10; i++) {
        students[i].name[0] = '\0';
        students[i].rollno = 0;
        students[i].marks = 0.0f;
    }

    // Get the student data from the user
    printf("Enter the student's name: ");
    scanf("%s", students[0].name);

    printf("Enter the student's roll number: ");
    scanf("%d", &students[0].rollno);

    printf("Enter the student's marks: ");
    scanf("%f", &students[0].marks);

    // Print the student data
    printStudent(&students[0]);

    // Sort the students based on marks
    qsort(students, 10, sizeof(Student), compareStudents);

    // Print the sorted students
    for (int i = 0; i < 10; i++) {
        printStudent(&students[i]);
    }

    return 0;
}