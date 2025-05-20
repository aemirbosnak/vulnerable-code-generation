//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int n, c;
    printf("Welcome to the Tower of Hanoi, Cyberpunk style!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");
    int towerOne[n], towerTwo[n], towerThree[n];
    int topOne = -1, topTwo = -1, topThree = -1;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        towerOne[i] = (rand() % (n+1-i)) + i;
    }
    int moves = (1 << n) - 1;
    int from = 1, to = 3, other = 2;
    if (n % 2 == 0) {
        to = 2;
        other = 3;
    }
    for (int i = n-1; i >= 0; i--) {
        topOne++;
        towerOne[topOne] = i;
    }
    int step = 0;
    while (step < moves) {
        step++;
        printf("Step %d:\n", step);
        sleep(1);
        if (step % 2 == 1) {
            if (towerOne[topOne] < towerThree[topThree]) {
                c = towerThree[topThree];
                topThree--;
                topOne++;
                towerOne[topOne] = c;
                printf("Move disk %d from Tower Three to Tower One\n", c);
            }
            else {
                c = towerOne[topOne];
                topOne--;
                topThree++;
                towerThree[topThree] = c;
                printf("Move disk %d from Tower One to Tower Three\n", c);
            }
        }
        else {
            if (towerOne[topOne] < towerTwo[topTwo]) {
                c = towerTwo[topTwo];
                topTwo--;
                topOne++;
                towerOne[topOne] = c;
                printf("Move disk %d from Tower Two to Tower One\n", c);
            }
            else if (towerTwo[topTwo] < towerThree[topThree]) {
                c = towerThree[topThree];
                topThree--;
                topTwo++;
                towerTwo[topTwo] = c;
                printf("Move disk %d from Tower Three to Tower Two\n", c);
            }
            else {
                c = towerOne[topOne];
                topOne--;
                topThree++;
                towerThree[topThree] = c;
                printf("Move disk %d from Tower One to Tower Three\n", c);
            }
        }
        if (topThree == n-1) {
            printf("\nCongratulations! You solved the Tower of Hanoi puzzle!\n");
            return 0;
        }
    }
    return 0;
}