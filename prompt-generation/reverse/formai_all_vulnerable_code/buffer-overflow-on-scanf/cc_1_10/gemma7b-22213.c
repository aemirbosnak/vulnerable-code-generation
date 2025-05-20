//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the student structure
typedef struct student {
    char name[50];
    int roll_no;
    float marks;
} student;

// Function to compare students
int compare_students(student a, student b) {
    return a.marks - b.marks;
}

int main() {
    // Create an array of students
    student students[MAX_STUDENTS];

    // Get the number of students
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Populate the student array
    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the roll number of student %d: ", i + 1);
        scanf("%d", &students[i].roll_no);

        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &students[i].marks);
    }

    // Sort the students in descending order
    qsort(students, num_students, sizeof(student), compare_students);

    // Print the sorted students
    printf("The sorted students are:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    return 0;
}