//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure for storing data
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function to compare two students based on their grades
int compareStudents(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return (studentA->grade > studentB->grade) - (studentA->grade < studentB->grade);
}

// Function to print the sorted list of students
void printStudents(Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("%d %s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

// Main function
int main() {
    int numStudents;
    scanf("%d", &numStudents);

    // Allocate memory for the students
    Student *students = malloc(numStudents * sizeof(Student));

    // Read in the student data
    for (int i = 0; i < numStudents; i++) {
        scanf("%d %s %.2f", &students[i].id, students[i].name, &students[i].grade);
    }

    // Sort the students by grade
    qsort(students, numStudents, sizeof(Student), compareStudents);

    // Print the sorted list of students
    printf("Sorted by grade:\n");
    printStudents(students, numStudents);

    // Free the memory
    free(students);
    return 0;
}