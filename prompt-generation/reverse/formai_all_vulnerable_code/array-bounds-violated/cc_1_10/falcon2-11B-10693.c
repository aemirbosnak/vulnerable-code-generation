//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int num_disks;
    int num_moves;
    int current_peg;
    int target_peg;
    int source_peg;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    printf("Enter the number of moves: ");
    scanf("%d", &num_moves);

    printf("Enter the current peg: ");
    scanf("%d", &current_peg);

    printf("Enter the target peg: ");
    scanf("%d", &target_peg);

    printf("Enter the source peg: ");
    scanf("%d", &source_peg);

    printf("Disks can only be moved one at a time.\n");
    printf("The largest disk must always remain on top of the stack.\n");
    printf("The source peg is the one with the disks.\n");
    printf("The target peg is the one where you want to move the disks.\n");
    printf("The current peg is the one where the largest disk is placed.\n");

    int hanoi[3][3] = {0};

    for (int i = 0; i < num_disks; i++) {
        hanoi[current_peg][source_peg] = i + 1;
    }

    for (int i = 0; i < num_moves; i++) {
        if (i % 2 == 0) {
            if (hanoi[current_peg][target_peg] == 0) {
                printf("Move disk %d from peg %d to peg %d.\n", hanoi[current_peg][source_peg], current_peg, target_peg);
            } else {
                printf("Move disk %d from peg %d to peg %d.\n", hanoi[current_peg][source_peg], current_peg, target_peg);
            }
        } else {
            if (hanoi[current_peg][target_peg] == 0) {
                printf("Move disk %d from peg %d to peg %d.\n", hanoi[current_peg][source_peg], current_peg, target_peg);
            } else {
                printf("Move disk %d from peg %d to peg %d.\n", hanoi[current_peg][source_peg], current_peg, target_peg);
            }
        }

        current_peg = target_peg;
        target_peg = source_peg;
        source_peg = current_peg;
    }

    return 0;
}