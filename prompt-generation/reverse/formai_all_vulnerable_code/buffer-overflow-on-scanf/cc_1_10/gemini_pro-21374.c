//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MIN_TOWER_HEIGHT 3
#define MAX_TOWER_HEIGHT 10

typedef struct {
    int height;
    char *name;
} tower_t;

void print_towers(tower_t *towers, int num_towers) {
    for (int i = 0; i < num_towers; i++) {
        printf("Tower %s: ", towers[i].name);
        for (int j = 0; j < towers[i].height; j++) {
            printf("[]");
        }
        printf("\n");
    }
}

int main() {
    int num_towers;
    printf("Welcome to the Peaceful Tower of Hanoi! How many towers do you want to play with? (3-10): ");
    scanf("%d", &num_towers);

    if (num_towers < MIN_TOWER_HEIGHT || num_towers > MAX_TOWER_HEIGHT) {
        printf("Invalid number of towers. Please choose a number between %d and %d.\n", MIN_TOWER_HEIGHT, MAX_TOWER_HEIGHT);
        return 1;
    }

    tower_t *towers = malloc(sizeof(tower_t) * num_towers);
    for (int i = 0; i < num_towers; i++) {
        towers[i].height = 0;
        towers[i].name = malloc(sizeof(char) * 2);
        sprintf(towers[i].name, "%d", i + 1);
    }

    printf("Great! Here are the towers:\n");
    print_towers(towers, num_towers);

    int num_moves = 0;
    int src, dest;
    while (towers[num_towers - 1].height < MIN_TOWER_HEIGHT) {
        printf("Which tower do you want to move a disk from? (1-%d): ", num_towers);
        scanf("%d", &src);

        printf("Which tower do you want to move the disk to? (1-%d): ", num_towers);
        scanf("%d", &dest);

        if (towers[src - 1].height == 0) {
            printf("That tower is empty! Please choose a tower with at least one disk.\n");
        } else if (towers[dest - 1].height == towers[dest - 1].height) {
            printf("That tower is full! Please choose a tower with at least one empty spot.\n");
        } else if (towers[src - 1].height > towers[dest - 1].height) {
            printf("You can't move a larger disk onto a smaller disk! Please choose a valid move.\n");
        } else {
            towers[dest - 1].height++;
            towers[src - 1].height--;
            num_moves++;

            printf("Move %d: Moved a disk from tower %d to tower %d\n", num_moves, src, dest);
            print_towers(towers, num_towers);
        }
    }

    printf("Congratulations! You have solved the Peaceful Tower of Hanoi with %d moves!\n", num_moves);

    for (int i = 0; i < num_towers; i++) {
        free(towers[i].name);
    }
    free(towers);

    return 0;
}