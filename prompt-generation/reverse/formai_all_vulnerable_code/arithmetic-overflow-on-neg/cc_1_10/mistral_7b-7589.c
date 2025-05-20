//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DISKS 6
#define SOURCE 1
#define DESTINATION 3
#define AUXILIARY 2

typedef struct {
    int number;
    char name[10];
} Disk;

void print_tower(int tower[], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (tower[i] > 0)
            printf(" %s%d%s\n", "\x1b[31m", tower[i], "\x1b[0m");
        else
            printf("   \x1b[31m%s%d%s\n", "\x1b[31m", -tower[i], "\x1b[0m");
    }
}

void hanoi(int n, int source, int auxiliary, int destination) {
    if (n > 0) {
        hanoi(n - 1, source, destination, auxiliary);
        int disk = source;
        printf("\n\x1b[1;32m >>>>\x1b[0m %s%d%s \x1b[1;32mfrom %s%d%s \x1b[1;32mto %s%d%s.\n\n",
            "\x1b[31m", source, "\x1b[0m", "\x1b[31m", source, "\x1b[0m", "\x1b[31m", destination, "\x1b[0m");
        hanoi(n - 1, auxiliary, source, destination);
    }
}

int main() {
    srand(time(NULL));
    Disk towers[DISKS + 3];
    int i;

    memset(towers, 0, sizeof(Disk) * (DISKS + 3));

    printf("\x1b[1;1H\x1b[2J");
    towers[SOURCE].number = DISKS;
    strcpy(towers[SOURCE].name, "Source");

    towers[DESTINATION].number = -DISKS;
    strcpy(towers[DESTINATION].name, "Destination");

    towers[AUXILIARY].number = 0;
    strcpy(towers[AUXILIARY].name, "Auxiliary");

    print_tower(towers[SOURCE].number > 0 ? towers[SOURCE].number : -towers[SOURCE].number, DISKS);

    hanoi(DISKS, SOURCE, AUXILIARY, DESTINATION);

    print_tower(towers[DESTINATION].number > 0 ? towers[DESTINATION].number : -towers[DESTINATION].number, DISKS);

    return 0;
}