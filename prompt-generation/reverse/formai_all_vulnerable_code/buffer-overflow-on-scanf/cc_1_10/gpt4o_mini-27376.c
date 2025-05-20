//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a Student
typedef struct {
    int id;
    char name[50];
    float grades[5];
    float average;
} Student;

// Function to calculate the average of grades
float calculate_average(float grades[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum / count;
}

// Function to display a student’s information
void display_student(Student student) {
    printf("Student ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student.grades[i]);
    }
    printf("\nAverage: %.2f\n\n", student.average);
}

// Function to add a new student
void add_student(Student *students, int *count) {
    if (*count >= 100) {
        printf("Maximum student limit reached.\n");
        return;
    }
    
    Student new_student;
    new_student.id = *count + 1; // ID is count + 1 for unique id assignment

    printf("Enter name of student: ");
    scanf("%s", new_student.name);
    
    printf("Enter 5 grades: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &new_student.grades[i]);
    }
    
    new_student.average = calculate_average(new_student.grades, 5);
    students[*count] = new_student;
    (*count)++;
}

// Function to remove a student by ID
void remove_student(Student *students, int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with ID %d removed.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to display all students
void display_all_students(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        display_student(students[i]);
    }
}

int main() {
    Student students[100];
    int student_count = 0;
    int choice, id;

    while (1) {
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student(students, &student_count);
                break;
            case 2:
                printf("Enter the ID of the student to remove: ");
                scanf("%d", &id);
                remove_student(students, &student_count, id);
                break;
            case 3:
                display_all_students(students, student_count);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}