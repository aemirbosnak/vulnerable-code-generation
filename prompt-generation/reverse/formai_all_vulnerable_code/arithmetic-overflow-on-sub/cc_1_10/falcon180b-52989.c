//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the disks on the poles
void print_disks(int pole, int n) {
    for (int i = n; i >= 1; i--) {
        printf(" ");
    }
    printf("|");
    for (int i = 1; i <= n; i++) {
        printf(" %d ", i);
    }
    printf("|\n");
}

// Function to move the disk from one pole to another
void move_disk(int from, int to, int n) {
    if (n == 1) {
        printf("Move disk %d from pole %d to pole %d\n", n, from, to);
    } else {
        move_disk(from, to - 1, n - 1);
        printf("Move disk %d from pole %d to pole %d\n", n, from, to);
        move_disk(to, from, n - 1);
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk %d from pole %d to pole %d\n", n, from, to);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    printf("Move disk %d from pole %d to pole %d\n", n, from, to);
    tower_of_hanoi(n - 1, aux, to, from);
}

// Function to generate a random number within the given range
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random instance of the Tower of Hanoi problem
void generate_instance(int n) {
    int from = rand_num(1, 3);
    int to = rand_num(1, 3);
    int aux = rand_num(1, 3);
    while (from == to || from == aux || to == aux) {
        from = rand_num(1, 3);
        to = rand_num(1, 3);
        aux = rand_num(1, 3);
    }
    tower_of_hanoi(n, from, to, aux);
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n > MAX_DISKS) {
        printf("Number of disks cannot be greater than %d\n", MAX_DISKS);
        return 1;
    }
    printf("Tower of Hanoi problem with %d disks:\n", n);
    print_disks(1, n);
    generate_instance(n);
    return 0;
}