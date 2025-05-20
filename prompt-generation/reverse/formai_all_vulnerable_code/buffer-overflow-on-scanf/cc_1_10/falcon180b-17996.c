//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define DELAY 100000 // 100ms delay

// Function to print the current state of the towers
void print_towers(int n, char source, char dest, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c: ", source);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c\n", source);
        } else {
            printf("%c ", source);
        }
    }
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c: ", dest);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c\n", dest);
        } else {
            printf("%c ", dest);
        }
    }
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("%c: ", aux);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c\n", aux);
        } else {
            printf("%c ", aux);
        }
    }
}

// Function to move n disks from source to dest using aux
void move_disks(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        printf("%c: ", dest);
        printf("%c\n", source);
        return;
    }
    move_disks(n - 1, source, aux, dest);
    printf("%c: ", dest);
    printf("%c\n", source);
    move_disks(n - 1, aux, dest, source);
}

// Function to get user input for number of disks
int get_n() {
    int n;
    do {
        printf("Enter the number of disks (1-100): ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX_DISKS);
    return n;
}

int main() {
    int n;
    char source, dest, aux;
    srand(time(NULL));
    n = get_n();
    source = 'A';
    dest = 'C';
    aux = 'B';

    // Initialize the towers
    printf("Initial state:\n");
    print_towers(n, source, dest, aux);

    // Move the disks
    move_disks(n, source, dest, aux);

    // Print the final state
    printf("\nFinal state:\n");
    print_towers(n, source, dest, aux);

    return 0;
}