//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include <stdio.h>
#include <math.h>

// Function declarations
double calculateMean(double arr[], int n);
double calculateVariance(double arr[], int n, double mean);
double calculateStandardDeviation(double variance);

int main()
{
    int n; // Number of data points
    double data[100]; // Array to store data points
    double mean, variance, standardDeviation; // Variables to store mean, variance and standard deviation

    // Read number of data points from user
    printf("Enter number of data points (less than 100): ");
    scanf("%d", &n);

    // Read data points from user and store in array
    printf("Enter the data points\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &data[i]);
    }

    // Calculate mean
    mean = calculateMean(data, n);

    // Calculate variance
    variance = calculateVariance(data, n, mean);

    // Calculate standard deviation
    standardDeviation = calculateStandardDeviation(variance);

    // Print mean, variance and standard deviation
    printf("Mean: %.2lf\n", mean);
    printf("Variance: %.2lf\n", variance);
    printf("Standard deviation: %.2lf\n", standardDeviation);

    return 0;
}

// Function to calculate mean
double calculateMean(double arr[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate variance
double calculateVariance(double arr[], int n, double mean)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += pow((arr[i] - mean), 2);
    }
    return sum / n;
}

// Function to calculate standard deviation
double calculateStandardDeviation(double variance)
{
    return sqrt(variance);
}