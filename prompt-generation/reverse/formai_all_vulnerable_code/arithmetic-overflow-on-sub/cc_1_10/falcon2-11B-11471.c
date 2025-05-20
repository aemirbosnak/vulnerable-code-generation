//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int num_disks;
int num_stacks;
int stacks[3][3];
int moves[3];

void print_stacks() {
    for (int i = 0; i < num_stacks; i++) {
        for (int j = 0; j < num_stacks; j++) {
            printf("%d ", stacks[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    printf("Enter the number of stacks: ");
    scanf("%d", &num_stacks);

    printf("Enter the initial configuration of the disks:\n");
    for (int i = 0; i < num_stacks; i++) {
        for (int j = 0; j < num_stacks; j++) {
            scanf("%d", &stacks[i][j]);
        }
    }

    printf("Enter the destination of the first disk: ");
    scanf("%d", &moves[0]);

    printf("Enter the destination of the second disk: ");
    scanf("%d", &moves[1]);

    printf("Enter the destination of the third disk: ");
    scanf("%d", &moves[2]);

    int moves_left = num_disks - 1;

    while (moves_left > 0) {
        if (moves[0] == 0) {
            printf("Move the %dth disk from stack %d to stack %d\n", moves_left, stacks[0][0], stacks[1][0]);
            stacks[0][0] = stacks[1][0];
            stacks[1][0] = moves_left;
            moves_left = 0;
        } else if (moves[1] == 0) {
            printf("Move the %dth disk from stack %d to stack %d\n", moves_left, stacks[0][1], stacks[2][0]);
            stacks[0][1] = stacks[2][0];
            stacks[2][0] = moves_left;
            moves_left = 0;
        } else if (moves[2] == 0) {
            printf("Move the %dth disk from stack %d to stack %d\n", moves_left, stacks[0][2], stacks[1][1]);
            stacks[0][2] = stacks[1][1];
            stacks[1][1] = moves_left;
            moves_left = 0;
        } else {
            int temp = stacks[0][moves[0]];
            stacks[0][moves[0]] = stacks[1][moves[1]];
            stacks[1][moves[1]] = stacks[2][moves[2]];
            stacks[2][moves[2]] = temp;

            moves[0] = stacks[0][moves[0]];
            moves[1] = stacks[1][moves[1]];
            moves[2] = stacks[2][moves[2]];

            moves_left--;
        }
    }

    printf("The final configuration is:\n");
    print_stacks();

    return 0;
}