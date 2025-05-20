//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: multivariable
// This is a C program to create a simple online examination system in a multivariable style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct student {
    char name[100];
    int roll_no;
    int marks[10];
};

// Function to get student information
void get_student_info(struct student *s) {
    printf("Enter student name: ");
    fgets(s->name, 100, stdin);
    printf("Enter student roll number: ");
    scanf("%d", &s->roll_no);
    for (int i = 0; i < 10; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}

// Function to calculate total marks
int calculate_total_marks(struct student *s) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        total += s->marks[i];
    }
    return total;
}

// Function to calculate percentage
float calculate_percentage(struct student *s) {
    int total = calculate_total_marks(s);
    float percentage = (float)total / 1000;
    return percentage;
}

// Function to print student information
void print_student_info(struct student *s) {
    printf("Name: %s\n", s->name);
    printf("Roll Number: %d\n", s->roll_no);
    printf("Total Marks: %d\n", calculate_total_marks(s));
    printf("Percentage: %.2f%%\n", calculate_percentage(s));
}

int main() {
    struct student s;
    get_student_info(&s);
    print_student_info(&s);
    return 0;
}