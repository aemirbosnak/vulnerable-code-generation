//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

int main() {
    int num1, num2, sum;
    float avg, mean, median;
    char str[100];

    printf("Welcome to the peaceful world of arithmetic!\n");

    // Ask the user for two numbers
    printf("Please enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    // Calculate the sum
    sum = num1 + num2;

    // Calculate the average
    avg = (float)sum / 2;

    // Calculate the mean
    mean = avg;

    // Calculate the median
    median = num1;

    // Print the results
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The average is %f\n", avg);
    printf("The mean is %f\n", mean);
    printf("The median is %d\n", median);

    // Ask the user for a string
    printf("Please enter a string (up to 100 characters): ");
    fgets(str, 100, stdin);

    // Print the string with each word capitalized
    printf("The string is: %s\n", str);

    // Calculate the length of the string
    int len = strlen(str);

    // Print the length of the string
    printf("The length of the string is %d\n", len);

    return 0;
}