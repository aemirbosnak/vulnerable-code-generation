//Falcon-180B DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>

// Define a struct for a student
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// Function to read a student from standard input
void read_student(Student *s) {
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter student age: ");
    scanf("%d", &s->age);
    printf("Enter student grade: ");
    scanf("%f", &s->grade);
}

// Function to print a student
void print_student(Student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);
}

// Function to sort an array of students by age
void sort_students(Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].age > students[j].age) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to calculate the average grade of an array of students
float avg_grade(Student *students, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += students[i].grade;
    }
    return sum / n;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student *students = malloc(n * sizeof(Student));
    for (int i = 0; i < n; i++) {
        read_student(&students[i]);
    }

    sort_students(students, n);

    printf("Sorted students by age:\n");
    for (int i = 0; i < n; i++) {
        print_student(students[i]);
    }

    float avg_grade_value = avg_grade(students, n);
    printf("\nAverage grade: %.2f\n", avg_grade_value);

    free(students);
    return 0;
}