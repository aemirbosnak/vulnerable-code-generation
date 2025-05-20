//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student data
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Function to allocate memory for an array of students
Student* create_student_array(int count) {
    Student* students = (Student*)malloc(count * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return students;
}

// Function to populate student data
void populate_students(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        students[i].id = i + 1;
        printf("Enter name for student %d: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline
        printf("Enter GPA for student %d: ", i + 1);
        scanf("%f", &students[i].gpa);
        getchar(); // To consume newline character left in buffer
    }
}

// Function to display all student data
void display_students(const Student* students, int count) {
    printf("\nStudent Details:\n");
    printf("ID\tName\t\tGPA\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Function to find student by ID
void find_student_by_id(const Student* students, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\nName: %s\nGPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to free allocated memory
void free_student_array(Student* students) {
    free(students);
}

int main() {
    int number_of_students;

    printf("Enter the number of students: ");
    scanf("%d", &number_of_students);
    getchar(); // consume the newline character

    // Create an array of students
    Student* students = create_student_array(number_of_students);

    // Populate student data
    populate_students(students, number_of_students);

    // Display all student data
    display_students(students, number_of_students);

    // Find a student by ID
    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);
    find_student_by_id(students, number_of_students, search_id);

    // Free allocated memory
    free_student_array(students);
    
    printf("Memory has been successfully freed.\n");

    return 0;
}