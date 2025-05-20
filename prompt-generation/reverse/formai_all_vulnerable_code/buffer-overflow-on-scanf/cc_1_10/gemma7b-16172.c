//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student information
struct Student {
    char name[50];
    int rollNo;
    float marks[10];
    char grade;
};

// Function to calculate the average marks of a student
float calculateAverage(struct Student student) {
    int i = 0;
    float totalMarks = 0.0f;
    for (i = 0; i < 10; i++) {
        totalMarks += student.marks[i];
    }
    return totalMarks / 10.0f;
}

// Function to determine the grade of a student
char determineGrade(float averageMarks) {
    if (averageMarks >= 90) {
        return 'A';
    } else if (averageMarks >= 80) {
        return 'B';
    } else if (averageMarks >= 70) {
        return 'C';
    } else if (averageMarks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    // Create an array of students
    struct Student students[100];

    // Get the student information
    printf("Enter the student's name: ");
    scanf("%s", students[0].name);

    printf("Enter the student's roll number: ");
    scanf("%d", &students[0].rollNo);

    // Get the student's marks
    printf("Enter the student's marks: ");
    scanf("%f", &students[0].marks[0]);

    // Calculate the student's average marks
    float averageMarks = calculateAverage(students[0]);

    // Determine the student's grade
    char grade = determineGrade(averageMarks);

    // Print the student's grade
    printf("The student's grade is: %c", grade);

    return 0;
}