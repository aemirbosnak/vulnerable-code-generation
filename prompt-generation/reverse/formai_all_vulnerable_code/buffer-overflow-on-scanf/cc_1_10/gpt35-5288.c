//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genious
#include<stdio.h>

void moveDisc(int, char, char, char);
void printLine();

int main() {
    int n;
    printf("Welcome to the genius Tower of Hanoi program!\n");
    printf("Enter the number of discs to play with: ");
    scanf("%d", &n);
    printf("\n");

    // print game board
    printf("Initial Board:\n");
    printLine();
    for(int i=n; i>=1; i--) {
        printf("|");
        for(int j=n; j>=1; j--) {
            if(j<i) printf("   ");
            else printf(" * ");
        }
        printf("|\n");
    }
    printLine();
    printf("\n");

    // initiate game
    moveDisc(n, 'A', 'C', 'B');

    printf("\nCongratulations, you have won the game!");

    return 0;
}

void moveDisc(int n, char from, char to, char spare) {
    if(n == 1) {
        printf("Move disc from %c to %c\n", from, to);
        return;
    }

    // move n-1 discs from 'from' to 'spare', using 'to' as a spare peg
    moveDisc(n-1, from, spare, to);
    // move the remaining disc from 'from' to 'to'
    printf("Move disc from %c to %c\n", from, to);
    // move n-1 discs from 'spare' to 'to', using 'from' as a spare peg
    moveDisc(n-1, spare, to, from);
}

void printLine() {
    for(int i=0; i<15; i++) {
        printf("-");
    }
    printf("\n");
}