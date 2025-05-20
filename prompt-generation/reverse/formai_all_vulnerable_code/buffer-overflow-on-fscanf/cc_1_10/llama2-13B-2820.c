//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a student
typedef struct {
    int age;
    double gpa;
    char gender[5];
} student_t;

// Define an array to store the students
student_t students[10];

// Define a function to read in the student data
void read_students(void) {
    int i, j;
    char line[100];
    double gpa;

    // Read in the students from a file
    for (i = 0; i < 10; i++) {
        // Read in the age and gender
        fscanf(stdin, "%d %s", &students[i].age, students[i].gender);

        // Read in the GPA
        fscanf(stdin, "%lf", &gpa);
        students[i].gpa = gpa;
    }
}

// Define a function to calculate the average GPA
double calculate_average_gpa(void) {
    int i;
    double sum = 0;

    // Calculate the sum of the GPAs
    for (i = 0; i < 10; i++) {
        sum += students[i].gpa;
    }

    // Calculate the average GPA
    return sum / 10;
}

// Define a function to print out the students
void print_students(void) {
    int i;

    // Print out the students' ages and GPAs
    for (i = 0; i < 10; i++) {
        printf("%d %lf\n", students[i].age, students[i].gpa);
    }
}

int main(void) {
    // Read in the students
    read_students();

    // Calculate the average GPA
    double avg_gpa = calculate_average_gpa();

    // Print out the average GPA
    printf("Average GPA: %lf\n", avg_gpa);

    // Print out the students
    print_students();

    return 0;
}