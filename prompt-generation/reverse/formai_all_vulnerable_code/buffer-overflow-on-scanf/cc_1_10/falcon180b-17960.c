//Falcon-180B DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student
struct student {
    char name[50];
    int age;
    float grade;
};

// Function to compare two students based on their grades
int compare_grades(const void *a, const void *b) {
    struct student *student_a = (struct student *)a;
    struct student *student_b = (struct student *)b;

    if (student_a->grade > student_b->grade)
        return 1;
    else if (student_a->grade < student_b->grade)
        return -1;
    else
        return 0;
}

// Function to print the details of a student
void print_student(struct student student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Grade: %.2f\n\n", student.grade);
}

// Main function
int main() {
    int num_students;
    struct student students[100];

    // Get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Get the details of each student from the user
    for (int i = 0; i < num_students; i++) {
        printf("Enter the details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    // Sort the students based on their grades
    qsort(students, num_students, sizeof(struct student), compare_grades);

    // Print the sorted list of students
    printf("Sorted list of students based on their grades:\n");
    for (int i = 0; i < num_students; i++) {
        print_student(students[i]);
    }

    return 0;
}