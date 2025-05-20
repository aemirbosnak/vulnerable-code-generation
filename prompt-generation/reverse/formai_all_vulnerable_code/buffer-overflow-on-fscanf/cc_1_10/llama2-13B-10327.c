//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STUDENTS 100
#define MAX_GPA 4.0

struct student {
    char name[50];
    int age;
    double gpa;
};

int main() {
    struct student students[MAX_STUDENTS];
    int i, j;
    double avg_gpa, max_gpa, min_gpa;

    // Load student data from file
    FILE *file = fopen("students.dat", "r");
    if (file == NULL) {
        printf("Error: unable to open file\n");
        return 1;
    }

    // Read student data from file
    for (i = 0; i < MAX_STUDENTS; i++) {
        fscanf(file, "%s %d %lf", students[i].name, &students[i].age, &students[i].gpa);
    }

    // Calculate average GPA
    avg_gpa = 0;
    for (i = 0; i < MAX_STUDENTS; i++) {
        avg_gpa += students[i].gpa;
    }
    avg_gpa /= MAX_STUDENTS;

    // Print average GPA
    printf("Average GPA: %lf\n", avg_gpa);

    // Calculate maximum GPA
    max_gpa = -1;
    for (i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].gpa > max_gpa) {
            max_gpa = students[i].gpa;
        }
    }

    // Print maximum GPA
    printf("Maximum GPA: %lf\n", max_gpa);

    // Calculate minimum GPA
    min_gpa = 100;
    for (i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].gpa < min_gpa) {
            min_gpa = students[i].gpa;
        }
    }

    // Print minimum GPA
    printf("Minimum GPA: %lf\n", min_gpa);

    // Print student names and GPA ranges
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("%s (%lf - %lf)\n", students[i].name, min_gpa, max_gpa);
    }

    // Close file
    fclose(file);

    return 0;
}