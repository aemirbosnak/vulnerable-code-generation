//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

typedef struct {
    int num_disks;
    int disk_sizes[MAX_DISKS];
} tower_of_hanoi_t;

void init_tower_of_hanoi(tower_of_hanoi_t *tower, int num_disks) {
    tower->num_disks = num_disks;
    for (int i = 0; i < num_disks; i++) {
        tower->disk_sizes[i] = num_disks - i;
    }
}

void print_tower_of_hanoi(tower_of_hanoi_t *tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->disk_sizes[i]);
    }
    printf("\n");
}

void move_disk(tower_of_hanoi_t *from_tower, tower_of_hanoi_t *to_tower) {
    int from_disk_size = from_tower->disk_sizes[from_tower->num_disks - 1];
    int to_disk_size = to_tower->disk_sizes[to_tower->num_disks - 1];
    if (from_disk_size > to_disk_size) {
        printf("Error: cannot move disk from smaller to larger disk.\n");
        return;
    }
    from_tower->num_disks--;
    to_tower->num_disks++;
    to_tower->disk_sizes[to_tower->num_disks - 1] = from_disk_size;
}

void solve_tower_of_hanoi(tower_of_hanoi_t *from_tower, tower_of_hanoi_t *to_tower, tower_of_hanoi_t *aux_tower, int num_disks) {
    if (num_disks == 1) {
        move_disk(from_tower, to_tower);
        return;
    }
    solve_tower_of_hanoi(from_tower, aux_tower, to_tower, num_disks - 1);
    move_disk(from_tower, to_tower);
    solve_tower_of_hanoi(aux_tower, to_tower, from_tower, num_disks - 1);
}

int main() {
    tower_of_hanoi_t tower1, tower2, tower3;
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    init_tower_of_hanoi(&tower1, num_disks);
    init_tower_of_hanoi(&tower2, 0);
    init_tower_of_hanoi(&tower3, 0);
    printf("Initial state of the tower of Hanoi:\n");
    print_tower_of_hanoi(&tower1);
    print_tower_of_hanoi(&tower2);
    print_tower_of_hanoi(&tower3);
    solve_tower_of_hanoi(&tower1, &tower3, &tower2, num_disks);
    printf("Final state of the tower of Hanoi:\n");
    print_tower_of_hanoi(&tower1);
    print_tower_of_hanoi(&tower2);
    print_tower_of_hanoi(&tower3);
    return 0;
}