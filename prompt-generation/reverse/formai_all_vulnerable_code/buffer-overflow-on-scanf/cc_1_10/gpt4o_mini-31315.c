//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float grade;
} Student;

// Function to compare two students for sorting
int compare_students(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    // First, compare by name
    int nameComparison = strcmp(studentA->name, studentB->name);
    if (nameComparison != 0) {
        return nameComparison;
    }

    // If names are the same, compare by grade (descending)
    if (studentA->grade < studentB->grade) {
        return 1; // So that higher grades come first
    } else if (studentA->grade > studentB->grade) {
        return -1;
    }

    // If grades are also the same, compare by age (ascending)
    return studentA->age - studentB->age;
}

void display_students(Student students[], int count) {
    printf("\nSorted Students List:\n");
    printf("------------------------------------------------------\n");
    printf("%-20s %-5s %-6s\n", "Name", "Age", "Grade");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-6.2f\n", students[i].name, students[i].age, students[i].grade);
    }
    printf("------------------------------------------------------\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students;

    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);
    
    // Input validation
    if (num_students < 1 || num_students > MAX_STUDENTS) {
        printf("Invalid number of students. Please enter a number between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }

    // Input student data
    for (int i = 0; i < num_students; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %49[^\n]", students[i].name); // Read string with spaces
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    // Sort the students
    qsort(students, num_students, sizeof(Student), compare_students);
    
    // Display sorted students
    display_students(students, num_students);

    return 0;
}