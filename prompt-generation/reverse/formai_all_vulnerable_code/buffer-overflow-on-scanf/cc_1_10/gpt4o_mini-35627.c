//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

void inputGrades(float grades[MAX_STUDENTS][MAX_SUBJECTS], int students, int subjects);
void displayGrades(float grades[MAX_STUDENTS][MAX_SUBJECTS], int students, int subjects);
void calculateAverages(float grades[MAX_STUDENTS][MAX_SUBJECTS], float averages[MAX_STUDENTS], int students, int subjects);
void transposeGrades(float grades[MAX_STUDENTS][MAX_SUBJECTS], float transposed[MAX_SUBJECTS][MAX_STUDENTS], int students, int subjects);

int main() {
    int students, subjects;
    float grades[MAX_STUDENTS][MAX_SUBJECTS];
    float averages[MAX_STUDENTS];
    float transposed[MAX_SUBJECTS][MAX_STUDENTS];

    printf("Welcome to the Student Grades Management System!\n");
    printf("Enter the number of students: ");
    scanf("%d", &students);
    printf("Enter the number of subjects: ");
    scanf("%d", &subjects);

    // Input student grades
    inputGrades(grades, students, subjects);
    
    // Display the grades
    printf("\nGrades entered:\n");
    displayGrades(grades, students, subjects);
    
    // Calculate and display averages
    calculateAverages(grades, averages, students, subjects);
    printf("\nAverage grades for each student:\n");
    for (int i = 0; i < students; i++) {
        printf("Student %d: %.2f\n", i + 1, averages[i]);
    }

    // Transpose and display the grade matrix
    transposeGrades(grades, transposed, students, subjects);
    printf("\nTransposed Grades Matrix:\n");
    displayGrades(transposed, subjects, students);

    return 0;
}

void inputGrades(float grades[MAX_STUDENTS][MAX_SUBJECTS], int students, int subjects) {
    for (int i = 0; i < students; i++) {
        printf("Enter grades for student %d:\n", i + 1);
        for (int j = 0; j < subjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &grades[i][j]);
        }
    }
}

void displayGrades(float grades[MAX_STUDENTS][MAX_SUBJECTS], int students, int subjects) {
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            printf("%.2f\t", grades[i][j]);
        }
        printf("\n");
    }
}

void calculateAverages(float grades[MAX_STUDENTS][MAX_SUBJECTS], float averages[MAX_STUDENTS], int students, int subjects) {
    for (int i = 0; i < students; i++) {
        float total = 0.0;
        for (int j = 0; j < subjects; j++) {
            total += grades[i][j];
        }
        averages[i] = total / subjects;
    }
}

void transposeGrades(float grades[MAX_STUDENTS][MAX_SUBJECTS], float transposed[MAX_SUBJECTS][MAX_STUDENTS], int students, int subjects) {
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            transposed[j][i] = grades[i][j];
        }
    }
}