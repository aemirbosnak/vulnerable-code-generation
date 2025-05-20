//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

// prints the intro message
void intro(void) {
    printf("Welcome to the Tower of Hanoi game!\n\n");
    printf("The objective of the game is to move all the disks from the starting peg to the ending peg, following these rules:\n");
    printf("- Only one disk can be moved at a time.\n");
    printf("- No disk may be placed on top of a smaller disk.\n\n");
}

// prints the towers
void print_towers(int n, char start_peg, char aux_peg, char end_peg) {
    // print the start peg
    printf("%c", start_peg);
    for (int i = 1; i <= n; i++) {
        printf(" %d", i);
    }
    printf("\n");

    // print the aux peg
    printf("%c", aux_peg);
    for (int i = 1; i <= n; i++) {
        printf("  ");
    }
    printf("\n");

    // print the end peg
    printf("%c", end_peg);
    for (int i = 1; i <= n; i++) {
        printf("  ");
    }
    printf("\n");
}

// moves the disks from the start peg to the end peg using the aux peg
void move_disks(int n, char start_peg, char aux_peg, char end_peg) {
    // move n-1 disks from the start peg to the aux peg using the end peg as the aux peg
    if (n > 1) {
        move_disks(n-1, start_peg, end_peg, aux_peg);
    }

    // move the largest disk from the start peg to the end peg
    printf("Move disk %d from peg %c to peg %c\n", n, start_peg, end_peg);

    // move n-1 disks from the aux peg to the end peg using the start peg as the aux peg
    if (n > 1) {
        move_disks(n-1, aux_peg, start_peg, end_peg);
    }
}

int main(void) {
    // intro
    intro();

    // get the number of disks
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // print the initial towers
    printf("\nInitial towers:\n");
    print_towers(n, 'A', 'B', 'C');

    // move the disks
    printf("\nMoving the disks:\n");
    move_disks(n, 'A', 'B', 'C');

    // print the final towers
    printf("\nFinal towers:\n");
    print_towers(n, 'C', 'B', 'A');

    return 0;
}