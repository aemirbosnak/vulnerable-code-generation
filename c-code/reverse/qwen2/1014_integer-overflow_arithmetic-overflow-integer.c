#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int size) {
    int total = 0;
    for (int i = 0; i <= size; i++) { // Vulnerable to integer overflow if size is very large
        total += arr[i];
    }
    return total;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = sum(arr, n);
    printf("Sum of elements: %d\n", result);
    free(arr);
    return 0;
}
