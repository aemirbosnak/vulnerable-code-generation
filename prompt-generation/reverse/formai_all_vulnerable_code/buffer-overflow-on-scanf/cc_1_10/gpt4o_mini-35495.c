//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for a Student
typedef struct {
    int id;
    char name[50];
    char major[50];
    float gpa;
} Student;

// Function declarations
void addStudent(Student *students, int *count);
void displayStudents(Student *students, int count);
void saveToFile(Student *students, int count);
void loadFromFile(Student *students, int *count);
void clearScreen();

// Main function to run the database simulation
int main() {
    Student students[100]; // Maximum of 100 students
    int count = 0;
    int choice;

    loadFromFile(students, &count);

    while (1) {
        clearScreen();
        printf("=== Student Database ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save Changes\n");
        printf("4. Load Students from File\n");
        printf("5. Exit\n");
        printf("========================\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count);
                break;
            case 4:
                loadFromFile(students, &count);
                break;
            case 5:
                saveToFile(students, count);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option, try again.\n");
        }

        printf("Press Enter to continue...");
        while (getchar() != '\n'); // Clear input buffer
        getchar(); // Wait for user to press enter
    }

    return 0;
}

// Function to clear the terminal screen
void clearScreen() {
    // Using ANSI escape code to clear the screen
    printf("\033[H\033[J");
}

// Function to add a student
void addStudent(Student *students, int *count) {
    if (*count >= 100) {
        printf("Database is full!\n");
        return;
    }
    Student newStudent;
    printf("Enter ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter Name: ");
    getchar(); // Clear newline from buffer
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove newline
    printf("Enter Major: ");
    fgets(newStudent.major, sizeof(newStudent.major), stdin);
    newStudent.major[strcspn(newStudent.major, "\n")] = 0; // Remove newline
    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(Student *students, int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }
    printf("ID\tName\t\tMajor\t\tGPA\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%-10s\t%.2f\n", students[i].id, students[i].name, students[i].major, students[i].gpa);
    }
}

// Function to save student data to a file
void saveToFile(Student *students, int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

// Function to load student data from a file
void loadFromFile(Student *students, int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No existing data to load.\n");
        return;
    }
    *count = fread(students, sizeof(Student), 100, file);
    fclose(file);
    printf("%d students loaded successfully!\n", *count);
}