//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX_DISKS 50

typedef struct {
    int num_disks;
    char **towers;
    int *num_disks_on_tower;
} Hanoi;

Hanoi *hanoi_init(int num_disks) {
    Hanoi *hanoi = malloc(sizeof(Hanoi));
    hanoi->num_disks = num_disks;
    hanoi->towers = malloc(sizeof(char *) * 3);
    hanoi->towers[0] = malloc(sizeof(char) * (num_disks + 1));
    hanoi->towers[1] = malloc(sizeof(char) * (num_disks + 1));
    hanoi->towers[2] = malloc(sizeof(char) * (num_disks + 1));
    hanoi->num_disks_on_tower = malloc(sizeof(int) * 3);
    hanoi->num_disks_on_tower[0] = num_disks;
    hanoi->num_disks_on_tower[1] = 0;
    hanoi->num_disks_on_tower[2] = 0;
    for (int i = 0; i < num_disks; i++) {
        hanoi->towers[0][i] = 'A' + num_disks - i - 1;
    }
    hanoi->towers[0][num_disks] = '\0';
    hanoi->towers[1][0] = '\0';
    hanoi->towers[2][0] = '\0';
    return hanoi;
}

void hanoi_print(Hanoi *hanoi) {
    printf("Tower 1: %s\n", hanoi->towers[0]);
    printf("Tower 2: %s\n", hanoi->towers[1]);
    printf("Tower 3: %s\n", hanoi->towers[2]);
}

void hanoi_solve(Hanoi *hanoi, int n, int from, int to, int via) {
    if (n == 1) {
        hanoi->towers[to][hanoi->num_disks_on_tower[to]++] = hanoi->towers[from][hanoi->num_disks_on_tower[from]-- - 1];
    } else {
        hanoi_solve(hanoi, n - 1, from, via, to);
        hanoi->towers[to][hanoi->num_disks_on_tower[to]++] = hanoi->towers[from][hanoi->num_disks_on_tower[from]-- - 1];
        hanoi_solve(hanoi, n - 1, via, to, from);
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    Hanoi *hanoi = hanoi_init(num_disks);
    hanoi_print(hanoi);
    hanoi_solve(hanoi, num_disks, 0, 2, 1);
    hanoi_print(hanoi);
    return 0;
}