//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DISK_COUNT 3
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct { int num, pos; } Disk;

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c.\n", from_rod, to_rod);
        return;
    }

    hanoi(n - 1, from_rod, aux_rod, to_rod);
    hanoi(1, from_rod, to_rod, aux_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

void setup(Disk *disks) {
    for (int i = 0; i < DISK_COUNT; ++i) {
        disks[i].num = i + 1;
        disks[i].pos = i;
    }
}

void print_state(Disk *disks) {
    printf("Current state:\n");
    for (int i = 0; i < DISK_COUNT; ++i)
        printf("Disk %d on rod %d\n", disks[i].num, disks[i].pos + 'A' - 1);
}

void move_disk(Disk *disks, int from, int to) {
    int temp = disks[from].pos;
    disks[from].pos = disks[to].pos;
    disks[to].pos = temp;
}

void hanoi_solver(char *input_file) {
    int n;
    char from, to, aux;

    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %c %c %c", &n, &from, &to, &aux);

    Disk disks[DISK_COUNT];
    setup(disks);

    hanoi(n, from - 'A', to - 'A', aux - 'A');
    print_state(disks);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hanoi_solver(argv[1]);
    return EXIT_SUCCESS;
}