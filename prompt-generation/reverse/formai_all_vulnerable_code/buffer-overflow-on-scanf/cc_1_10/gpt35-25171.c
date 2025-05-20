//FormAI DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>

// Structure to store student information
struct Student {
    int id;
    char name[50];
    float marks;
};

// Function to read student details
void readStudent(struct Student *student) {
    printf("Enter student id: ");
    scanf("%d", &student->id);
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter student marks: ");
    scanf("%f", &student->marks);
}

// Function to display student details
void displayStudent(struct Student student) {
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);
}

int main() {
    int n; // number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Create array of students dynamically
    struct Student *students = (struct Student *) malloc(n * sizeof(struct Student));
    if(students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read student details
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        readStudent(&students[i]);
    }

    // Display student details
    printf("\nStudent Details:\n");
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        displayStudent(students[i]);
    }

    // Free memory allocated for students array
    free(students);

    return 0;
}