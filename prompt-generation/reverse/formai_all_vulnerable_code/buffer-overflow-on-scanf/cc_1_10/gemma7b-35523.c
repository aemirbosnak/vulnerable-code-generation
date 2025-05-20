//Gemma-7B DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Declare variables
    int n, i, j, k, l, m, x, y, z;
    float avg, sum, stddev;
    char name[20];

    // Get the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for student data
    struct student
    {
        char name[20];
        int marks[3];
    } students[n];

    // Get student data
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the marks of student %d: ", i + 1);
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &students[i].marks[j]);
        }
    }

    // Calculate the average marks
    sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum += students[i].marks[j];
        }
        avg = (float)sum / 3;
        printf("The average marks of student %d is: %.2f\n", i + 1, avg);
    }

    // Calculate the standard deviation
    stddev = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            x = students[i].marks[j] - avg;
            stddev += x * x;
        }
        stddev = (float)sqrt(stddev / (n - 1)) * 100;
        printf("The standard deviation of student %d is: %.2f%\n", i + 1, stddev);
    }

    return 0;
}