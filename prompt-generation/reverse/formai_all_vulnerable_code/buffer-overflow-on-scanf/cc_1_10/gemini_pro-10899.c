//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of the first n natural numbers
int sum_of_naturals(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum_of_naturals(n - 1);
    }
}

// Function to calculate the sum of the squares of the first n natural numbers
int sum_of_squares(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n * n + sum_of_squares(n - 1);
    }
}

// Function to calculate the sum of the cubes of the first n natural numbers
int sum_of_cubes(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n * n * n + sum_of_cubes(n - 1);
    }
}

// Function to calculate the sum of the reciprocals of the first n natural numbers
double sum_of_reciprocals(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1.0 / n + sum_of_reciprocals(n - 1);
    }
}

// Function to calculate the sum of the logarithms of the first n natural numbers
double sum_of_logarithms(int n) {
    if (n == 0) {
        return 0;
    } else {
        return log(n) + sum_of_logarithms(n - 1);
    }
}

// Function to calculate the sum of the sines of the first n natural numbers
double sum_of_sines(int n) {
    if (n == 0) {
        return 0;
    } else {
        return sin(n) + sum_of_sines(n - 1);
    }
}

// Function to calculate the sum of the cosines of the first n natural numbers
double sum_of_cosines(int n) {
    if (n == 0) {
        return 0;
    } else {
        return cos(n) + sum_of_cosines(n - 1);
    }
}

// Function to calculate the sum of the tangents of the first n natural numbers
double sum_of_tangents(int n) {
    if (n == 0) {
        return 0;
    } else {
        return tan(n) + sum_of_tangents(n - 1);
    }
}

// Function to calculate the sum of the cotangents of the first n natural numbers
double sum_of_cotangents(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1.0 / tan(n) + sum_of_cotangents(n - 1);
    }
}

// Function to calculate the sum of the secants of the first n natural numbers
double sum_of_secants(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1.0 / cos(n) + sum_of_secants(n - 1);
    }
}

// Function to calculate the sum of the cosecants of the first n natural numbers
double sum_of_cosecants(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1.0 / sin(n) + sum_of_cosecants(n - 1);
    }
}

int main() {
    // Get the input from the user
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the sum of the first n natural numbers
    int sum_of_naturals_result = sum_of_naturals(n);

    // Calculate the sum of the squares of the first n natural numbers
    int sum_of_squares_result = sum_of_squares(n);

    // Calculate the sum of the cubes of the first n natural numbers
    int sum_of_cubes_result = sum_of_cubes(n);

    // Calculate the sum of the reciprocals of the first n natural numbers
    double sum_of_reciprocals_result = sum_of_reciprocals(n);

    // Calculate the sum of the logarithms of the first n natural numbers
    double sum_of_logarithms_result = sum_of_logarithms(n);

    // Calculate the sum of the sines of the first n natural numbers
    double sum_of_sines_result = sum_of_sines(n);

    // Calculate the sum of the cosines of the first n natural numbers
    double sum_of_cosines_result = sum_of_cosines(n);

    // Calculate the sum of the tangents of the first n natural numbers
    double sum_of_tangents_result = sum_of_tangents(n);

    // Calculate the sum of the cotangents of the first n natural numbers
    double sum_of_cotangents_result = sum_of_cotangents(n);

    // Calculate the sum of the secants of the first n natural numbers
    double sum_of_secants_result = sum_of_secants(n);

    // Calculate the sum of the cosecants of the first n natural numbers
    double sum_of_cosecants_result = sum_of_cosecants(n);

    // Print the results to the console
    printf("The sum of the first %d natural numbers is: %d\n", n, sum_of_naturals_result);
    printf("The sum of the squares of the first %d natural numbers is: %d\n", n, sum_of_squares_result);
    printf("The sum of the cubes of the first %d natural numbers is: %d\n", n, sum_of_cubes_result);
    printf("The sum of the reciprocals of the first %d natural numbers is: %f\n", n, sum_of_reciprocals_result);
    printf("The sum of the logarithms of the first %d natural numbers is: %f\n", n, sum_of_logarithms_result);
    printf("The sum of the sines of the first %d natural numbers is: %f\n", n, sum_of_sines_result);
    printf("The sum of the cosines of the first %d natural numbers is: %f\n", n, sum_of_cosines_result);
    printf("The sum of the tangents of the first %d natural numbers is: %f\n", n, sum_of_tangents_result);
    printf("The sum of the cotangents of the first %d natural numbers is: %f\n", n, sum_of_cotangents_result);
    printf("The sum of the secants of the first %d natural numbers is: %f\n", n, sum_of_secants_result);
    printf("The sum of the cosecants of the first %d natural numbers is: %f\n", n, sum_of_cosecants_result);

    return 0;
}