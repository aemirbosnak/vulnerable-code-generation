//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_DISKS 100
#define MAX_MOVES 1000

// Function prototypes
void moveTower(int n, char from, char to, char aux);
void printTower(int n, char from, char to, char aux);
void playGame(int n);

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    playGame(n);
    return 0;
}

void moveTower(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c.\n", from, to);
        return;
    }
    moveTower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c.\n", n, from, to);
    moveTower(n - 1, aux, to, from);
}

void printTower(int n, char from, char to, char aux) {
    if (n == 0) {
        return;
    }
    printTower(n - 1, from, aux, to);
    printf("Disk %d is on peg %c.\n", n, from);
    printTower(n - 1, to, from, aux);
}

void playGame(int n) {
    char from = 'A', to = 'C', aux = 'B';
    int moves = 0;
    srand(time(NULL));
    while (moves < MAX_MOVES) {
        int choice = rand() % 3;
        if (choice == 0) {
            moveTower(n, from, to, aux);
            from = to;
            to = aux;
            aux = 'B';
        } else if (choice == 1) {
            moveTower(n, from, aux, to);
            from = aux;
            to = to;
            aux = 'B';
        } else {
            moveTower(n, to, aux, from);
            from = to;
            to = aux;
            aux = 'B';
        }
        moves++;
    }
    printf("Game over. You took %d moves.\n", moves);
    printTower(n, from, to, aux);
}