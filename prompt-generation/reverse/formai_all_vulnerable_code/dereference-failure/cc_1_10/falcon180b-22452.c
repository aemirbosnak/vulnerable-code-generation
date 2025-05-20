//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int **tower;
} tower_t;

void init_tower(tower_t *tower, int size) {
    tower->size = size;
    tower->tower = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        tower->tower[i] = (int *)malloc(size * sizeof(int));
    }
}

void destroy_tower(tower_t *tower) {
    for (int i = 0; i < tower->size; i++) {
        free(tower->tower[i]);
    }
    free(tower->tower);
}

void print_tower(tower_t *tower) {
    for (int i = 0; i < tower->size; i++) {
        for (int j = 0; j < tower->size; j++) {
            printf("%d ", tower->tower[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the number of disks: ");
    scanf("%d", &size);

    tower_t tower;
    init_tower(&tower, size);

    int from_rod = 0;
    int to_rod = size - 1;
    int temp_rod = size - 1;

    printf("Initial tower:\n");
    print_tower(&tower);

    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("Move disk %d from rod %d to rod %d\n", i, from_rod, to_rod);
            tower.tower[to_rod][j] = i;
            printf("Current tower:\n");
            print_tower(&tower);
            from_rod++;
            to_rod--;
            temp_rod = (to_rod + from_rod) / 2;
        }
    }

    destroy_tower(&tower);

    return 0;
}