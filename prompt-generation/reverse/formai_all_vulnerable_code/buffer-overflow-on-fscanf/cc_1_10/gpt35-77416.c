//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* Define a struct for representing a student record */
typedef struct student {
    int id;
    char name[100];
    float gpa;
} Student;

/* Define a function to read student records from a file */
void readStudents(char* filename, Student students[], int n) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    /* Read in each student record */
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d,%[^,],%f\n", &students[i].id, students[i].name, &students[i].gpa);
    }

    fclose(fp);
}

/* Define a function to find the average GPA of the students */
float findAvgGPA(Student students[], int n) {
    float totalGPA = 0;
    for (int i = 0; i < n; i++) {
        totalGPA += students[i].gpa;
    }

    return totalGPA / n;
}

/* Define a function to find the student with the highest GPA */
Student findTopGPA(Student students[], int n) {
    Student topGPA;

    /* Assume the first student has the highest GPA */
    topGPA = students[0];

    for (int i = 1; i < n; i++) {
        if (students[i].gpa > topGPA.gpa) {
            topGPA = students[i];
        }
    }

    return topGPA;
}

int main() {
    int numStudents = 5;
    Student students[numStudents];

    /* Read in the student records from a file */
    readStudents("students.csv", students, numStudents);

    /* Find and print the average GPA */
    float avgGPA = findAvgGPA(students, numStudents);
    printf("The average GPA is %.2f\n", avgGPA);

    /* Find and print the student with the highest GPA */
    Student topGPA = findTopGPA(students, numStudents);
    printf("The student with the highest GPA is %s (ID: %d, GPA: %.2f)\n", topGPA.name, topGPA.id, topGPA.gpa);

    return 0;
}