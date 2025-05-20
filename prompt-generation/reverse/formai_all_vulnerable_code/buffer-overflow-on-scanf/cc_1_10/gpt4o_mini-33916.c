//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Student
typedef struct {
    int id;
    char name[100];
    float gpa;
} Student;

// Function to add a new student
void addStudent(Student* students, int* count) {
    printf("Enter Student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", students[*count].name);
    printf("Enter Student GPA: ");
    scanf("%f", &students[*count].gpa);
    
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(const Student* students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    
    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Function to search for a student by ID
void searchStudent(const Student* students, int count) {
    int searchId;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("Student found! ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", searchId);
}

// Function to delete a student by ID
void deleteStudent(Student* students, int* count) {
    int deleteId;
    printf("Enter Student ID to delete: ");
    scanf("%d", &deleteId);
    
    for (int i = 0; i < *count; i++) {
        if (students[i].id == deleteId) {
            students[i] = students[*count - 1]; // Replace with last student
            (*count)--; // Decrease count
            printf("Student with ID %d deleted successfully!\n", deleteId);
            return;
        }
    }
    printf("Student with ID %d not found.\n", deleteId);
}

// Function to sort students by GPA
void sortStudentsByGPA(Student* students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].gpa > students[j + 1].gpa) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by GPA successfully!\n");
}

// Function to show the menu
void showMenu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Sort Students by GPA\n");
    printf("6. Exit\n");
}

int main() {
    Student students[100];
    int count = 0;
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                sortStudentsByGPA(students, count);
                displayStudents(students, count); // Show sorted results
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}