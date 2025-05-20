//FormAI DATASET v1.0 Category: Math exercise ; Style: ultraprecise
// A program to calculate the average and standard deviation of a set of numbers

#include <stdio.h>  // for printf and scanf
#include <math.h>   // for sqrt and pow

#define MAX_NUMS 100  // maximum number of values that can be entered

int main()
{
    double nums[MAX_NUMS];  // array to hold the values
    double sum = 0.0;       // variable to store the sum of the values
    int count = 0;          // variable to keep track of the number of values entered

    // Prompt the user to enter the values
    printf("Enter the values (one per line, type a letter to stop):\n");

    // Loop through the values entered by the user
    while (scanf("%lf", &nums[count]) == 1)
    {
        sum += nums[count];  // add the value to the sum
        count++;             // increment the count

        // Check if the maximum number of values has been reached
        if (count == MAX_NUMS)
        {
            printf("Maximum number of values reached, stopping input\n");
            break;
        }
    }

    // Calculate the average of the values
    double avg = sum / count;

    // Calculate the standard deviation of the values
    double variance = 0.0;  // variable to store the variance

    for (int i = 0; i < count; i++)
    {
        variance += pow(nums[i] - avg, 2);  // add the difference from the average squared to the variance
    }

    variance /= count;  // divide by the number of values to get the variance
    double std_dev = sqrt(variance);  // square root of the variance is the standard deviation

    // Print out the results
    printf("Average: %lf\n", avg);
    printf("Standard deviation: %lf\n", std_dev);

    return 0;
}