//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY_TIME 500000

// Function to print the current state of the towers
void print_towers(int n, int source, int dest, int aux)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i == source)
            printf("%d ", 0);
        else if (i == dest)
            printf("%d ", n - 1);
        else
            printf("%d ", i + 1);
    }
    printf("\n");
}

// Function to move n disks from source to dest using aux
void hanoi(int n, int source, int dest, int aux)
{
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", source, dest);
        print_towers(n, source, dest, aux);
        return;
    }

    hanoi(n - 1, source, aux, dest);

    printf("Move disk %d from %d to %d\n", n, source, dest);
    print_towers(n, source, dest, aux);

    hanoi(n - 1, aux, dest, source);
}

// Function to calculate the time taken to solve the puzzle
double get_time(struct timespec start_time, struct timespec end_time)
{
    double elapsed_time;
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    elapsed_time += (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;
    return elapsed_time;
}

int main(int argc, char *argv[])
{
    int n, i;
    srand(time(NULL));
    n = rand() % MAX_DISKS + 1;
    int source = 1, dest = 3, aux = 2;

    struct timespec start_time, end_time;
    clock_gettime(CLOCK_REALTIME, &start_time);

    hanoi(n, source, dest, aux);

    clock_gettime(CLOCK_REALTIME, &end_time);
    double time_taken = get_time(start_time, end_time);

    printf("Time taken to solve the puzzle: %.2f ms\n", time_taken);

    return 0;
}