//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Map size
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Player and goal coordinates
int player_x = 0, player_y = 0;
int goal_x, goal_y;

// Map
char map[MAP_HEIGHT][MAP_WIDTH];

// Function to generate a random goal
void generate_goal() {
    goal_x = rand() % MAP_WIDTH;
    goal_y = rand() % MAP_HEIGHT;
}

// Function to print the map
void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == player_y && j == player_x) {
                printf("@ ");
            } else if (i == goal_y && j == goal_x) {
                printf("G ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to get player input
void get_input() {
    char input;
    scanf(" %c", &input);

    switch (input) {
    case 'w':
        player_y--;
        break;
    case 's':
        player_y++;
        break;
    case 'a':
        player_x--;
        break;
    case 'd':
        player_x++;
        break;
    }
}

// Function to check if the player has reached the goal
int check_goal() {
    return player_x == goal_x && player_y == goal_y;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the goal
    generate_goal();

    // Print the initial map
    print_map();

    // Game loop
    while (!check_goal()) {
        // Get player input
        get_input();

        // Check if the player has moved out of the map
        if (player_x < 0 || player_x >= MAP_WIDTH || player_y < 0 || player_y >= MAP_HEIGHT) {
            printf("You can't move out of the map!\n");
            continue;
        }

        // Print the updated map
        print_map();
    }

    // The player has reached the goal
    printf("Congratulations! You reached the goal!\n");

    return 0;
}