//Falcon-180B DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the structure for a student
typedef struct {
    char name[50];
    int age;
    float grade;
} student_t;

// Function to compare two students based on their grades
int compare_students(const void *a, const void *b) {
    const student_t *student_a = (const student_t *)a;
    const student_t *student_b = (const student_t *)b;

    if (student_a->grade > student_b->grade) {
        return 1;
    } else if (student_a->grade < student_b->grade) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the details of a student
void print_student(const student_t *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grade: %.2f\n\n", student->grade);
}

// Function to generate random students
void generate_students(student_t students[], int num_students) {
    srand(time(NULL));

    for (int i = 0; i < num_students; i++) {
        students[i].age = rand() % 101;
        students[i].grade = rand() % 101;

        sprintf(students[i].name, "Student %d", i + 1);
    }
}

// Function to sort the students based on their grades
void sort_students(student_t students[], int num_students) {
    qsort(students, num_students, sizeof(student_t), compare_students);
}

// Function to print the top n students
void print_top_students(const student_t students[], int num_students, int n) {
    printf("Top %d Students:\n", n);

    for (int i = 0; i < n && i < num_students; i++) {
        print_student(&students[i]);
    }
}

int main() {
    int num_students;

    printf("Enter the number of students (maximum %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);

    if (num_students <= 0 || num_students > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    student_t students[num_students];

    generate_students(students, num_students);
    sort_students(students, num_students);
    print_top_students(students, num_students, 10);

    return 0;
}