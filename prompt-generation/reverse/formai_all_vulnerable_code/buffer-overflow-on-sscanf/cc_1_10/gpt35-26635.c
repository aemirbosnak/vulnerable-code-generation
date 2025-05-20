//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum line length
#define MAX_LINE_LENGTH 1024

// Define struct for holding student data
typedef struct {
    char name[50];
    double gpa;
    int grades[5];
} Student;

// Define function for reading in student data from text file
int readStudentData(FILE* fp, Student* students, int max_students) {
    char line[MAX_LINE_LENGTH];
    int num_students = 0;

    // Loop through lines in text file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Parse line and assign values to student struct
        sscanf(line, "%s %lf %d %d %d %d %d", students[num_students].name, &students[num_students].gpa,
              &students[num_students].grades[0], &students[num_students].grades[1], 
              &students[num_students].grades[2], &students[num_students].grades[3], 
              &students[num_students].grades[4]);
        num_students++;

        // Check if maximum number of students has been reached
        if (num_students == max_students) {
            break;
        }
    }

    return num_students;
}

// Define function for calculating average of an array of integers
double getArrayAverage(int* array, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return (double) sum / size;
}

// Define function for performing data mining analysis on student data
void dataMiningAnalysis(Student* students, int num_students) {
    printf("Total number of students: %d\n", num_students);

    // Calculate average GPA and print
    double gpa_sum = 0.0;
    for (int i = 0; i < num_students; i++) {
        gpa_sum += students[i].gpa;
    }
    double gpa_avg = gpa_sum / num_students;
    printf("Average GPA: %f\n", gpa_avg);

    // Calculate average grade for each course and print
    for (int i = 0; i < 5; i++) {
        int grades_sum = 0;
        for (int j = 0; j < num_students; j++) {
            grades_sum += students[j].grades[i];
        }
        double grades_avg = (double) grades_sum / num_students;
        printf("Average grade for course %d: %f\n", i+1, grades_avg);
    }

    // Calculate correlation between study time and grades for each course and print
    for (int i = 0; i < 5; i++) {
        int grades_sum = 0;
        int study_time_sum = 0;
        int study_time_squared_sum = 0;
        for (int j = 0; j < num_students; j++) {
            grades_sum += students[j].grades[i];
            study_time_sum += students[j].grades[i] * 2;
            study_time_squared_sum += students[j].grades[i] * students[j].grades[i];
        }
        double grades_avg = (double) grades_sum / num_students;
        double study_time_avg = (double) study_time_sum / num_students;
        double study_time_squared_avg = (double) study_time_squared_sum / num_students;
        double covariance = study_time_avg * grades_avg - (2 * study_time_squared_avg);
        double var_study = study_time_squared_avg - (study_time_avg * study_time_avg);
        printf("Correlation between study time and grades for course %d: %f\n", i+1, covariance / var_study);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <student_data.txt>\n", argv[0]);
        return 1;
    }

    // Open file and exit if error
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", argv[1]);
        return 1;
    }

    // Allocate memory for student data and read in data from file
    Student* students = malloc(sizeof(Student) * 100);
    int num_students = readStudentData(fp, students, 100);

    // Perform data mining analysis on student data
    dataMiningAnalysis(students, num_students);

    // Free memory and close file
    free(students);
    fclose(fp);

    return 0;
}