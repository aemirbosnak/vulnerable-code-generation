//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Function to display the current state of the towers
void display(int n, char from, char to, char aux) {
    int i;
    for(i=0; i<n; i++) {
        printf("%c ", 'A'+i);
    }
    printf("\n");
    printf("Move disk %d from %c to %c\n", n, from, to);
}

//Function to check if the move is valid or not
int isValid(int n, char from, char to) {
    if(from == 'A' && to == 'C' && n > 0)
        return 1;
    else if(from == 'C' && to == 'B' && n > 0)
        return 1;
    else if(from == 'B' && to == 'A' && n > 0)
        return 1;
    else
        return 0;
}

//Function to move the disk from one tower to another
void move(char from, char to, int n) {
    if(from == 'A' && to == 'C') {
        printf("Move disk %d from %c to %c\n", n, from, to);
    }
    else if(from == 'C' && to == 'B') {
        printf("Move disk %d from %c to %c\n", n, from, to);
    }
    else if(from == 'B' && to == 'A') {
        printf("Move disk %d from %c to %c\n", n, from, to);
    }
}

//Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    move(from, to, n);
    towerOfHanoi(n-1, aux, to, from);
}

//Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}