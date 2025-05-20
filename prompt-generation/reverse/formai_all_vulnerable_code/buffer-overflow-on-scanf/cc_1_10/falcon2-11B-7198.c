//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>

void fibonacci(int n, int* arr) {
    if (n <= 0)
        return;

    if (n == 1)
        arr[0] = 0;
    else if (n == 2)
        arr[0] = 1;
    else {
        fibonacci(n-1, arr);
        fibonacci(n-2, arr);
        arr[0] = arr[0] + arr[1];
    }
}

void print_grid(int* grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j < grid[i])
                printf(" ");
            else if (grid[i] == j)
                printf("*");
            else
                printf("_");
        }
        printf("\n");
    }
}

int main() {
    int n, i, j, width = 0, height = 0;
    int grid[100];
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        fibonacci(i+1, grid);

    printf("\nFibonacci Sequence: \n");
    for (i = 0; i < n; i++)
        printf("%d ", grid[i]);

    width = grid[0] + 1;
    height = n;
    printf("\nGrid:\n");
    print_grid(grid, width, height);

    return 0;
}