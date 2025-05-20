//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int score;
} Student;

int main() {
    // Create an array of students
    Student students[] = {
        {1, "John Doe", 90},
        {2, "Jane Smith", 85},
        {3, "Michael Jones", 95},
        {4, "Sarah Miller", 80},
        {5, "William Brown", 75}
    };

    // Get the number of students
    int num_students = sizeof(students) / sizeof(students[0]);

    // Print the list of students
    printf("List of students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d: %s (%d)\n", students[i].id, students[i].name, students[i].score);
    }

    // Get the student's ID
    int id;
    printf("Enter the student's ID: ");
    scanf("%d", &id);

    // Find the student by their ID
    Student *student = NULL;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            student = &students[i];
            break;
        }
    }

    // If the student was not found, print an error message
    if (student == NULL) {
        printf("Student not found.\n");
        return 1;
    }

    // Print the student's information
    printf("Student information:\n");
    printf("ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Score: %d\n", student->score);

    // Get the student's new score
    int new_score;
    printf("Enter the student's new score: ");
    scanf("%d", &new_score);

    // Update the student's score
    student->score = new_score;

    // Print the updated student information
    printf("Updated student information:\n");
    printf("ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Score: %d\n", student->score);

    return 0;
}