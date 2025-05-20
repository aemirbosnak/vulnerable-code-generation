//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the towers
#define NUM_TOWERS 3
#define TOWER_A 0
#define TOWER_B 1
#define TOWER_C 2

// Define the disks
#define NUM_DISKS 9

// Define the colors of the disks
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"

// Define the reset color code
#define COLOR_RESET "\x1b[0m"

// Define the tower data structure
typedef struct {
    int num_disks;
    int disks[NUM_DISKS];
} tower_t;

// Define the function to move a disk from one tower to another
void move_disk(tower_t *tower_from, tower_t *tower_to) {
    // Check if the move is valid
    if (tower_from->num_disks == 0 || tower_to->num_disks == NUM_DISKS) {
        printf("Invalid move\n");
        return;
    }

    // Move the disk from the from tower to the to tower
    tower_to->disks[tower_to->num_disks++] = tower_from->disks[tower_from->num_disks--];
}

// Define the function to print the towers
void print_towers(tower_t towers[NUM_TOWERS]) {
    // Print the towers
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i);
        for (int j = 0; j < towers[i].num_disks; j++) {
            switch (towers[i].disks[j]) {
                case 1:
                    printf("%s%d%s ", COLOR_RED, towers[i].disks[j], COLOR_RESET);
                    break;
                case 2:
                    printf("%s%d%s ", COLOR_GREEN, towers[i].disks[j], COLOR_RESET);
                    break;
                case 3:
                    printf("%s%d%s ", COLOR_YELLOW, towers[i].disks[j], COLOR_RESET);
                    break;
                case 4:
                    printf("%s%d%s ", COLOR_BLUE, towers[i].disks[j], COLOR_RESET);
                    break;
                case 5:
                    printf("%s%d%s ", COLOR_MAGENTA, towers[i].disks[j], COLOR_RESET);
                    break;
                case 6:
                    printf("%s%d%s ", COLOR_CYAN, towers[i].disks[j], COLOR_RESET);
                    break;
                case 7:
                    printf("%s%d%s ", COLOR_WHITE, towers[i].disks[j], COLOR_RESET);
                    break;
            }
        }
        printf("\n");
    }
}

// Define the function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(tower_t towers[NUM_TOWERS], int num_disks) {
    // Check if the number of disks is valid
    if (num_disks < 1 || num_disks > NUM_DISKS) {
        printf("Invalid number of disks\n");
        return;
    }

    // Initialize the towers
    for (int i = 0; i < NUM_TOWERS; i++) {
        towers[i].num_disks = 0;
    }

    // Place the disks on the first tower
    for (int i = num_disks; i > 0; i--) {
        towers[TOWER_A].disks[towers[TOWER_A].num_disks++] = i;
    }

    // Print the initial state of the towers
    print_towers(towers);

    // Solve the Tower of Hanoi problem
    for (int i = 1; i <= num_disks; i++) {
        // Move the disk from the first tower to the second tower
        move_disk(&towers[TOWER_A], &towers[TOWER_B]);

        // Print the current state of the towers
        print_towers(towers);

        // Move the disk from the second tower to the third tower
        move_disk(&towers[TOWER_B], &towers[TOWER_C]);

        // Print the current state of the towers
        print_towers(towers);

        // Move the disk from the first tower to the second tower
        move_disk(&towers[TOWER_A], &towers[TOWER_B]);

        // Print the current state of the towers
        print_towers(towers);
    }
}

// Define the main function
int main(void) {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the towers
    tower_t towers[NUM_TOWERS];

    // Get the number of disks from the user
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // Solve the Tower of Hanoi problem
    solve_tower_of_hanoi(towers, num_disks);

    return 0;
}