//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_GRADES 5

typedef struct {
    char name[MAX_NAME_LEN];
    int grade[MAX_GRADES];
} student_t;

void grade_entry(student_t *student, int grade);
void print_grades(student_t *student);

int main() {
    int i, j;
    student_t students[5];

    // Initialize students
    for (i = 0; i < 5; i++) {
        printf("Enter name: ");
        fgets(students[i].name, MAX_NAME_LEN, stdin);
        printf("Enter grade 1: ");
        scanf("%d", &students[i].grade[0]);
        printf("Enter grade 2: ");
        scanf("%d", &students[i].grade[1]);
        printf("Enter grade 3: ");
        scanf("%d", &students[i].grade[2]);
        printf("Enter grade 4: ");
        scanf("%d", &students[i].grade[3]);
        printf("Enter grade 5: ");
        scanf("%d", &students[i].grade[4]);
    }

    // Grade entry loop
    for (i = 0; i < 5; i++) {
        for (j = 0; j < MAX_GRADES; j++) {
            grade_entry(&students[i], j);
        }
    }

    // Print grades
    for (i = 0; i < 5; i++) {
        print_grades(&students[i]);
    }

    return 0;
}

void grade_entry(student_t *student, int grade) {
    // Check if grade is valid
    if (grade < 0 || grade > 100) {
        printf("Invalid grade! Please enter a valid grade between 0 and 100.\n");
        return;
    }

    // Add grade to student's grade array
    student->grade[grade - 1]++;

    // Check if student has already reached the maximum grade
    if (student->grade[grade - 1] > 100) {
        student->grade[grade - 1] = 100;
    }
}

void print_grades(student_t *student) {
    int i, j;

    // Print student name and grades
    for (i = 0; i < 5; i++) {
        printf("%s's grades: ", student[i].name);
        for (j = 0; j < MAX_GRADES; j++) {
            printf("%d ", student[i].grade[j]);
        }
        printf("\n");
    }
}