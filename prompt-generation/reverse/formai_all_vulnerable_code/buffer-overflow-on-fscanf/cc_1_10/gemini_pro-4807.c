//GEMINI-pro DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a student
typedef struct {
    char name[50];
    int age;
    char gender;
    float gpa;
} student;

// Function to read students from a file
void read_students(char *filename, student **students, int *num_students) {
    FILE *fp;
    char line[100];

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the number of students
    fscanf(fp, "%d", num_students);

    // Allocate memory for the students
    *students = malloc(*num_students * sizeof(student));

    // Read the students from the file
    for (int i = 0; i < *num_students; i++) {
        fscanf(fp, "%s %d %c %f", (*students)[i].name, &(*students)[i].age, &(*students)[i].gender, &(*students)[i].gpa);
    }

    // Close the file
    fclose(fp);
}

// Function to write students to a file
void write_students(char *filename, student *students, int num_students) {
    FILE *fp;

    // Open the file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the number of students
    fprintf(fp, "%d\n", num_students);

    // Write the students to the file
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s %d %c %f\n", students[i].name, students[i].age, students[i].gender, students[i].gpa);
    }

    // Close the file
    fclose(fp);
}

// Function to print students
void print_students(student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s %d %c %f\n", students[i].name, students[i].age, students[i].gender, students[i].gpa);
    }
}

int main() {
    student *students;
    int num_students;

    // Read students from file
    read_students("students.txt", &students, &num_students);

    // Print students
    print_students(students, num_students);

    // Write students to file
    write_students("students2.txt", students, num_students);

    // Free memory
    free(students);

    return 0;
}