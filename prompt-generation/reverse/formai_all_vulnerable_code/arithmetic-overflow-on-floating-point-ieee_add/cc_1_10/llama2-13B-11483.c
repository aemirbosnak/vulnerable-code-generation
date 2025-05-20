//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_LENGTH 10

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char grade[MAX_GRADE_LENGTH];
} Student;

// Function to calculate the average grade
double calculate_average(Student *students, int num_students) {
    int i;
    double sum = 0;
    for (i = 0; i < num_students; i++) {
        sum += atof(students[i].grade);
    }
    return sum / num_students;
}

// Function to print the student information
void print_students(Student *students, int num_students) {
    int i;
    for (i = 0; i < num_students; i++) {
        printf("%s is %d years old and is in grade %s\n", students[i].name, students[i].age, students[i].grade);
    }
}

int main() {
    // Create an array of Student structures
    Student students[5] = {
        {"Alice", 10, "1st grade"},
        {"Bob", 12, "3rd grade"},
        {"Charlie", 15, "9th grade"},
        {"David", 18, "12th grade"},
        {"Eve", 14, "8th grade"}
    };

    // Calculate the average grade
    double average = calculate_average(students, 5);
    printf("The average grade is: %f\n", average);

    // Print the student information
    print_students(students, 5);

    return 0;
}