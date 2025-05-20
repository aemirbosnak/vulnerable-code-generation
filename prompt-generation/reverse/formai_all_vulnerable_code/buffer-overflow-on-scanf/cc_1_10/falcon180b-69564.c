//Falcon-180B DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

// Define a structure to store information about each student
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// Function to compare two students based on their grades
int compare_students(const void *a, const void *b) {
    const Student *student_a = a;
    const Student *student_b = b;

    if (student_a->grade > student_b->grade) {
        return 1;
    } else if (student_a->grade < student_b->grade) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the details of a student
void print_student(const Student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grade: %.2f\n", student->grade);
    printf("\n");
}

// Function to read the details of a student from the user
void read_student(Student *student) {
    printf("Enter the name of the student: ");
    scanf("%s", student->name);

    printf("Enter the age of the student: ");
    scanf("%d", &student->age);

    printf("Enter the grade of the student: ");
    scanf("%f", &student->grade);
}

// Function to generate a random grade for a student
float generate_random_grade() {
    return (float)rand() / RAND_MAX;
}

// Function to generate a random age for a student
int generate_random_age() {
    return rand() % 100;
}

// Function to generate a random name for a student
void generate_random_name(char *name) {
    const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    for (i = 0; i < 50; i++) {
        name[i] = letters[rand() % 26];
    }

    name[i] = '\0';
}

int main() {
    srand(time(NULL));

    // Initialize an array of students
    Student students[10];

    // Read the details of each student from the user
    int i;
    for (i = 0; i < 10; i++) {
        read_student(&students[i]);
    }

    // Sort the array of students based on their grades
    qsort(students, 10, sizeof(Student), compare_students);

    // Print the details of each student
    for (i = 0; i < 10; i++) {
        print_student(&students[i]);
    }

    return 0;
}