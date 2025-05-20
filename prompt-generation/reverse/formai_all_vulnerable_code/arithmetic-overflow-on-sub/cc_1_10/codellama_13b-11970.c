//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
/*
 * Tower of Hanoi Problem in a Grateful Style
 *
 * Description: This program solves the Tower of Hanoi problem in a grateful style.
 * The program first thanks the user for playing the game, then it asks the user for the number
 * of disks to be moved. After that, it displays the steps for solving the Tower of Hanoi problem
 * in a grateful style.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>

#define MAX_DISKS 100

void print_disks(int disks) {
    int i;
    printf("{");
    for (i = disks; i > 0; i--) {
        printf(" %d ", i);
    }
    printf("}");
}

void move_disks(int disks, char from, char to, char temp) {
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
    } else {
        move_disks(disks - 1, from, temp, to);
        printf("Move disk %d from %c to %c\n", disks, from, to);
        move_disks(disks - 1, temp, to, from);
    }
}

int main() {
    int disks;
    char from, to, temp;

    printf("Welcome to the Tower of Hanoi in a Grateful Style!\n");
    printf("This program will solve the Tower of Hanoi problem for you.\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &disks);

    from = 'A';
    to = 'B';
    temp = 'C';

    printf("Here are the steps for solving the Tower of Hanoi problem:\n");
    move_disks(disks, from, to, temp);

    printf("Thank you for playing the game! Goodbye!\n");

    return 0;
}