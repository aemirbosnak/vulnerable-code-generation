//Gemma-7B DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Declare variables
    int n, i, j, k;
    float x, y, z, avg, stddev;

    // Get the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for student grades
    float *grades = (float *)malloc(n * sizeof(float));

    // Get student grades
    printf("Enter the grades for each student: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &grades[i]);
    }

    // Calculate the average grade
    avg = 0.0f;
    for (i = 0; i < n; i++)
    {
        avg += grades[i];
    }
    avg /= n;

    // Calculate the standard deviation
    stddev = 0.0f;
    for (i = 0; i < n; i++)
    {
        stddev += (grades[i] - avg) * (grades[i] - avg);
    }
    stddev /= n - 1;
    stddev = sqrtf(stddev);

    // Print the results
    printf("The average grade is: %.2f\n", avg);
    printf("The standard deviation is: %.2f\n", stddev);

    // Free the memory
    free(grades);

    return 0;
}