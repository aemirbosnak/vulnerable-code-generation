//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the student structure
typedef struct Student {
    char name[50];
    int roll_no;
    float marks[5];
    struct Student* next;
} Student;

// Function to insert a student at the end
void insert_student(Student** head) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    printf("Enter student name: ");
    scanf("%s", new_student->name);
    printf("Enter student roll number: ");
    scanf("%d", &new_student->roll_no);
    printf("Enter student marks: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &new_student->marks[i]);
    }

    if (*head == NULL) {
        *head = new_student;
    } else {
        (*head)->next = new_student;
    }

    new_student->next = NULL;
}

// Function to calculate the average marks of a student
float calculate_average(Student* student) {
    float total_marks = 0.0f;
    for (int i = 0; i < 5; i++) {
        total_marks += student->marks[i];
    }
    return total_marks / 5.0f;
}

// Function to print the student details
void print_student(Student* student) {
    printf("Name: %s\n", student->name);
    printf("Roll No: %d\n", student->roll_no);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%f ", student->marks[i]);
    }
    printf("\n");
}

int main() {
    Student* head = NULL;

    // Insert students
    insert_student(&head);
    insert_student(&head);
    insert_student(&head);

    // Print student details
    print_student(head);

    // Calculate average marks
    float average_marks = calculate_average(head);

    // Print average marks
    printf("Average marks: %f\n", average_marks);

    return 0;
}