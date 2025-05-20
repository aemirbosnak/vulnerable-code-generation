//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a student
typedef struct student_t {
    int id;
    char name[50];
    int age;
    float gpa;
} student;

// Define the function prototypes
void print_menu();
void add_student();
void display_student();
void search_student();
void display_student_list();

// Define the database (an array of students)
student students[100];
int num_students = 0;

// Main function
int main() {
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_student();
                break;
            case 3:
                search_student();
                break;
            case 4:
                display_student_list();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
        
    } while (choice != 5);
    
    return 0;
}

// Function to print the menu options
void print_menu() {
    printf("----- Student Database -----");
    printf("\n1. Add a student");
    printf("\n2. Display a student");
    printf("\n3. Search for a student");
    printf("\n4. Display all students");
    printf("\n5. Exit");
}

// Function to add a new student to the database
void add_student() {
    if (num_students >= 100) {
        printf("Database is full. Cannot add any more students.\n");
        return;
    }
    
    student new_student;
    
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    
    printf("Enter student age: ");
    scanf("%d", &new_student.age);
    
    printf("Enter student GPA: ");
    scanf("%f", &new_student.gpa);
    
    students[num_students] = new_student;
    num_students++;
    
    printf("Student added successfully!\n");
}

// Function to display a student's information
void display_student() {
    int id;
    
    printf("Enter student ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("GPA: %.2f\n", students[i].gpa);
            return;
        }
    }
    
    printf("Student not found.\n");
}

// Function to search for a student by name or ID
void search_student() {
    int choice;
    
    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. ID\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        char name[50];
        printf("Enter student name: ");
        scanf("%s", name);
        
        // Search for the student by name
        for (int i = 0; i < num_students; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("GPA: %.2f\n", students[i].gpa);
                return;
            }
        }
        
        printf("Student not found.\n");
        
    } else if (choice == 2) {
        int id;
        printf("Enter student ID: ");
        scanf("%d", &id);
        
        // Search for the student by ID
        for (int i = 0; i < num_students; i++) {
            if (students[i].id == id) {
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("GPA: %.2f\n", students[i].gpa);
                return;
            }
        }
        
        printf("Student not found.\n");
        
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to display a list of all students
void display_student_list() {
    printf("List of all students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }
}