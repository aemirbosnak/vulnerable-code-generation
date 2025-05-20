//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DISKS 10

void clear_console() {
    // Clear the terminal screen for better visualization
    printf("\033[H\033[J");
}

void print_puzzle(int num_disks, int from_peg, int to_peg, int aux_peg, int peg[MAX_DISKS][3]) {
    clear_console();  // Clear the console for each move visualization
    printf("Tower of Hanoi\n");
    printf("Move from peg %d to peg %d\n\n", from_peg + 1, to_peg + 1);
    
    for (int layer = num_disks - 1; layer >= 0; --layer) {
        for (int i = 0; i < 3; ++i) {
            if (peg[layer][i] > 0) {
                for (int space = 0; space < (MAX_DISKS - peg[layer][i]) * 2; space++) {
                    printf(" ");
                }
                for (int j = 0; j < peg[layer][i] * 2 - 1; j++) {
                    printf("#");
                }
                printf("    ");
            } else {
                for (int space = 0; space < MAX_DISKS * 2; space++) {
                    printf(" ");
                }
                printf("    ");
            }
        }
        printf("\n");
    }

    // Display the labels for the pegs
    printf("PEGS:\n");
    printf("1    2    3\n");
    usleep(1000000);  // Pause for 1 second for better visualization
}

void move_disk(int peg[MAX_DISKS][3], int from_peg, int to_peg) {
    int disk;
    // Move the disk from from_peg to to_peg
    for (disk = 0; disk < MAX_DISKS; ++disk) {
        if (peg[disk][from_peg] > 0) {
            peg[disk][from_peg]--;
            peg[disk][to_peg]++;
            break;
        }
    }
}

void tower_of_hanoi(int n, int from_peg, int to_peg, int aux_peg, int peg[MAX_DISKS][3]) {
    if (n == 1) {
        move_disk(peg, from_peg, to_peg);
        print_puzzle(n, from_peg, to_peg, aux_peg, peg);
        return;
    }
    tower_of_hanoi(n - 1, from_peg, aux_peg, to_peg, peg);
    move_disk(peg, from_peg, to_peg);
    print_puzzle(n, from_peg, to_peg, aux_peg, peg);
    tower_of_hanoi(n - 1, aux_peg, to_peg, from_peg, peg);
}

void initialize_peg(int peg[MAX_DISKS][3], int num_disks) {
    for (int i = 0; i < num_disks; i++) {
        peg[i][0] = i + 1;  // Fill the first peg with disks
        peg[i][1] = 0;      // second peg is empty
        peg[i][2] = 0;      // third peg is empty
    }
}

int main() {
    int num_disks;
    int peg[MAX_DISKS][3] = {0};

    printf("Enter the number of disks (1 - 10): ");
    scanf("%d", &num_disks);
    
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Please enter a valid number of disks between 1 and 10.\n");
        return 1;
    }

    initialize_peg(peg, num_disks);
    print_puzzle(num_disks, 0, 1, 2, peg);
    tower_of_hanoi(num_disks, 0, 2, 1, peg);

    return 0;
}