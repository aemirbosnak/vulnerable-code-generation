//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the structure of a student
typedef struct {
    char name[50];
    int age;
    int grade;
} student_t;

// Define the comparison function for sorting students by name
int compare_students_by_name(const void *a, const void *b) {
    const student_t *student_a = (const student_t *)a;
    const student_t *student_b = (const student_t *)b;

    return strcmp(student_a->name, student_b->name);
}

// Define the comparison function for sorting students by age
int compare_students_by_age(const void *a, const void *b) {
    const student_t *student_a = (const student_t *)a;
    const student_t *student_b = (const student_t *)b;

    return student_a->age - student_b->age;
}

// Define the comparison function for sorting students by grade
int compare_students_by_grade(const void *a, const void *b) {
    const student_t *student_a = (const student_t *)a;
    const student_t *student_b = (const student_t *)b;

    return student_a->grade - student_b->grade;
}

// Get the students from the user
void get_students(student_t students[], int *num_students) {
    printf("Enter the number of students: ");
    scanf("%d", num_students);

    for (int i = 0; i < *num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter the grade of student %d: ", i + 1);
        scanf("%d", &students[i].grade);
    }
}

// Print the students
void print_students(student_t students[], int num_students) {
    printf("\nStudents:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s %d %d\n", students[i].name, students[i].age, students[i].grade);
    }
}

// Sort the students by name
void sort_students_by_name(student_t students[], int num_students) {
    qsort(students, num_students, sizeof(student_t), compare_students_by_name);
}

// Sort the students by age
void sort_students_by_age(student_t students[], int num_students) {
    qsort(students, num_students, sizeof(student_t), compare_students_by_age);
}

// Sort the students by grade
void sort_students_by_grade(student_t students[], int num_students) {
    qsort(students, num_students, sizeof(student_t), compare_students_by_grade);
}

// Main function
int main() {
    // Declare the array of students
    student_t students[MAX_STUDENTS];

    // Get the number of students from the user
    int num_students;
    get_students(students, &num_students);

    // Print the original array of students
    printf("\nOriginal array of students:\n");
    print_students(students, num_students);

    // Sort the students by name
    sort_students_by_name(students, num_students);

    // Print the sorted array of students by name
    printf("\nSorted array of students by name:\n");
    print_students(students, num_students);

    // Sort the students by age
    sort_students_by_age(students, num_students);

    // Print the sorted array of students by age
    printf("\nSorted array of students by age:\n");
    print_students(students, num_students);

    // Sort the students by grade
    sort_students_by_grade(students, num_students);

    // Print the sorted array of students by grade
    printf("\nSorted array of students by grade:\n");
    print_students(students, num_students);

    return 0;
}