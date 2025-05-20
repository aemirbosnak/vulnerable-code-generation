//Falcon-180B DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a student
typedef struct {
    char name[50];
    int age;
    float grade;
} student_t;

// Function to compare two students based on their grades
int compare_students(const void* a, const void* b) {
    const student_t* student1 = (const student_t*)a;
    const student_t* student2 = (const student_t*)b;

    if (student1->grade > student2->grade) {
        return 1;
    } else if (student1->grade < student2->grade) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the details of a student
void print_student(const student_t* student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grade: %.2f\n\n", student->grade);
}

// Function to read the details of a student from the user
void read_student(student_t* student) {
    printf("Enter the name of the student: ");
    scanf("%s", student->name);

    printf("Enter the age of the student: ");
    scanf("%d", &student->age);

    printf("Enter the grade of the student: ");
    scanf("%f", &student->grade);
}

// Function to sort an array of students using qsort
void sort_students(student_t students[], int count) {
    qsort(students, count, sizeof(student_t), compare_students);
}

int main() {
    int count;

    // Get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &count);

    // Dynamically allocate memory for the array of students
    student_t* students = (student_t*)malloc(count * sizeof(student_t));

    // Read the details of each student from the user
    for (int i = 0; i < count; i++) {
        read_student(&students[i]);
    }

    // Sort the array of students based on their grades
    sort_students(students, count);

    // Print the details of each student in the sorted array
    for (int i = 0; i < count; i++) {
        print_student(&students[i]);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}