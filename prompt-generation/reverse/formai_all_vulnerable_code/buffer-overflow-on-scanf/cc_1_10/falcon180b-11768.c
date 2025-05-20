//Falcon-180B DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_STUDENTS 100

// Struct to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float GPA;
} Student;

// Function to compare two students by GPA (for sorting)
int compare_students(const void *a, const void *b) {
    const Student *student_a = (const Student *)a;
    const Student *student_b = (const Student *)b;

    if (student_a->GPA > student_b->GPA) {
        return 1;
    } else if (student_a->GPA < student_b->GPA) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the list of students
void print_students(Student students[], int num_students) {
    printf("Name\tAge\tGPA\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].age, students[i].GPA);
    }
}

int main() {
    int num_students;
    printf("Enter the number of students (max %d): ", MAX_NUM_STUDENTS);
    scanf("%d", &num_students);

    if (num_students > MAX_NUM_STUDENTS) {
        printf("Error: number of students exceeds maximum limit.\n");
        return 1;
    }

    Student students[num_students];

    // Get student information from user
    for (int i = 0; i < num_students; i++) {
        printf("Enter student %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("GPA: ");
        scanf("%f", &students[i].GPA);
    }

    // Sort students by GPA
    qsort(students, num_students, sizeof(Student), compare_students);

    // Print list of students
    printf("\nList of students (sorted by GPA):\n");
    print_students(students, num_students);

    return 0;
}