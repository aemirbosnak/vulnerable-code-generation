//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to hold student data
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function to compare two students based on their grades (for sorting)
int compareStudents(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    if (studentA->grade < studentB->grade) return -1;  // studentA has a lower grade
    if (studentA->grade > studentB->grade) return 1;   // studentA has a higher grade
    return 0;                                           // grades are equal
}

// Function to print the list of students
void printStudents(Student *students, int size) {
    printf("ID\tName\t\tGrade\n");
    printf("------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

// Function to generate random student data for testing purposes
void generateRandomStudents(Student *students, int size) {
    const char *names[] = {"Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hannah", "Isaac", "Jack", "Kelly", "Leo"};
    srand(time(0));  // Seed for random number generator

    for (int i = 0; i < size; i++) {
        students[i].id = i + 1;  // Unique ID
        strcpy(students[i].name, names[rand() % 12]);  // Random name from the list
        students[i].grade = (float)(rand() % 100 + 1) / 100 * 10;  // Random grade between 0.0 and 10.0
    }
}

int main() {
    int numStudents;
    
    // Prompt user for the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for student data
    Student *students = (Student *)malloc(numStudents * sizeof(Student));
    
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }

    // Generate and display random student data
    generateRandomStudents(students, numStudents);
    printf("\nGenerated Students:\n");
    printStudents(students, numStudents);

    // Sort students based on their grades
    qsort(students, numStudents, sizeof(Student), compareStudents);

    // Display sorted students
    printf("\nSorted Students by Grades:\n");
    printStudents(students, numStudents);

    // Release allocated memory
    free(students);
    
    return 0;  // Exit the program
}