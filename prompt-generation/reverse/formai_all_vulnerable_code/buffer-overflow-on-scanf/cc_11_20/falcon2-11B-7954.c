//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num_disks, i;
    int src, dest, temp;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks <= 1) {
        printf("No disks to move.\n");
        return 0;
    }
    src = 0;
    dest = 1;
    temp = -1;
    printf("Tower of Hanoi problem\n");
    printf("Source: %d\n", src);
    printf("Destination: %d\n", dest);
    printf("Temporary: %d\n", temp);
    printf("Number of disks: %d\n", num_disks);
    printf("Move the disk from source to destination:\n");
    for (i = num_disks; i > 0; i--) {
        printf("%d\n", i);
        if (i > 1) {
            printf("Move %d from %d to %d\n", i, src, dest);
            temp = src;
            src = dest;
            dest = temp;
        }
        if (i == 1) {
            printf("Move %d from %d to %d\n", i, src, dest);
            temp = src;
            src = dest;
            dest = temp;
        }
    }
    printf("Move the disk from destination to temporary:\n");
    for (i = 1; i <= num_disks; i++) {
        printf("%d\n", i);
        if (i > 1) {
            printf("Move %d from %d to %d\n", i, dest, temp);
            temp = dest;
            dest = src;
            src = temp;
        }
        if (i == 1) {
            printf("Move %d from %d to %d\n", i, dest, temp);
            temp = dest;
            dest = src;
            src = temp;
        }
    }
    printf("Move the disk from temporary to source:\n");
    for (i = 1; i <= num_disks; i++) {
        printf("%d\n", i);
        if (i > 1) {
            printf("Move %d from %d to %d\n", i, temp, src);
            temp = src;
            src = dest;
            dest = temp;
        }
        if (i == 1) {
            printf("Move %d from %d to %d\n", i, temp, src);
            temp = src;
            src = dest;
            dest = temp;
        }
    }
    return 0;
}