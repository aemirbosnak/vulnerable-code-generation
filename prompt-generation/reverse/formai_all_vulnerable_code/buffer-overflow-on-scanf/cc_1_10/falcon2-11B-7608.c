//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

// Function to parse a string into an integer
int parseInt(char* str) {
    int result = 0;
    int sign = 1;

    for (int i = 0; str[i]!= '\0'; i++) {
        if (str[i] == '-' || str[i] == '+') {
            sign = -sign;
        } else {
            result = result * 10 + (str[i] - '0');
        }
    }

    return result * sign;
}

// Function to parse a string into a float
float parseFloat(char* str) {
    char* end;
    long double result = strtold(str, &end);
    if (*end!= '\0' || (end - str) > 1) {
        return 0;
    }
    return result;
}

// Function to find the median of a set of numbers
float findMedian(float* numbers, int size) {
    float median;
    int halfSize = size / 2;

    if (size % 2 == 0) {
        median = (numbers[halfSize] + numbers[halfSize - 1]) / 2;
    } else {
        median = numbers[halfSize];
    }

    return median;
}

int main() {
    int numOfNumbers;
    char* input;

    printf("Enter the number of integers: ");
    scanf("%d", &numOfNumbers);

    if (numOfNumbers <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    input = (char*) malloc(numOfNumbers * sizeof(char));

    printf("Enter the integers: ");
    for (int i = 0; i < numOfNumbers; i++) {
        fgets(input + i * numOfNumbers, numOfNumbers, stdin);
    }

    int* numbers = (int*) malloc(numOfNumbers * sizeof(int));
    for (int i = 0; i < numOfNumbers; i++) {
        numbers[i] = parseInt(input + i * numOfNumbers);
    }

    float median = findMedian(numbers, numOfNumbers);
    printf("The median of the integers is: %.2f\n", median);

    free(input);
    free(numbers);

    return 0;
}