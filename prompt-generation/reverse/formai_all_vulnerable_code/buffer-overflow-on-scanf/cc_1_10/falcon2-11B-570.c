//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <math.h>

// Function to calculate the square root of a number
double sqrt(double num) {
    return sqrt(num);
}

// Function to calculate the square of a number
double square(double num) {
    return num * num;
}

// Function to calculate the cube of a number
double cube(double num) {
    return num * num * num;
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the sum of a list of numbers
double sum(int len, double *numbers) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += numbers[i];
    }
    return sum;
}

int main() {
    // Prompt the user for input
    printf("Enter a number: ");
    double num;
    scanf("%lf", &num);

    // Display the input number
    printf("Input number: %lf\n", num);

    // Calculate the square root of the input number
    double sqrtNum = sqrt(num);
    printf("Square root of %lf: %lf\n", num, sqrtNum);

    // Calculate the square of the input number
    double squareNum = square(num);
    printf("Square of %lf: %lf\n", num, squareNum);

    // Calculate the cube of the input number
    double cubeNum = cube(num);
    printf("Cube of %lf: %lf\n", num, cubeNum);

    // Calculate the factorial of the input number
    int factorialNum = factorial(num);
    printf("Factorial of %d: %d\n", num, factorialNum);

    // Prompt the user for a list of numbers
    printf("Enter a list of numbers (comma separated): ");
    char input[100];
    scanf("%s", input);

    // Convert the input string to a list of numbers
    char *delimiter = ",";
    char *token;
    int len = strlen(input);
    int i = 0;
    double *numbers = malloc(len * sizeof(double));
    while ((token = strsep(&input, delimiter))!= NULL) {
        numbers[i] = atof(token);
        i++;
    }

    // Calculate the sum of the input list of numbers
    double sumNum = sum(len, numbers);
    printf("Sum of %d numbers: %lf\n", len, sumNum);

    // Free the memory allocated for the list of numbers
    free(numbers);

    return 0;
}