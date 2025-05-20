//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADES 10

// Structure to hold student data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char grade[MAX_GRADES];
} student_t;

// Function to print a banner with a retro vibe
void print_banner(void) {
    printf("--------------------------------------------------------------\n");
    printf("Welcome to the Retro C Programming Exercise!                   \n");
    printf("--------------------------------------------------------------\n");
    printf("Please choose a student to grade: ");
}

// Function to grade a student
void grade_student(student_t *student) {
    int i;
    printf("--------------------------------------------------------------\n");
    printf("Grade Report for %s (%d years old):\n", student->name, student->age);
    for (i = 0; i < MAX_GRADES; i++) {
        printf("  Grade %c: %d\n", 'A' + i, student->grade[i]);
    }
}

// Function to get student data
void get_student_data(student_t *student) {
    printf("Enter student name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    printf("Enter age: ");
    scanf("%d", &student->age);
    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Enter grade %c: ", 'A' + i);
        scanf("%d", &student->grade[i]);
    }
}

int main() {
    student_t student;
    char choice;

    // Print banner
    print_banner();

    // Get student data
    get_student_data(&student);

    // Grade student
    grade_student(&student);

    // Print choice to grade another student
    printf("Do you want to grade another student? (y/n): ");
    scanf(" %c", &choice);

    return 0;
}