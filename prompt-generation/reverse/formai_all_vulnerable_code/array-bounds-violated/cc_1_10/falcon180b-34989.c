//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MOVE(x) x = (x + 1) % 3
#define DISPLAY(x) printf("\n\n%s\n", x)

int main() {
    int n, i, j, k, l, count = 0;
    char from, to;
    struct timespec start, end;
    double elapsed;

    printf("\nEnter the number of disks: ");
    scanf("%d", &n);

    int stack[MAX][3];
    for (i = 0; i < n; i++) {
        stack[i][0] = i;
        stack[i][1] = 0;
        stack[i][2] = 2;
    }

    printf("\nInitial configuration:\n");
    for (i = 0; i < n; i++) {
        printf("Disk %d is at peg %d\n", i+1, stack[i][1]+1);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    for (i = n-1; i >= 0; i--) {
        for (j = 0; j < 3; j++) {
            if (stack[i][j] == 0) {
                MOVE(j);
                count++;
            }
        }
        for (j = 0; j < 3; j++) {
            if (stack[i][j]!= 0) {
                from = j + 'A';
                to = (j + 1) % 3 + 'A';
                printf("%c -> %c\n", from, to);
                stack[i][j] = stack[i][MOVE(j)];
            }
        }
    }

    clock_gettime(CLOCK_REALTIME, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("\n\nTower of Hanoi problem solved in %.6f seconds.\n", elapsed);
    printf("Number of moves: %d\n", count);

    return 0;
}