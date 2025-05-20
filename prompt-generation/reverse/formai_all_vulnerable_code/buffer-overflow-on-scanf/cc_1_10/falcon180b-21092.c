//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 20
#define DELAY 50000 // 50ms delay

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux, int *towers) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("From tower: ");
        } else if (i == 1) {
            printf("To tower: ");
        } else {
            printf("Aux tower: ");
        }
        printf("%c ", towers[i] + 'A');
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, int *towers) {
    char aux = 'A' + (from == 'A'? 'B' : 'A');
    int i;

    // Move n-1 disks from from to aux
    for (i = n - 1; i >= 0; i--) {
        towers[to] = towers[to] + towers[from];
        towers[from] = '0' + i;
        print_towers(n, from, to, aux, towers);
        usleep(DELAY);
    }

    // Move the last disk from from to to
    towers[to] = towers[to] + towers[from];
    towers[from] = '0' + i;
    print_towers(n, from, to, aux, towers);
    usleep(DELAY);
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int n, char from, char to, char aux, int *towers) {
    if (n == 1) {
        printf("Move disk 1 from tower %c to tower %c\n", from, to);
        towers[to] = towers[to] + towers[from];
        towers[from] = '0';
        print_towers(n, from, to, aux, towers);
        usleep(DELAY);
        return;
    }

    hanoi(n - 1, from, aux, to, towers);
    move_disk(n, from, to, towers);
    hanoi(n - 1, aux, to, from, towers);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    char from = 'A', to = 'C', aux = 'B';
    int towers[3] = { 0 };

    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++) {
        towers[from] = towers[from] + (rand() % 10) + '0';
        print_towers(n, from, to, aux, towers);
        usleep(DELAY);
    }

    hanoi(n, from, to, aux, towers);

    return 0;
}