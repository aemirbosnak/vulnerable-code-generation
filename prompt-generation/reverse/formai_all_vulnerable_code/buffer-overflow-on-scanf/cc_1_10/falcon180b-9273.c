//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the square root of a number
double sqrt(double x) {
    return sqrt(x);
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth power of a number
double power(double x, int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to calculate the sum of the series 1 + 1/2 + 1/3 +... + 1/n
double sum_series(int n) {
    double result = 0.0;
    for (int i = 1; i <= n; i++) {
        result += 1.0 / i;
    }
    return result;
}

// Function to calculate the average of an array of numbers
double average(int arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of an array of numbers
double std_dev(int arr[], int size, double avg) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - avg, 2.0);
    }
    return sqrt(sum / size);
}

int main() {
    int n, i;
    double x, result;

    // Prompt the user to enter the number of terms in the series
    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);

    // Calculate the sum of the series
    result = sum_series(n);

    // Print the result
    printf("The sum of the series is: %lf\n", result);

    return 0;
}