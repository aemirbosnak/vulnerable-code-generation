//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Function to allocate memory for an array of students
Student* createStudentArray(int numStudents) {
    return (Student*)malloc(numStudents * sizeof(Student));
}

// Function to fill student details
void fillStudentDetails(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].id = i + 1; // Assign ID starting from 1
        printf("Enter name for student %d: ", students[i].id);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline character
        printf("Enter GPA for student %d: ", students[i].id);
        scanf("%f", &students[i].gpa);
        getchar(); // Clear newline character from buffer
    }
}

// Function to print student details
void printStudentDetails(Student* students, int numStudents) {
    printf("\nStudent Details:\n");
    printf("ID\tName\t\tGPA\n");
    printf("------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Function to sort students by GPA
void sortStudentsByGPA(Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                // Swap the students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int numStudents;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);
    getchar(); // Clear newline character from buffer

    // Allocate memory for students
    Student* students = createStudentArray(numStudents);
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Fill and print students
    fillStudentDetails(students, numStudents);
    printStudentDetails(students, numStudents);

    // Sort and print sorted students
    sortStudentsByGPA(students, numStudents);
    printf("\nStudents sorted by GPA (high to low):\n");
    printStudentDetails(students, numStudents);

    // Free allocated memory
    free(students);
    return 0;
}