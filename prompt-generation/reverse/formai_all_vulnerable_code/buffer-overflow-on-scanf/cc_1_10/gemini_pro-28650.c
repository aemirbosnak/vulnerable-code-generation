//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct tower {
    int num_disks;
    int *disks;
} tower;

void move_disk(tower *from, tower *to) {
    to->disks[to->num_disks++] = from->disks[--from->num_disks];
}

void towers_of_hanoi(tower *from, tower *to, tower *aux, int num_disks) {
    if (num_disks == 1) {
        move_disk(from, to);
    } else {
        towers_of_hanoi(from, aux, to, num_disks - 1);
        move_disk(from, to);
        towers_of_hanoi(aux, to, from, num_disks - 1);
    }
}

int main() {
    tower from, to, aux;
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    from.num_disks = num_disks;
    to.num_disks = 0;
    aux.num_disks = 0;

    from.disks = (int *)malloc(num_disks * sizeof(int));
    to.disks = (int *)malloc(num_disks * sizeof(int));
    aux.disks = (int *)malloc(num_disks * sizeof(int));

    for (int i = 0; i < num_disks; i++) {
        from.disks[i] = num_disks - i;
    }

    towers_of_hanoi(&from, &to, &aux, num_disks);

    printf("The disks have been moved from the first tower to the third tower.\n");

    free(from.disks);
    free(to.disks);
    free(aux.disks);

    return 0;
}