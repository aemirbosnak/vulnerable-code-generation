//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to print the current configuration of the tower
void print(char arr[MAX][MAX], int n, int h) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '*') {
                printf("\t%c\t", arr[i][j]);
            } else {
                printf("\t\t");
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid or not
int isValid(char arr[MAX][MAX], int n, int from, int to, int h) {
    if (from < 0 || from >= n || to < 0 || to >= n || arr[to][h]!= '\0') {
        return 0;
    }
    return 1;
}

// Function to move the disk from one peg to another
void move(char arr[MAX][MAX], int n, int from, int to, int h) {
    if (isValid(arr, n, from, to, h)) {
        arr[to][h] = arr[from][h];
        arr[from][h] = '\0';
    }
}

// Function to solve the tower of hanoi problem
void solve(char arr[MAX][MAX], int n, int from, int to, int h, int count) {
    if (count == n - 1) {
        printf("\n\t\tMove %d: Move disk %d from %d to %d\n", count + 1, n - 1, from, to);
        move(arr, n, from, to, h);
        print(arr, n, h);
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i][h]!= '\0') {
            solve(arr, n, i, to, h, count);
        }
    }
}

// Main function to call the solve function
int main() {
    printf("\n\t\tTower of Hanoi Problem\n");
    int n;
    printf("\n\tEnter the number of disks: ");
    scanf("%d", &n);
    char arr[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = '\0';
        }
    }
    arr[0][0] = '*';
    printf("\n\tInitial configuration:\n");
    print(arr, n, 0);
    printf("\n\tSolving Tower of Hanoi problem...\n");
    solve(arr, n, 0, 2, 0, 0);
    return 0;
}