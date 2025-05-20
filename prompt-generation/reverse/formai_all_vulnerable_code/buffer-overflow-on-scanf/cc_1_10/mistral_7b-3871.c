//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void func(int *arr, int size) {
    int i;

    printf("\nFunction Started...\n");

    if (arr == NULL || size <= 0) {
        fprintf(stderr, "Error: Invalid Argument(s)\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < size; i++) {
        if (arr[i] < 0) {
            fprintf(stderr, "Error: Negative number found at index %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("Function Successfully Executed...\n");
}

int main() {
    int i, j, nums[MAX_SIZE];
    char str[MAX_SIZE];

    printf("\nProgram Started...\n");

    printf("Enter the number of elements: ");
    scanf("%d", &i);

    if (i <= 0) {
        fprintf(stderr, "Error: Invalid number of elements\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integers: ", i);

    for (j = 0; j < i; j++) {
        scanf("%d", &nums[j]);

        if (nums[j] < 0) {
            fprintf(stderr, "Error: Negative number found at index %d\n", j);
            exit(EXIT_FAILURE);
        }
    }

    func(nums, i);

    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);

    if (len > MAX_SIZE - 1) {
        fprintf(stderr, "Error: String too long\n");
        exit(EXIT_FAILURE);
    }

    printf("String: %s\n", str);

    printf("\nFunction to calculate sum of numbers in an array:\n");
    int sum = 0;

    for (j = 0; j < i; j++) {
        sum += nums[j];
    }

    printf("Sum: %d\n", sum);

    printf("\nProgram Ended...\n");

    return 0;
}