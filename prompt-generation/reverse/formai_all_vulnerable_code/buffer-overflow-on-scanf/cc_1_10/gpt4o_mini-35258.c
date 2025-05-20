//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printTowers(int *towerA, int *towerB, int *towerC, int n) {
    int height = n;

    // The height of the tower including empty spaces
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (towerA[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("   ");
        for (int j = 0; j < n; j++) {
            if (towerB[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("   ");
        for (int j = 0; j < n; j++) {
            if (towerC[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("--A----B----C--\n");
}

void moveDisk(int *source, int *dest, int *srcHeight, int *destHeight, int n) {
    if (*srcHeight > 0) {
        source[*srcHeight - 1]--;
        dest[*destHeight] += 1;
        (*destHeight)++;
        (*srcHeight)--;
    }
}

void towerOfHanoi(int n, int *towerA, int *towerB, int *towerC, int heightA, int heightB, int heightC) {
    if (n == 1) {
        printf("Moving disk 1\n");
        printTowers(towerA, towerB, towerC, heightA);
        sleep(1); // adding delay for visual effect
        moveDisk(towerA, towerC, &heightA, &heightC, n);
        printTowers(towerA, towerB, towerC, heightA);
        return;
    }
    towerOfHanoi(n - 1, towerA, towerC, towerB, heightA, heightC, heightB);
    printf("Moving disk %d\n", n);
    printTowers(towerA, towerB, towerC, heightA);
    sleep(1);
    moveDisk(towerA, towerC, &heightA, &heightC, n);
    printTowers(towerA, towerB, towerC, heightA);
    towerOfHanoi(n - 1, towerB, towerA, towerC, heightB, heightA, heightC);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Towers initialized
    int towerA[n], towerB[n], towerC[n];
    for (int i = 0; i < n; i++) {
        towerA[i] = n - i; // fill tower A with disks
        towerB[i] = 0;
        towerC[i] = 0;
    }

    printf("\nInitial State:\n");
    printTowers(towerA, towerB, towerC, n);
    sleep(1);
    
    towerOfHanoi(n, towerA, towerB, towerC, n, 0, 0);
    
    printf("\nAll disks moved to Tower C successfully!\n");
    return 0;
}