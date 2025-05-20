//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student information
typedef struct student {
    char name[20];
    int rollno;
    float marks;
} student;

// Function to compare students based on marks
int compare(student a, student b) {
    return (int) (a.marks - b.marks);
}

// Function to create a student
student createStudent() {
    student s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter roll no: ");
    scanf("%d", &s.rollno);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    return s;
}

// Function to display student information
void displayStudent(student s) {
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.rollno);
    printf("Marks: %.2f\n", s.marks);
}

// Function to find the student with the highest marks
student findHighestMarks(student students[], int n) {
    qsort(students, n, sizeof(student), compare);
    return students[0];
}

int main() {
    // Create an array of students
    student students[10];

    // Create and display student information
    for (int i = 0; i < 10; i++) {
        students[i] = createStudent();
        displayStudent(students[i]);
    }

    // Find the student with the highest marks
    student highestMarksStudent = findHighestMarks(students, 10);

    // Display the student with the highest marks
    displayStudent(highestMarksStudent);

    return 0;
}