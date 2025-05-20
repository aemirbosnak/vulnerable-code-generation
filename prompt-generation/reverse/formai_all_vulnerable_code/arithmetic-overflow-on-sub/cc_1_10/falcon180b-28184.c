//Falcon-180B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>

// Define a structure for a student
struct student {
    char name[50];
    int age;
    float gpa;
};

// Define a function to read a student's information from the user
void read_student(struct student *s) {
    printf("Enter student name: ");
    scanf("%s", s->name);

    printf("Enter student age: ");
    scanf("%d", &s->age);

    printf("Enter student GPA: ");
    scanf("%f", &s->gpa);
}

// Define a function to print a student's information
void print_student(struct student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("GPA: %.2f\n", s.gpa);
}

// Define a function to sort an array of students by GPA
void sort_students(struct student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[j].gpa > students[i].gpa) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Define a function to calculate the average GPA of an array of students
float calculate_average_gpa(struct student students[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += students[i].gpa;
    }
    return sum / n;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student students[n];

    // Read each student's information from the user
    for (int i = 0; i < n; i++) {
        read_student(&students[i]);
    }

    // Sort the students by GPA
    sort_students(students, n);

    // Print the sorted list of students
    printf("Sorted list of students by GPA:\n");
    for (int i = 0; i < n; i++) {
        print_student(students[i]);
    }

    // Calculate and print the average GPA of the students
    float avg_gpa = calculate_average_gpa(students, n);
    printf("\nAverage GPA: %.2f\n", avg_gpa);

    return 0;
}