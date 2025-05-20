//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

int main() {
    int n, start_rod, end_rod, temp_rod;
    int disks[MAX_DISKS];
    clock_t start_time, end_time;
    double elapsed_time;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize the disks
    for (int i = 0; i < n; i++) {
        disks[i] = i + 1;
    }

    // Set the start and end rods
    start_rod = 0;
    end_rod = 2;

    // Get the start time
    start_time = clock();

    // Solve the Tower of Hanoi problem
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            temp_rod = 3 - start_rod - end_rod;
            disks[end_rod] = disks[start_rod];
            disks[start_rod] = disks[temp_rod];
            disks[temp_rod] = disks[end_rod];
        }
        printf("Move disk %d from rod %d to rod %d\n", disks[i], start_rod, end_rod);
        start_rod = end_rod;
        end_rod = 3 - start_rod - end_rod;
    }

    // Get the end time
    end_time = clock();

    // Calculate the elapsed time
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}