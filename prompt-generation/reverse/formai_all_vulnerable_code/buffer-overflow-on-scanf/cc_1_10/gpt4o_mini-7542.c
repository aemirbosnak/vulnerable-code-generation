//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    float grade;
} Student;

// Function prototypes
void inputStudents(Student *students, int n);
void displayStudents(Student *students, int n);
void sortStudents(Student *students, int n);
int compare(const void *a, const void *b);


int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for students
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Input student details
    inputStudents(students, n);

    // Display students before sorting
    printf("\nStudents before sorting:\n");
    displayStudents(students, n);

    // Sort students
    sortStudents(students, n);

    // Display students after sorting
    printf("\nStudents after sorting:\n");
    displayStudents(students, n);

    // Free allocated memory
    free(students);
    return 0;
}

void inputStudents(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name for student %d: ", i + 1);
        getchar(); // Clear newline character
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline

        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter grade for student %d: ", i + 1);
        scanf("%f", &students[i].grade);
    }
}

void displayStudents(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d, Grade: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

void sortStudents(Student *students, int n) {
    qsort(students, n, sizeof(Student), compare);
}

int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    if (studentA->grade != studentB->grade) {
        if (studentA->grade < studentB->grade) return 1; // Sort descending by grade
        else return -1;
    } else {
        if (studentA->age != studentB->age) {
            return studentA->age - studentB->age; // Sort ascending by age
        } else {
            return strcmp(studentA->name, studentB->name); // Sort alphabetically by name
        }
    }
}