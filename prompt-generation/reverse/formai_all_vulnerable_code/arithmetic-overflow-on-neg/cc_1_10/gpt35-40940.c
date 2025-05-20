//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int factorials(int num) {
    if (num == 1)
        return 1;
    else
        return num * factorials(num - 1);
}

int fibonacci(int num) {
    if (num == 0 || num == 1)
        return 1;
    else
        return fibonacci(num - 1) + fibonacci(num - 2);
}

int binarySearch(int arr[], int left, int right, int num) {
    if (right >= left) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == num)
            return middle;

        if (arr[middle] > num)
            return binarySearch(arr, left, middle - 1, num);

        return binarySearch(arr, middle + 1, right, num);
    }

    return -1;
}

float power(float num, int exponent) {
    if (exponent == 0)
        return 1;

    if (exponent > 0)
        return num * power(num, exponent - 1);

    if (exponent < 0)
        return 1 / (num * power(num, (-exponent) - 1));
}

int main() {
    int choice;

    printf("Please enter the number of the function you want to perform:\n");
    printf("1. Factorials\n");
    printf("2. Fibonacci Series\n");
    printf("3. Binary Search\n");
    printf("4. Power Function\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int num;

        printf("Please enter the number you want to find the factorial of:\n");
        scanf("%d", &num);

        printf("%d! = %d\n", num, factorials(num));
    } else if (choice == 2) {
        int num, i;

        printf("Please enter the number of terms you want in the series:\n");
        scanf("%d", &num);

        printf("The Fibonacci Series is:\n");

        for (i = 0; i < num; i++)
            printf("%d ", fibonacci(i));

        printf("\n");
    } else if (choice == 3) {
        int * arr, num, i, value, result;

        printf("Please enter the size of the array:\n");
        scanf("%d", &num);

        arr = (int *) malloc(num * sizeof(int));

        printf("Please enter the elements of the array in ascending order:\n");

        for (i = 0; i < num; i++)
            scanf("%d", &arr[i]);

        printf("Please enter the value you want to search for:\n");
        scanf("%d", &value);

        result = binarySearch(arr, 0, num - 1, value);

        if (result == -1)
            printf("Value not found in array.\n");
        else
            printf("Value found at index %d.\n", result);

        free(arr);
    } else if (choice == 4) {
        float num, result;
        int exponent;

        printf("Please enter the number you want to take the power of:\n");
        scanf("%f", &num);

        printf("Please enter the exponent:\n");
        scanf("%d", &exponent);

        result = power(num, exponent);

        printf("%f to the power of %d is %f\n", num, exponent, result);
    } else {
        printf("Invalid number entered.\n");
    }

    return 0;
}