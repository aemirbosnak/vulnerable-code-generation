//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of disks
#define MAX_DISKS 10

// Define the three towers
#define TOWER_A 1
#define TOWER_B 2
#define TOWER_C 3

// Define the state of the game
#define GAME_IN_PROGRESS 1
#define GAME_OVER 2

// Define the structure for a disk
typedef struct disk {
    int size;
} Disk;

// Define the state of the game as a global variable
int game_state = GAME_IN_PROGRESS;

// Define the number of disks as a global variable
int num_disks;

// Define the three towers as arrays of disks
Disk tower_a[MAX_DISKS];
Disk tower_b[MAX_DISKS];
Disk tower_c[MAX_DISKS];

// Define variables to track the top of each tower
int top_a = -1;
int top_b = -1;
int top_c = -1;

// Define a function to print the state of the game
void print_game_state() {
    printf("=======================\n");
    printf("Tower of Hanoi\n\n");
    printf("Tower A: ");
    for (int i = top_a; i >= 0; i--) {
        printf("%d ", tower_a[i].size);
    }
    printf("\n");
    printf("Tower B: ");
    for (int i = top_b; i >= 0; i--) {
        printf("%d ", tower_b[i].size);
    }
    printf("\n");
    printf("Tower C: ");
    for (int i = top_c; i >= 0; i--) {
        printf("%d ", tower_c[i].size);
    }
    printf("\n");
}

// Define a function to initialize the game
void init_game(int disks) {
    // Set the number of disks
    num_disks = disks;
    
    // Initialize the towers
    for (int i = 0; i < num_disks; i++) {
        tower_a[i].size = i + 1;
        top_a++;
    }
}

// Define a function to randomly move a disk
void move_random_disk() {
    // Generate a random number from 1 to 3 to select a tower to move from
    int from_tower = (rand() % 3) + 1;
    
    // Generate a random number from 1 to 3 to select a tower to move to
    int to_tower = (rand() % 3) + 1;
    
    // Make sure the towers are different
    while (to_tower == from_tower) {
        to_tower = (rand() % 3) + 1;
    }
    
    // Select the top disk from the from_tower
    Disk disk;
    switch (from_tower) {
        case TOWER_A:
            if (top_a == -1) {
                return;
            }
            disk = tower_a[top_a];
            top_a--;
            break;
        case TOWER_B:
            if (top_b == -1) {
                return;
            }
            disk = tower_b[top_b];
            top_b--;
            break;
        case TOWER_C:
            if (top_c == -1) {
                return;
            }
            disk = tower_c[top_c];
            top_c--;
            break;
    }
    
    // Move the disk to the to_tower
    switch (to_tower) {
        case TOWER_A:
            if (top_a < num_disks - 1) {
                top_a++;
                tower_a[top_a] = disk;
            }
            break;
        case TOWER_B:
            if (top_b < num_disks - 1) {
                top_b++;
                tower_b[top_b] = disk;
            }
            break;
        case TOWER_C:
            if (top_c < num_disks - 1) {
                top_c++;
                tower_c[top_c] = disk;
            }
            break;
    }
}

// Define a function to check if the game is over
void check_game_state() {
    if (top_c == num_disks - 1) {
        game_state = GAME_OVER;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Get the number of disks from the user
    int disks;
    printf("Enter the number of disks (max %d): ", MAX_DISKS);
    scanf("%d", &disks);
    while (disks < 1 || disks > MAX_DISKS) {
        printf("Invalid number of disks. Enter a number between 1 and %d: ", MAX_DISKS);
        scanf("%d", &disks);
    }
    
    // Initialize the game
    init_game(disks);
    
    // Print the initial state of the game
    print_game_state();
    
    // Loop until the game is over
    while (game_state == GAME_IN_PROGRESS) {
        // Move a random disk
        move_random_disk();
        
        // Check if the game is over
        check_game_state();
        
        // Print the state of the game
        print_game_state();
    }
    
    // Print the game over message
    printf("Congratulations! You won!\n");
    
    return 0;
}