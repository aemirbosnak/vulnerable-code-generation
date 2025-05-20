//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: peaceful
// Program to create a unique C Online Examination System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store student details
struct student {
    char name[50];
    char roll_no[10];
    int marks;
};

// Function to calculate the average of marks
float calculate_average(struct student students[], int num_students) {
    int i, sum = 0;
    for (i = 0; i < num_students; i++) {
        sum += students[i].marks;
    }
    return (float) sum / num_students;
}

// Function to display the student details
void display_students(struct student students[], int num_students) {
    int i;
    for (i = 0; i < num_students; i++) {
        printf("Name: %s\nRoll No: %s\nMarks: %d\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

// Function to sort the students based on their marks
void sort_students(struct student students[], int num_students) {
    int i, j, temp;
    for (i = 0; i < num_students - 1; i++) {
        for (j = i + 1; j < num_students; j++) {
            if (students[i].marks > students[j].marks) {
                temp = students[i].marks;
                students[i].marks = students[j].marks;
                students[j].marks = temp;
            }
        }
    }
}

int main() {
    struct student students[100];
    int num_students, i, j;

    // Get the number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Get the details of each student
    for (i = 0; i < num_students; i++) {
        printf("Enter the details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%s", students[i].roll_no);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Calculate the average of marks
    float average = calculate_average(students, num_students);
    printf("Average: %.2f\n", average);

    // Display the student details
    display_students(students, num_students);

    // Sort the students based on their marks
    sort_students(students, num_students);

    // Display the sorted student details
    display_students(students, num_students);

    return 0;
}