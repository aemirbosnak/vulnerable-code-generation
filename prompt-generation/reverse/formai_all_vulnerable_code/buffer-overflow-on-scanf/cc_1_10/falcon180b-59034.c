//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10
#define M 10

int arr[N][M];
int target;
int row, col;

void generate_matrix() {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void print_matrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int binary_search(int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid][0] == target) {
            row = mid;
            col = 0;
            return 1;
        } else if (arr[mid][0] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

void linear_search() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == target) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

int main() {
    generate_matrix();
    print_matrix();

    printf("Enter target value: ");
    scanf("%d", &target);

    binary_search(0, N - 1, target);
    if (row == -1) {
        linear_search();
    }

    if (row == -1 && col == -1) {
        printf("Target value not found!\n");
    } else {
        printf("Target value found at position (%d, %d)!\n", row, col);
    }

    return 0;
}