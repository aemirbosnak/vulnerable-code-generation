//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
/*
 * A unique C data mining example program in the style of Linus Torvalds
 *
 * This program demonstrates how to perform data mining using a simple
 * dataset of student grades and their corresponding course names.
 *
 * The program takes in a text file containing the student grades and
 * course names, and then performs data mining operations on the data
 * to generate a set of insights.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_STUDENTS 100
#define MAX_COURSES 10

// Structure to store student information
typedef struct {
    char name[MAX_LINE_LENGTH];
    char course[MAX_LINE_LENGTH];
    int grade;
} student_t;

// Function to read in the data from the text file
int read_data(student_t students[], int *num_students) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    int i = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        sscanf(line, "%s %s %d", students[i].name, students[i].course, &students[i].grade);
        i++;
    }

    *num_students = i;

    fclose(fp);
    return 0;
}

// Function to calculate the mean grade for a given course
double calculate_mean_grade(student_t students[], int num_students, char course[]) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].course, course) == 0) {
            sum += students[i].grade;
            count++;
        }
    }
    return sum / count;
}

// Function to calculate the standard deviation for a given course
double calculate_std_dev(student_t students[], int num_students, char course[]) {
    double mean = calculate_mean_grade(students, num_students, course);
    double sum_squared_diff = 0.0;
    int count = 0;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].course, course) == 0) {
            double diff = students[i].grade - mean;
            sum_squared_diff += diff * diff;
            count++;
        }
    }
    return sqrt(sum_squared_diff / count);
}

// Function to find the most common grade for a given course
int find_most_common_grade(student_t students[], int num_students, char course[]) {
    int grades[10] = {0};
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].course, course) == 0) {
            grades[students[i].grade]++;
        }
    }

    int most_common = 0;
    for (int i = 0; i < 10; i++) {
        if (grades[i] > grades[most_common]) {
            most_common = i;
        }
    }

    return most_common;
}

// Main function
int main(int argc, char **argv) {
    student_t students[MAX_STUDENTS];
    int num_students;

    // Read in the data from the text file
    if (read_data(students, &num_students) != 0) {
        return 1;
    }

    // Calculate the mean grade for each course
    for (int i = 0; i < num_students; i++) {
        double mean = calculate_mean_grade(students, num_students, students[i].course);
        printf("Mean grade for course %s: %.2f\n", students[i].course, mean);
    }

    // Calculate the standard deviation for each course
    for (int i = 0; i < num_students; i++) {
        double std_dev = calculate_std_dev(students, num_students, students[i].course);
        printf("Standard deviation for course %s: %.2f\n", students[i].course, std_dev);
    }

    // Find the most common grade for each course
    for (int i = 0; i < num_students; i++) {
        int most_common = find_most_common_grade(students, num_students, students[i].course);
        printf("Most common grade for course %s: %d\n", students[i].course, most_common);
    }

    return 0;
}