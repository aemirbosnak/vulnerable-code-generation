//FormAI DATASET v1.0 Category: Database simulation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define constants
#define MAX_NAME_SIZE 20
#define MAX_STUDENT_COUNT 100

// Define a struct to represent a student
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
    float gpa;
} Student;

// Declare functions
void displayMenu();
void addStudent(Student* studentList, int* studentCount);
void removeStudent(Student* studentList, int* studentCount);
void getStudentById(Student* studentList, int studentCount);
void displayAllStudents(Student* studentList, int studentCount);
void saveToDatabase(Student* studentList, int studentCount);
void readFromDatabase(Student* studentList, int* studentCount);

int main() {
    // Declare variables
    int option, studentCount = 0;
    Student studentList[MAX_STUDENT_COUNT];
    
    // Display menu and get user input
    do {
        displayMenu();
        scanf("%d", &option);
        
        // Perform option selected by user
        switch(option) {
            case 1:
                addStudent(studentList, &studentCount);
                break;
            case 2:
                removeStudent(studentList, &studentCount);
                break;
            case 3:
                getStudentById(studentList, studentCount);
                break;
            case 4:
                displayAllStudents(studentList, studentCount);
                break;
            case 5:
                saveToDatabase(studentList, studentCount);
                break;
            case 6:
                readFromDatabase(studentList, &studentCount);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
        }
        
        // Clear input buffer
        fflush(stdin);
    } while(option != 7);
    
    return 0;
}

void displayMenu() {
    printf("\n-----Student Database-----");
    printf("\n1. Add Student");
    printf("\n2. Remove Student");
    printf("\n3. Get Student by ID");
    printf("\n4. Display All Students");
    printf("\n5. Save to Database");
    printf("\n6. Read from Database");
    printf("\n7. Exit program");
    printf("\nEnter option number: ");
}

void addStudent(Student* studentList, int* studentCount) {
    // Check if student list is full
    if(*studentCount == MAX_STUDENT_COUNT) {
        printf("\nStudent list is full. Cannot add new student.\n");
        return;
    }
    
    // Get inputs from user
    Student newStudent;
    printf("\nEnter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);
    
    // Add new student to list
    studentList[*studentCount] = newStudent;
    (*studentCount)++;
    
    printf("\nStudent added successfully.\n");
}

void removeStudent(Student* studentList, int* studentCount) {
    // Check if student list is empty
    if(*studentCount == 0) {
        printf("\nStudent list is empty. Cannot remove student.\n");
        return;
    }
    
    // Get inputs from user
    int id, i;
    printf("\nEnter student ID to remove: ");
    scanf("%d", &id);
    
    // Search for student by ID and remove if found
    for(i=0; i<*studentCount; i++) {
        if(studentList[i].id == id) {
            // Shift all students after the removed student back by one
            int j;
            for(j=i; j<*studentCount-1; j++) {
                studentList[j] = studentList[j+1];
            }
            (*studentCount)--;
            printf("\nStudent removed successfully.\n");
            return;
        }
    }
    
    // Student not found
    printf("\nStudent with ID %d not found.\n", id);
}

void getStudentById(Student* studentList, int studentCount) {
    // Check if student list is empty
    if(studentCount == 0) {
        printf("\nStudent list is empty. Cannot get student.\n");
        return;
    }
    
    // Get inputs from user
    int id, i;
    printf("\nEnter student ID to get: ");
    scanf("%d", &id);
    
    // Search for student by ID and display if found
    for(i=0; i<studentCount; i++) {
        if(studentList[i].id == id) {
            printf("\nStudent ID: %d", studentList[i].id);
            printf("\nStudent Name: %s", studentList[i].name);
            printf("\nStudent GPA: %.2f\n", studentList[i].gpa);
            return;
        }
    }
    
    // Student not found
    printf("\nStudent with ID %d not found.\n", id);
}

void displayAllStudents(Student* studentList, int studentCount) {
    // Check if student list is empty
    if(studentCount == 0) {
        printf("\nStudent list is empty.\n");
        return;
    }
    
    // Loop through all students in list and display
    int i;
    for(i=0; i<studentCount; i++) {
        printf("\nStudent ID: %d", studentList[i].id);
        printf("\nStudent Name: %s", studentList[i].name);
        printf("\nStudent GPA: %.2f\n", studentList[i].gpa);
    }
}

void saveToDatabase(Student* studentList, int studentCount) {
    // Check if student list is empty
    if(studentCount == 0) {
        printf("\nStudent list is empty. Cannot save to database.\n");
        return;
    }
    
    // Open database file for writing
    FILE* file = fopen("database.txt", "w");
    if(file == NULL) {
        printf("\nError opening database file.\n");
        return;
    }
    
    // Write all student data to file
    int i;
    for(i=0; i<studentCount; i++) {
        fprintf(file, "%d %s %.2f\n", studentList[i].id, studentList[i].name, studentList[i].gpa);
    }
    
    fclose(file);
    printf("\nStudent data saved to database.\n");
}

void readFromDatabase(Student* studentList, int* studentCount) {
    // Open database file for reading
    FILE* file = fopen("database.txt", "r");
    if(file == NULL) {
        printf("\nError opening database file.\n");
        return;
    }
    
    // Read all student data from file
    int id;
    char name[MAX_NAME_SIZE];
    float gpa;
    while(fscanf(file, "%d %s %f", &id, name, &gpa) == 3) {
        Student student = {id, name, gpa};
        studentList[*studentCount] = student;
        (*studentCount)++;
    }
    
    fclose(file);
    printf("\nStudent data read from database.\n");
}