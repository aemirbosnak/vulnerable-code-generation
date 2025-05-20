//GEMINI-pro DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a student
typedef struct student {
    char name[50];
    int age;
    float gpa;
} student;

// Create a function to read students from a file
int read_students(const char *filename, student **students) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Read the number of students
    int num_students;
    fscanf(fp, "%d", &num_students);

    // Allocate memory for the students
    *students = malloc(num_students * sizeof(student));
    if (*students == NULL) {
        return -1;
    }

    // Read the students from the file
    for (int i = 0; i < num_students; i++) {
        fscanf(fp, "%s %d %f", (*students)[i].name, &(*students)[i].age, &(*students)[i].gpa);
    }

    // Close the file
    fclose(fp);

    return num_students;
}

// Create a function to write students to a file
int write_students(const char *filename, student *students, int num_students) {
    // Open the file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    // Write the number of students
    fprintf(fp, "%d\n", num_students);

    // Write the students to the file
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Create a function to print students
void print_students(student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

// Create a function to compare students by GPA
int compare_students_by_gpa(const void *a, const void *b) {
    const student *student1 = (const student *)a;
    const student *student2 = (const student *)b;

    if (student1->gpa < student2->gpa) {
        return -1;
    } else if (student1->gpa > student2->gpa) {
        return 1;
    } else {
        return 0;
    }
}

// Create a function to find the student with the highest GPA
student *find_student_with_highest_gpa(student *students, int num_students) {
    // Sort the students by GPA
    qsort(students, num_students, sizeof(student), compare_students_by_gpa);

    // Return the student with the highest GPA
    return &students[num_students - 1];
}

// Create a function to find the average GPA of the students
float find_average_gpa(student *students, int num_students) {
    float total_gpa = 0;
    for (int i = 0; i < num_students; i++) {
        total_gpa += students[i].gpa;
    }
    return total_gpa / num_students;
}

// Create a function to main
int main() {
    // Declare variables
    student *students;
    int num_students;
    char filename[] = "students.txt";

    // Read students from the file
    num_students = read_students(filename, &students);
    if (num_students == -1) {
        printf("Error reading students from the file.\n");
        return 1;
    }

    // Print the students
    printf("Students:\n");
    print_students(students, num_students);

    // Find the student with the highest GPA
    student *student_with_highest_gpa = find_student_with_highest_gpa(students, num_students);
    printf("Student with the highest GPA:\n");
    print_students(student_with_highest_gpa, 1);

    // Find the average GPA of the students
    float average_gpa = find_average_gpa(students, num_students);
    printf("Average GPA: %.2f\n", average_gpa);

    // Write the students to the file
    if (write_students(filename, students, num_students) == -1) {
        printf("Error writing students to the file.\n");
        return 1;
    }

    // Free the memory allocated for the students
    free(students);

    return 0;
}