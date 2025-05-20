//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>

void welcome() {
    printf("Welcome to C Warehouse Management System (WMS)!\n");
}

int sum(int a, int b) {
    return a + b;
}

float average(int a, int b, int c) {
    return (a + b + c) / 3;
}

int product(int a, int b) {
    return a * b;
}

long factorial(int n) {
    long result = 1;
    while (n > 1) {
        result *= n--;
    }
    return result;
}

float squareRoot(float n) {
    return sqrt(n);
}

int sumArrays(int arr1[], int arr2[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr1[i] + arr2[i];
    }
    return sum;
}

int productArrays(int arr1[], int arr2[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr1[i] * arr2[i];
    }
    return product;
}

float averageArrays(int arr1[], int arr2[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr1[i] + arr2[i];
    }
    return sum / 2;
}

long factorialArrays(int arr[], int size) {
    long factorial = 1;
    for (int i = 0; i < size; i++) {
        factorial *= arr[i];
    }
    return factorial;
}

int main() {
    welcome();

    int num1, num2;
    float num3, num4;
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};

    printf("Sum of %d and %d is: %d\n", num1, num2, sum(num1, num2));
    printf("Average of %d, %d, and %d is: %f\n", num3, num4, num3, average(num3, num4, num3));
    printf("Product of %d and %d is: %d\n", num3, num4, product(num3, num4));
    printf("Factorial of %d is: %ld\n", num3, factorial(num3));
    printf("Square root of %f is: %f\n", num4, squareRoot(num4));
    printf("Sum of %d and %d is: %d\n", arr1[0], arr2[0], sumArrays(arr1, arr2, 4));
    printf("Product of %d and %d is: %d\n", arr1[0], arr2[0], productArrays(arr1, arr2, 4));
    printf("Average of %d and %d is: %f\n", arr1[0], arr2[0], averageArrays(arr1, arr2, 4));
    printf("Factorial of %d is: %ld\n", arr1[0], factorialArrays(arr1, 4));
    printf("Sum of %d, %d, and %d is: %d\n", arr1[0], arr1[1], arr2[0], sumArrays(arr1, arr2, 3));
    printf("Product of %d, %d, and %d is: %d\n", arr1[0], arr1[1], arr2[0], productArrays(arr1, arr2, 3));
    printf("Average of %d, %d, and %d is: %f\n", arr1[0], arr1[1], arr2[0], averageArrays(arr1, arr2, 3));
    printf("Factorial of %d is: %ld\n", arr1[0], factorialArrays(arr1, 3));

    return 0;
}