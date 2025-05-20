//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 20

// Structure to represent a student
typedef struct {
    int roll_number;
    char name[MAX_NAME_LENGTH];
    float marks;
} Student;

// Function to swap two students
void swap_students(Student *s1, Student *s2) {
    Student temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

// Function to sort an array of students based on marks
void sort_students(Student students[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                swap_students(&students[j], &students[j + 1]);
            }
        }
    }
}

// Function to read students data from a file
void read_students_from_file(Student students[], int *size) {
    FILE *file;
    char filename[MAX_NAME_LENGTH];
    int i = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(file)) {
        fscanf(file, "%d %s %f", &students[i].roll_number, students[i].name, &students[i].marks);
        i++;
        *size = i;
    }

    fclose(file);
}

// Function to display students data
void display_students(Student students[], int size) {
    int i;

    printf("\nStudents Data:\n");
    printf("%-10s %-20s %-10s\n", "Roll Number", "Name", "Marks");

    for (i = 0; i < size; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].roll_number, students[i].name, students[i].marks);
    }
}

// Main function
int main() {
    Student students[MAX_SIZE];
    int size = 0;

    printf("Reading students data from file...\n");
    read_students_from_file(students, &size);

    printf("Sorting students based on marks...\n");
    sort_students(students, size);

    printf("Students data after sorting:\n");
    display_students(students, size);

    return 0;
}