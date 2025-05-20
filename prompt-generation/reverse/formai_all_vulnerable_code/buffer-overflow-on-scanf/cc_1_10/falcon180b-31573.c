//Falcon-180B DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a student with name and grade
typedef struct {
    char name[50];
    float grade;
} Student;

// Function to compare two students by grade
int compareStudents(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;

    if (studentA->grade > studentB->grade) {
        return 1;
    } else if (studentA->grade < studentB->grade) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the sorted list of students
void printStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %.2f\n", students[i].name, students[i].grade);
    }
}

// Main function
int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for the array of students
    Student *students = malloc(numStudents * sizeof(Student));

    // Read in the names and grades of the students
    printf("Enter the names and grades of the students:\n");
    for (int i = 0; i < numStudents; i++) {
        scanf("%s %.2f", students[i].name, &students[i].grade);
    }

    // Sort the students by grade
    qsort(students, numStudents, sizeof(Student), compareStudents);

    // Print the sorted list of students
    printf("Sorted list of students:\n");
    printStudents(students, numStudents);

    // Free the memory allocated for the array of students
    free(students);

    return 0;
}