//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int disks[n];
    for (int i = 0; i < n; i++) {
        disks[i] = i + 1;
    }

    int source, destination, auxiliary;

    printf("Source Tower: ");
    scanf("%d", &source);
    printf("Destination Tower: ");
    scanf("%d", &destination);
    printf("Auxiliary Tower: ");
    scanf("%d", &auxiliary);

    int moves = 0;

    while (n > 0) {
        if (n == 1) {
            printf("Move disk %d from source tower %d to destination tower %d.\n", disks[0], source, destination);
            n--;
            break;
        }

        if (n == 2) {
            printf("Move disk %d from source tower %d to auxiliary tower %d.\n", disks[0], source, auxiliary);
            n--;
            printf("Move disk %d from auxiliary tower %d to destination tower %d.\n", disks[1], auxiliary, destination);
            n--;
            break;
        }

        printf("Move disk %d from source tower %d to auxiliary tower %d.\n", disks[n-1], source, auxiliary);
        n--;

        printf("Move disk %d from source tower %d to destination tower %d.\n", disks[0], source, destination);
        n--;

        printf("Move disk %d from auxiliary tower %d to destination tower %d.\n", disks[n-1], auxiliary, destination);
        n--;

        moves++;
    }

    printf("Total moves: %d\n", moves);
    return 0;
}