//GEMINI-pro DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a student's data
typedef struct student {
    char name[50];
    int age;
    float marks;
} student;

// Function to read student data from a file
void readStudentData(FILE *fp, student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        fscanf(fp, "%s %d %f", students[i].name, &students[i].age, &students[i].marks);
    }
}

// Function to write student data to a file
void writeStudentData(FILE *fp, student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].marks);
    }
}

// Function to sort students by name
void sortStudentsByName(student *students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    // Open the input file
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the number of students from the file
    int numStudents;
    fscanf(fp, "%d", &numStudents);

    // Allocate memory for the students
    student *students = malloc(sizeof(student) * numStudents);
    if (students == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the student data from the file
    readStudentData(fp, students, numStudents);

    // Close the input file
    fclose(fp);

    // Sort the students by name
    sortStudentsByName(students, numStudents);

    // Open the output file
    fp = fopen("sorted_students.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        free(students);
        return EXIT_FAILURE;
    }

    // Write the sorted student data to the file
    fprintf(fp, "%d\n", numStudents);
    writeStudentData(fp, students, numStudents);

    // Close the output file
    fclose(fp);

    // Free the memory allocated for the students
    free(students);

    return EXIT_SUCCESS;
}