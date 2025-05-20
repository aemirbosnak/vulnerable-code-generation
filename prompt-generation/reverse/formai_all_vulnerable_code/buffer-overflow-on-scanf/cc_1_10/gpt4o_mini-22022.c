//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This structure represents a student's record
typedef struct {
    int id;
    char name[50];
    float grades[5];
    float average;
} Student;

// Function declarations
void inputStudentData(Student *student);
void calculateAverage(Student *student);
void displayStudentData(const Student *student);
void saveStudentDataToFile(const Student *student, const char *filename);

int main() {
    // Initializes a student structure
    Student student;
    char filename[] = "student_data.txt";
    
    // Input student data
    inputStudentData(&student);
    
    // Calculate average grades
    calculateAverage(&student);
    
    // Display student data
    displayStudentData(&student);
    
    // Save student data to a file
    saveStudentDataToFile(&student, filename);
    
    return 0; // Exit successfully
}

// Function to input student data
void inputStudentData(Student *student) {
    printf("Enter Student ID: ");
    scanf("%d", &student->id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student->name);
    
    // Input grades
    for (int i = 0; i < 5; i++) {
        printf("Enter Grade %d: ", i + 1);
        scanf("%f", &student->grades[i]);
    }
}

// Function to calculate the average of the grades
void calculateAverage(Student *student) {
    float total = 0;
    
    for (int i = 0; i < 5; i++) {
        total += student->grades[i];
    }
    
    // Calculate the average
    student->average = total / 5;
}

// Function to display student data
void displayStudentData(const Student *student) {
    printf("\n--- Student Data ---\n");
    printf("ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    
    // Display grades
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student->grades[i]);
    }
    
    // Display average
    printf("\nAverage Grade: %.2f\n", student->average);
}

// Function to save student data to a file
void saveStudentDataToFile(const Student *student, const char *filename) {
    FILE *file = fopen(filename, "w");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    
    // Write student data to the file
    fprintf(file, "ID: %d\n", student->id);
    fprintf(file, "Name: %s\n", student->name);
    fprintf(file, "Grades: ");
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%.2f ", student->grades[i]);
    }
    fprintf(file, "\nAverage Grade: %.2f\n", student->average);
    
    // Close the file
    fclose(file);
    
    // Inform the user that data has been saved
    printf("\nStudent data saved to %s\n", filename);
}