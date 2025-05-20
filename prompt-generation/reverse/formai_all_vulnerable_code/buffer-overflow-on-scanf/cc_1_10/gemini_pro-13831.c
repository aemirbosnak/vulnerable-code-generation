//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
typedef struct student {
    char name[50];
    int roll_no;
    int marks[5];
} student;

// Function to get student data
void get_student_data(student *s) {
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter student roll number: ");
    scanf("%d", &s->roll_no);
    for (int i = 0; i < 5; i++) {
        printf("Enter marks in subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}

// Function to calculate total marks
int calculate_total_marks(student *s) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    return total;
}

// Function to calculate average marks
float calculate_average_marks(student *s) {
    float average = calculate_total_marks(s) / 5.0;
    return average;
}

// Function to print student data
void print_student_data(student *s) {
    printf("Student name: %s\n", s->name);
    printf("Student roll number: %d\n", s->roll_no);
    printf("Marks in each subject:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: %d\n", i + 1, s->marks[i]);
    }
    printf("Total marks: %d\n", calculate_total_marks(s));
    printf("Average marks: %.2f\n", calculate_average_marks(s));
}

int main() {
    // Create an array of students
    student students[100];

    // Get the number of students
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Get the data for each student
    for (int i = 0; i < num_students; i++) {
        printf("\nEnter data for student %d:\n", i + 1);
        get_student_data(&students[i]);
    }

    // Print the data for each student
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);
        print_student_data(&students[i]);
    }

    return 0;
}