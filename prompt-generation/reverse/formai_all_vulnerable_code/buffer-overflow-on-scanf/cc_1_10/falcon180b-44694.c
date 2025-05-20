//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;

    // Get user input for the number of random numbers to generate
    printf("Enter the number of random numbers you want to generate: ");
    scanf("%d", &n);

    // Get user input for the minimum and maximum values of the random numbers
    printf("Enter the minimum value: ");
    int min = rand_num(1, 100);
    printf("Enter the maximum value: ");
    int max = rand_num(min, 1000);

    // Generate n random numbers between min and max
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand_num(min, max);
    }

    // Calculate the sum, average, and standard deviation of the generated numbers
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double avg = (double) sum / n;
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += pow((arr[i] - avg), 2);
    }
    double stdev = sqrt(variance / n);

    // Calculate the factorial of the number of generated numbers
    int fact = factorial(n);

    // Print the results
    printf("The sum of the generated numbers is: %d\n", sum);
    printf("The average of the generated numbers is: %.2f\n", avg);
    printf("The standard deviation of the generated numbers is: %.2f\n", stdev);
    printf("The factorial of the number of generated numbers is: %d\n", fact);

    return 0;
}