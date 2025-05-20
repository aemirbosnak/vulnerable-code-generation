//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Define the structure for a student
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// Function to swap two students
void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two students by age
int compare_age(const void* a, const void* b) {
    const Student* student_a = (const Student*)a;
    const Student* student_b = (const Student*)b;
    return (student_a->age - student_b->age);
}

// Function to compare two students by grade
int compare_grade(const void* a, const void* b) {
    const Student* student_a = (const Student*)a;
    const Student* student_b = (const Student*)b;
    return (student_b->grade - student_a->grade);
}

// Function to sort an array of students by age
void sort_by_age(Student arr[], int n) {
    qsort(arr, n, sizeof(Student), compare_age);
}

// Function to sort an array of students by grade
void sort_by_grade(Student arr[], int n) {
    qsort(arr, n, sizeof(Student), compare_grade);
}

// Function to generate random students
void generate_students(Student arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i].age = rand() % 100;
        arr[i].grade = (float)rand() / RAND_MAX;
        sprintf(arr[i].name, "Student %d", i+1);
    }
}

// Function to print an array of students
void print_students(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s (%d years old) has a grade of %.2f\n", arr[i].name, arr[i].age, arr[i].grade);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];
    generate_students(students, n);

    printf("Unsorted students:\n");
    print_students(students, n);

    sort_by_age(students, n);
    printf("\nSorted by age:\n");
    print_students(students, n);

    sort_by_grade(students, n);
    printf("\nSorted by grade:\n");
    print_students(students, n);

    return 0;
}