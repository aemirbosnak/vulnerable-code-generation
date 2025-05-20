//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOWERS 10
#define MAX_DISCS 10

typedef struct tower {
    char name;
    int num_discs;
    int discs[MAX_DISCS];
} tower;

void print_towers(tower towers[], int num_towers) {
    for (int i = 0; i < num_towers; i++) {
        printf("Tower %c: ", towers[i].name);
        for (int j = 0; j < towers[i].num_discs; j++) {
            printf("%d ", towers[i].discs[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_disc(tower *from, tower *to) {
    if (from->num_discs == 0 || to->num_discs == MAX_DISCS) {
        return;
    }

    int disc = from->discs[from->num_discs - 1];
    from->num_discs--;
    to->discs[to->num_discs++] = disc;
}

void solve_tower_of_hanoi(tower *towers, int num_towers, int num_discs) {
    if (num_discs == 1) {
        move_disc(towers, towers + 1);
        return;
    }

    solve_tower_of_hanoi(towers, num_towers - 1, num_discs - 1);
    move_disc(towers, towers + num_towers - 1);
    solve_tower_of_hanoi(towers + 1, num_towers - 1, num_discs - 1);
}

int main() {
    int num_towers, num_discs;

    printf("Enter the number of towers: ");
    scanf("%d", &num_towers);

    printf("Enter the number of discs: ");
    scanf("%d", &num_discs);

    if (num_towers < 3 || num_towers > MAX_TOWERS || num_discs < 1 || num_discs > MAX_DISCS) {
        printf("Invalid input!\n");
        return 1;
    }

    tower towers[MAX_TOWERS];

    for (int i = 0; i < num_towers; i++) {
        towers[i].name = 'A' + i;
        towers[i].num_discs = 0;
    }

    for (int i = num_discs; i >= 1; i--) {
        towers[0].discs[towers[0].num_discs++] = i;
    }

    print_towers(towers, num_towers);

    solve_tower_of_hanoi(towers, num_towers, num_discs);

    print_towers(towers, num_towers);

    return 0;
}