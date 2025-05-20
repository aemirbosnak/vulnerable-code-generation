//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct {
    int id;
    char name[50];
    float grades[5];
    float average;
} Student;

// Function to calculate the average of grades
float calculateAverage(float grades[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += grades[i];
    }
    return total / count;
}

// Function to perform input of student data
void inputStudentData(Student *s) {
    printf("Enter student ID: ");
    scanf("%d", &s->id);
    printf("Enter student name: ");
    getchar(); // To consume newline character left by previous input
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0; // Remove newline character

    // Input grades
    for (int i = 0; i < 5; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%f", &s->grades[i]);
    }

    // Calculate average
    s->average = calculateAverage(s->grades, 5);
}

// Function to display student data
void displayStudentData(Student s) {
    printf("Student ID: %d\n", s.id);
    printf("Student Name: %s\n", s.name);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", s.grades[i]);
    }
    printf("\nAverage Grade: %.2f\n", s.average);
}

// Function to save student data to a file
void saveToFile(Student s) {
    FILE *file = fopen("students.dat", "a");
    if (file) {
        fprintf(file, "%d;%s;%.2f;%.2f;%.2f;%.2f;%.2f\n", 
                s.id, s.name, 
                s.grades[0], s.grades[1], 
                s.grades[2], s.grades[3], 
                s.grades[4]);
        fclose(file);
    } else {
        printf("Error: Could not open file for writing.\n");
    }
}

// Function to read students from a file
void readFromFile() {
    FILE *file = fopen("students.dat", "r");
    if (file) {
        char line[256];
        printf("Reading student data from file:\n");
        while (fgets(line, sizeof(line), file)) {
            int id;
            char name[50];
            float grades[5];

            sscanf(line, "%d;%49[^;];%f;%f;%f;%f;%f", &id, name, 
                   &grades[0], &grades[1], grades[2], grades[3], grades[4]);

            printf("ID: %d, Name: %s, Grades: ", id, name);
            for (int i = 0; i < 5; i++) {
                printf("%.2f ", grades[i]);
            }
            printf("\n");
        }
        fclose(file);
    } else {
        printf("Error: Could not open file for reading.\n");
    }
}

// Main function
int main() {
    int choice;
    Student student;
    
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Input Student Data\n");
        printf("2. Display Student Data\n");
        printf("3. Save Student Data to File\n");
        printf("4. Read Student Data from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStudentData(&student);
                printf("Student data input complete.\n");
                break;
            case 2:
                displayStudentData(student);
                break;
            case 3:
                saveToFile(student);
                printf("Student data saved to file.\n");
                break;
            case 4:
                readFromFile();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}