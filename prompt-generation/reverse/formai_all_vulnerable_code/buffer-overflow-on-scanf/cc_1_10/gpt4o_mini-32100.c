//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student information
typedef struct Student {
    int id;
    char name[50];
    float grade;
} Student;

// Function prototypes
void addStudent(Student *students, int *count);
void displayStudents(Student *students, int count);
void indexStudents(Student *students, int count);

int main() {
    // Array of students
    Student students[100];
    int count = 0;
    int choice;

    printf("🎉 Welcome to the Happy Student Database System! 🎉\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Index and Display Students by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                indexStudents(students, count);
                break;
            case 4:
                printf("🌈 Thank you for using the Happy Student Database System! 🌈\n");
                exit(0);
            default:
                printf("🚫 Invalid choice! Please try again. 🚫\n");
        }
    }

    return 0;
}

// Function to add a student
void addStudent(Student *students, int *count) {
    if (*count >= 100) {
        printf("😢 Sorry, we can't add more students! Limit reached. 😢\n");
        return;
    }

    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student grade: ");
    scanf("%f", &newStudent.grade);
    
    students[*count] = newStudent;  // Save the new student
    (*count)++;  // Increase the count
    printf("🎈 Student added successfully! 🎈\n");
}

// Function to display all students
void displayStudents(Student *students, int count) {
    if (count == 0) {
        printf("😊 No students to display! 😊\n");
        return;
    }

    printf("\n📚 List of Students 📚\n");
    printf("ID\tName\t\tGrade\n");
    printf("--\t----\t\t-----\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }

    printf("🎉 Display complete! 🎉\n");
}

// Function to index and display students by ID
void indexStudents(Student *students, int count) {
    if (count == 0) {
        printf("😊 No students to index! 😊\n");
        return;
    }

    // Simple bubble sort to index students by ID
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("\n🚀 Indexed Students List (by ID) 🚀\n");
    printf("ID\tName\t\tGrade\n");
    printf("--\t----\t\t-----\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }

    printf("🎊 Indexing complete! 🎊\n");
}