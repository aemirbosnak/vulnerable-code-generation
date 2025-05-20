//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(char tower_a[], char tower_b[], char tower_c[], int top) {
    int i;

    for (i = top; i >= 0; i--) {
        printf("%c ", tower_a[i]);
    }
    printf("\n");

    for (i = top; i >= 0; i--) {
        printf("%c ", tower_b[i]);
    }
    printf("\n");

    for (i = top; i >= 0; i--) {
        printf("%c ", tower_c[i]);
    }
    printf("\n\n");
}

// Function to check if a move is valid
int is_valid_move(char from_tower[], char to_tower[], int n) {
    if (from_tower[n - 1] == '0') {
        return 0;
    }

    if (to_tower[n - 1]!= '0' && to_tower[n - 1] <= from_tower[n - 1]) {
        return 0;
    }

    return 1;
}

// Function to move a disk from one tower to another
void move_disk(char from_tower[], char to_tower[], int n) {
    char temp = from_tower[n - 1];
    from_tower[n - 1] = '0';
    to_tower[n - 1] = temp;
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from_tower[], char to_tower[], char aux_tower[]) {
    if (n == 1) {
        move_disk(from_tower, to_tower, 1);
        return;
    }

    tower_of_hanoi(n - 1, from_tower, aux_tower, to_tower);

    move_disk(from_tower, to_tower, n);

    print_towers(from_tower, to_tower, aux_tower, n - 1);
}

// Main function
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    char from_tower[MAX_DISKS];
    char to_tower[MAX_DISKS];
    char aux_tower[MAX_DISKS];

    // Initialize the towers
    for (int i = n; i >= 1; i--) {
        from_tower[i - 1] = '0' + i;
    }
    for (int i = 0; i < n; i++) {
        to_tower[i] = '0';
    }
    for (int i = 0; i < n; i++) {
        aux_tower[i] = '0';
    }

    // Solve the Tower of Hanoi problem
    tower_of_hanoi(n, from_tower, to_tower, aux_tower);

    return 0;
}