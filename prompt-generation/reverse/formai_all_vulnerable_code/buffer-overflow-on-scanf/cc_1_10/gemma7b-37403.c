//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student information
struct student {
    char name[50];
    int rollno;
    float marks;
    char status;
};

// Function to compare two students
int compareStudents(struct student *a, struct student *b) {
    return strcmp(a->name, b->name);
}

// Function to calculate the average marks
float calculateAverage(struct student *s) {
    return (s->marks) / 2;
}

// Function to display student information
void displayStudent(struct student *s) {
    printf("Name: %s\n", s->name);
    printf("Roll No.: %d\n", s->rollno);
    printf("Marks: %.2f\n", s->marks);
    printf("Status: %c\n", s->status);
}

int main() {
    // Create an array of students
    struct student students[10];

    // Initialize the students
    for (int i = 0; i < 10; i++) {
        students[i].name[0] = '\0';
        students[i].rollno = 0;
        students[i].marks = 0.0f;
        students[i].status = '\0';
    }

    // Get the student information
    printf("Enter the student's name: ");
    scanf("%s", students[0].name);

    printf("Enter the student's roll number: ");
    scanf("%d", &students[0].rollno);

    printf("Enter the student's marks: ");
    scanf("%f", &students[0].marks);

    // Calculate the student's average marks
    students[0].marks = calculateAverage(&students[0]);

    // Display the student's information
    displayStudent(&students[0]);

    // Compare the students
    struct student *a = &students[0];
    struct student *b = &students[1];
    int comparison = compareStudents(a, b);

    // Print the comparison result
    if (comparison == 0) {
        printf("Students are equal.\n");
    } else {
        printf("Students are not equal.\n");
    }

    return 0;
}