//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printTower(int n, char source, char dest, char aux) {
    printf("Current state:\n");
    for (int i = n; i > 0; i--) {
        printf("Disk %d: ", i);
        if (i % 3 == 0) {
            printf("%c\n", source);
        } else if (i % 3 == 1) {
            printf("%c\n", dest);
        } else {
            printf("%c\n", aux);
        }
    }
    printf("\n");
}

/* Function to move the disks */
void towerOfHanoi(int n, char source, char dest, char aux) {
    if (n == 0) return;

    towerOfHanoi(n - 1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    // Simulate the shifting state with a delay and custom print
    printTower(n, source, dest, aux);
    sleep(1); // Pause to visualize the move
    towerOfHanoi(n - 1, aux, dest, source);
}

int main() {
    int n;

    while (1) {
        printf("Enter the number of disks (1 to 10): ");
        scanf("%d", &n);

        if (n < 1 || n > 10) {
            printf("Please enter a valid number of disks between 1 and 10.\n");
            continue;
        }

        printf("Solving Tower of Hanoi for %d disks:\n", n);
        // Start the recursive process
        towerOfHanoi(n, 'A', 'C', 'B'); // A -> source, C -> destination, B -> auxiliary
        break;
    }

    printf("All disks moved successfully!\n");
    return 0;
}