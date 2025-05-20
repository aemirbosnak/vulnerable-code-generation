//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
typedef struct Student {
    char name[50];
    char id[20];
    int marks;
} Student;

// Prototype for functions
void displayMenu();
void addStudent(Student *students, int *numStudents);
void removeStudent(Student *students, int *numStudents);
void displayStudents(Student *students, int numStudents);
void searchStudent(Student *students, int numStudents);
void saveStudentsToFile(Student *students, int numStudents);
void loadStudentsFromFile(Student *students, int *numStudents);

// Main function
int main() {

    // Initialize student database
    Student students[100];
    int numStudents = 0;

    // Display menu and get user choice
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                removeStudent(students, &numStudents);
                break;
            case 3:
                displayStudents(students, numStudents);
                break;
            case 4:
                searchStudent(students, numStudents);
                break;
            case 5:
                saveStudentsToFile(students, numStudents);
                break;
            case 6:
                loadStudentsFromFile(students, &numStudents);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}

// Display menu options
void displayMenu() {
    printf("\n\nOnline Examination System Menu\n\n");
    printf("1. Add Student\n");
    printf("2. Remove Student\n");
    printf("3. Display Students\n");
    printf("4. Search Student\n");
    printf("5. Save Students to File\n");
    printf("6. Load Students from File\n");
    printf("7. Exit\n\n");
    printf("Enter your choice: ");
}

// Add a new student to the database
void addStudent(Student *students, int *numStudents) {

    // Get student details
    printf("Enter student name: ");
    scanf(" %[^\n]s", students[*numStudents].name);
    printf("Enter student ID: ");
    scanf(" %[^\n]s", students[*numStudents].id);
    printf("Enter student marks: ");
    scanf("%d", &students[*numStudents].marks);

    // Increment the number of students
    (*numStudents)++;

    printf("Student added successfully!\n");
}

// Remove a student from the database
void removeStudent(Student *students, int *numStudents) {

    // Get student ID
    char id[20];
    printf("Enter student ID: ");
    scanf(" %[^\n]s", id);

    // Find student index
    int index = -1;
    for (int i = 0; i < *numStudents; i++) {
        if (strcmp(students[i].id, id) == 0) {
            index = i;
            break;
        }
    }

    // If student found, remove them from the database
    if (index != -1) {
        for (int i = index; i < *numStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        (*numStudents)--;
        printf("Student removed successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}

// Display all students in the database
void displayStudents(Student *students, int numStudents) {

    if (numStudents == 0) {
        printf("No students found!\n");
    } else {
        printf("Students:\n");
        for (int i = 0; i < numStudents; i++) {
            printf("%s\t%s\t%d\n", students[i].name, students[i].id, students[i].marks);
        }
    }
}

// Search for a student in the database
void searchStudent(Student *students, int numStudents) {

    // Get student ID
    char id[20];
    printf("Enter student ID: ");
    scanf(" %[^\n]s", id);

    // Find student index
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, id) == 0) {
            index = i;
            break;
        }
    }

    // If student found, display their details
    if (index != -1) {
        printf("Student found:\n");
        printf("Name: %s\n", students[index].name);
        printf("ID: %s\n", students[index].id);
        printf("Marks: %d\n", students[index].marks);
    } else {
        printf("Student not found!\n");
    }
}

// Save students to a file
void saveStudentsToFile(Student *students, int numStudents) {

    // Open file for writing
    FILE *fp = fopen("students.txt", "w");

    // Write student data to file
    for (int i = 0; i < numStudents; i++) {
        fprintf(fp, "%s %s %d\n", students[i].name, students[i].id, students[i].marks);
    }

    // Close file
    fclose(fp);

    printf("Students saved to file successfully!\n");
}

// Load students from a file
void loadStudentsFromFile(Student *students, int *numStudents) {

    // Open file for reading
    FILE *fp = fopen("students.txt", "r");

    // Read student data from file
    char name[50], id[20];
    int marks;
    while (fscanf(fp, "%s %s %d\n", name, id, &marks) != EOF) {
        strcpy(students[*numStudents].name, name);
        strcpy(students[*numStudents].id, id);
        students[*numStudents].marks = marks;
        (*numStudents)++;
    }

    // Close file
    fclose(fp);

    printf("Students loaded from file successfully!\n");
}