//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADES 5

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int ages[MAX_GRADES];
} student_t;

// Function to input student information
void input_student(student_t *s) {
    printf("Enter student's name: ");
    fgets(s->name, MAX_NAME_LENGTH, stdin);
    printf("Enter student's age: ");
    scanf("%d", &s->ages[0]);
    for (int i = 1; i < MAX_GRADES; i++) {
        printf("Enter student's grade %d: ", i);
        scanf("%d", &s->ages[i]);
    }
}

// Function to output student information
void output_student(const student_t *s) {
    printf("Student: %s\n", s->name);
    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Grade %d: %d\n", i + 1, s->ages[i]);
    }
}

// Function to calculate and print the average grade
void print_average(const student_t *s) {
    int total = 0;
    for (int i = 0; i < MAX_GRADES; i++) {
        total += s->ages[i];
    }
    double average = (double)total / MAX_GRADES;
    printf("Average grade: %.2f\n", average);
}

int main() {
    student_t student;
    input_student(&student);
    print_average(&student);
    output_student(&student);
    return 0;
}