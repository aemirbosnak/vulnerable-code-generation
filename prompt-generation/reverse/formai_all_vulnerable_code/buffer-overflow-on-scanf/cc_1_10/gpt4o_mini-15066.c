//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// Function prototypes
void add_student(Student *students, int *count);
void display_students(Student *students, int count);
void sort_students(Student *students, int count);
void search_student(Student *students, int count);
void free_memory(Student *students);

int main() {
    // Initialize variables
    Student *students = NULL;
    int count = 0;
    int choice;
    
    // Allocate enough memory for students dynamically
    students = (Student *)malloc(sizeof(Student) * 100);
    if(students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Menu loop
    do {
        printf("\n---- Student Management System ----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Sort Students by Score\n");
        printf("4. Search for a Student by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_student(students, &count);
                break;
            case 2:
                display_students(students, count);
                break;
            case 3:
                sort_students(students, count);
                printf("Students sorted by score.\n");
                break;
            case 4:
                search_student(students, count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    // Free the allocated memory
    free_memory(students);
    return 0;
}

// Function to add a student
void add_student(Student *students, int *count) {
    if (*count >= 100) {
        printf("Cannot add more students. Maximum reached.\n");
        return;
    }
    
    printf("Enter student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter student name: ");
    scanf(" %[^\n]", students[*count].name);  // Read string with spaces
    printf("Enter student score: ");
    scanf("%f", &students[*count].score);
    (*count)++;
    printf("Student added successfully.\n");
}

// Function to display all students
void display_students(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- List of Students ---\n");
    for(int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", 
               students[i].id, students[i].name, students[i].score);
    }
}

// Function to sort students by score
void sort_students(Student *students, int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            if (students[i].score > students[j].score) {
                // Swap students[i] and students[j]
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to search for a student by ID
void search_student(Student *students, int count) {
    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);
    for(int i = 0; i < count; i++) {
        if (students[i].id == search_id) {
            printf("Student found: ID: %d, Name: %s, Score: %.2f\n", 
                   students[i].id, students[i].name, students[i].score);
            return;
        }
    }
    printf("Student with ID %d not found.\n", search_id);
}

// Function to free allocated memory
void free_memory(Student *students) {
    free(students);
}