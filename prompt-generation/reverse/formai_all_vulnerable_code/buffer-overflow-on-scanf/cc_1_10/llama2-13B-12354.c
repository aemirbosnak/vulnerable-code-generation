//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 25
#define MAX_GRADES 5

// Function to get the current date and time
void get_current_date_time(char *date_time) {
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", time_info);
}

// Function to calculate the average grade
float calculate_average_grade(float grades[]) {
    int i;
    float sum = 0;

    for (i = 0; i < MAX_GRADES; i++) {
        sum += grades[i];
    }

    return sum / MAX_GRADES;
}

// Function to print the grades and average grade
void print_grades(float grades[]) {
    int i;

    printf("Student Names: \n");
    for (i = 0; i < MAX_GRADES; i++) {
        printf("    %s: %f\n", grades[i], grades[i]);
    }

    printf("\nAverage Grade: %f\n", calculate_average_grade(grades));
}

int main() {
    // Array to store student names and grades
    char names[MAX_NAME_LENGTH][25];
    float grades[MAX_GRADES];

    // Get the current date and time
    char date_time[25];
    get_current_date_time(date_time);

    // Prompt the user to enter the student names and grades
    printf("Please enter the student names and grades:\n");

    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s", names[i]);
        scanf("%f", &grades[i]);
    }

    // Calculate and print the average grade
    print_grades(grades);

    return 0;
}