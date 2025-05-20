//GEMINI-pro DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple student record
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to read students from a file
int readStudents(FILE *fp, Student *students, int maxStudents) {
    int numStudents = 0;

    // Read the first student record
    if (fscanf(fp, "%s %d %f", students[numStudents].name, &students[numStudents].age, &students[numStudents].gpa) != 3) {
        return numStudents;
    }

    // Read the remaining student records
    while (fscanf(fp, "%s %d %f", students[numStudents].name, &students[numStudents].age, &students[numStudents].gpa) == 3) {
        numStudents++;

        // Check if we have reached the maximum number of students
        if (numStudents == maxStudents) {
            break;
        }
    }

    return numStudents;
}

// Function to write students to a file
void writeStudents(FILE *fp, Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

// Main function
int main() {
    // Open the input file
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Read the students from the file
    Student students[100];
    int numStudents = readStudents(fp, students, 100);

    // Close the input file
    fclose(fp);

    // Print the students
    for (int i = 0; i < numStudents; i++) {
        printf("%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
    }

    // Open the output file
    fp = fopen("students_out.txt", "w");
    if (fp == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Write the students to the file
    writeStudents(fp, students, numStudents);

    // Close the output file
    fclose(fp);

    return EXIT_SUCCESS;
}