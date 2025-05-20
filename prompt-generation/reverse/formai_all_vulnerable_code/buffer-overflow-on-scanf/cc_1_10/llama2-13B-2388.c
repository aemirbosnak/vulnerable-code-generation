//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADES 5

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
} student_t;

// Function to print a message to the screen
void print_message(const char* message) {
    printf("%s\n", message);
}

// Function to ask the user for their name
void get_name(student_t* student) {
    printf("What is your name? ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
}

// Function to ask the user for their age
void get_age(student_t* student) {
    printf("How old are you? ");
    scanf("%d", &student->age);
}

// Function to ask the user for their GPA
void get_gpa(student_t* student) {
    printf("What is your GPA? ");
    scanf("%lf", &student->gpa);
}

// Function to print the student's information
void print_student(student_t* student) {
    printf("Hello, %s! You are %d years old and have a GPA of %.2lf.\n", student->name, student->age, student->gpa);
}

int main() {
    student_t student;

    // Ask the user for their name
    get_name(&student);

    // Ask the user for their age
    get_age(&student);

    // Ask the user for their GPA
    get_gpa(&student);

    // Print the student's information
    print_student(&student);

    return 0;
}