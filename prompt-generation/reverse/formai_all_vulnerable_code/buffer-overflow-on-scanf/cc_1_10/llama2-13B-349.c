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
    int grade[MAX_GRADES];
} student_t;

// Function to input student information
void input_student(student_t *s) {
    printf("Enter student name: ");
    fgets(s->name, MAX_NAME_LENGTH, stdin);
    s->name[strcspn(s->name, "\n")] = 0; // Trim newline character

    printf("Enter grade for subject 1: ");
    scanf("%d", &s->grade[0]);

    printf("Enter grade for subject 2: ");
    scanf("%d", &s->grade[1]);

    printf("Enter grade for subject 3: ");
    scanf("%d", &s->grade[2]);

    printf("Enter grade for subject 4: ");
    scanf("%d", &s->grade[3]);

    printf("Enter grade for subject 5: ");
    scanf("%d", &s->grade[4]);
}

// Function to display student information
void display_student(student_t s) {
    printf("Student: %s\n", s.name);
    printf("Grade for subject 1: %d\n", s.grade[0]);
    printf("Grade for subject 2: %d\n", s.grade[1]);
    printf("Grade for subject 3: %d\n", s.grade[2]);
    printf("Grade for subject 4: %d\n", s.grade[3]);
    printf("Grade for subject 5: %d\n", s.grade[4]);
}

int main() {
    student_t student;

    // Input student information
    input_student(&student);

    // Display student information
    display_student(student);

    return 0;
}