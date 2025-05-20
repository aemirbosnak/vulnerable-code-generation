//FormAI DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    FILE *fptr;
    Student s;

    // Dynamically allocate memory for an array of students
    int num_students = 3;
    Student *students = (Student*) malloc(num_students * sizeof(Student));

    // Prompt user to enter details for each student and store in array
    for (int i = 0; i < num_students; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // Write array of students to file
    fptr = fopen("students.dat", "wb");
    if (fptr == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    fwrite(students, sizeof(Student), num_students, fptr);
    fclose(fptr);

    // Read from file and output student details
    printf("\nStudent details:\n");
    fptr = fopen("students.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    fread(students, sizeof(Student), num_students, fptr);
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d\nName: %s\nGPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
    fclose(fptr);

    // Deallocate the memory used for the array
    free(students);

    return 0;
}