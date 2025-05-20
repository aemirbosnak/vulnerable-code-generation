//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
// Program to create a unique C Online Examination System example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct student {
    char name[100];
    char roll_no[10];
    char subject[10];
    int marks;
};

// Function to display student details
void display_student(struct student s) {
    printf("Name: %s\n", s.name);
    printf("Roll No: %s\n", s.roll_no);
    printf("Subject: %s\n", s.subject);
    printf("Marks: %d\n", s.marks);
}

// Function to calculate total marks
int calculate_total_marks(struct student s[]) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        total += s[i].marks;
    }
    return total;
}

// Function to calculate average marks
float calculate_average_marks(struct student s[]) {
    int total = calculate_total_marks(s);
    return (float)total / 3;
}

// Main function
int main() {
    // Create an array of student structures
    struct student students[3];

    // Get details of first student
    printf("Enter details of student 1:\n");
    printf("Name: ");
    scanf("%s", students[0].name);
    printf("Roll No: ");
    scanf("%s", students[0].roll_no);
    printf("Subject: ");
    scanf("%s", students[0].subject);
    printf("Marks: ");
    scanf("%d", &students[0].marks);

    // Get details of second student
    printf("Enter details of student 2:\n");
    printf("Name: ");
    scanf("%s", students[1].name);
    printf("Roll No: ");
    scanf("%s", students[1].roll_no);
    printf("Subject: ");
    scanf("%s", students[1].subject);
    printf("Marks: ");
    scanf("%d", &students[1].marks);

    // Get details of third student
    printf("Enter details of student 3:\n");
    printf("Name: ");
    scanf("%s", students[2].name);
    printf("Roll No: ");
    scanf("%s", students[2].roll_no);
    printf("Subject: ");
    scanf("%s", students[2].subject);
    printf("Marks: ");
    scanf("%d", &students[2].marks);

    // Calculate total marks
    int total_marks = calculate_total_marks(students);

    // Calculate average marks
    float average_marks = calculate_average_marks(students);

    // Display student details
    for (int i = 0; i < 3; i++) {
        display_student(students[i]);
    }

    // Display total marks and average marks
    printf("Total Marks: %d\n", total_marks);
    printf("Average Marks: %.2f\n", average_marks);

    return 0;
}