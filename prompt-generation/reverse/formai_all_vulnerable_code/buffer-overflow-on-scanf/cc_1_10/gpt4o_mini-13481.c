//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

// Enum directions for ease of use
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    INVALID
} Direction;

// Robot structure
typedef struct {
    int x;
    int y;
} Robot;

// Function prototypes
void display_grid(Robot bot);
Direction get_direction();
void move_robot(Robot* bot, Direction direction);
void happy_movement(Robot* bot);

int main() {
    Robot bot = {0, 0}; // Start position at the top-left corner
    printf("🎉 Welcome to the Happy Robot Movement Simulator! 🎉\n");

    while (1) {
        display_grid(bot);
        Direction direction = get_direction();
        
        if (direction == QUIT) {
            printf("🚀 Bye! Thanks for playing with the Happy Robot! 🚀\n");
            break;
        } else if (direction == INVALID) {
            printf("❌ Oops! Please enter a valid direction! ❌\n");
            continue;
        }
        
        move_robot(&bot, direction);
        happy_movement(&bot);
    }
    return 0;
}

// Display the current state of the grid and the robot's position
void display_grid(Robot bot) {
    printf("\n🐾 Current Position: [%d, %d]\n\n", bot.x, bot.y);
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == bot.x && j == bot.y) {
                printf("🤖 "); // Robot position
            } else {
                printf("⬜ "); // Empty space
            }
        }
        printf("\n");
    }
}

// Get the user's direction input
Direction get_direction() {
    char input[10];
    printf("🚦 Enter direction (up, down, left, right) or 'quit' to exit: ");
    scanf("%s", input);
    
    if (strcmp(input, "up") == 0) return UP;
    if (strcmp(input, "down") == 0) return DOWN;
    if (strcmp(input, "left") == 0) return LEFT;
    if (strcmp(input, "right") == 0) return RIGHT;
    if (strcmp(input, "quit") == 0) return QUIT;
    
    return INVALID;
}

// Move the robot based on chosen direction
void move_robot(Robot* bot, Direction direction) {
    switch (direction) {
        case UP:
            if (bot->x > 0) bot->x--;
            break;
        case DOWN:
            if (bot->x < GRID_SIZE - 1) bot->x++;
            break;
        case LEFT:
            if (bot->y > 0) bot->y--;
            break;
        case RIGHT:
            if (bot->y < GRID_SIZE - 1) bot->y++;
            break;
        default:
            break;
    }
}

// Display happy movement feedback
void happy_movement(Robot* bot) {
    printf("✨ The robot happily moves to [%d, %d]! ✨\n", bot->x, bot->y);
    if (bot->x == 0 && bot->y == 0) {
        printf("🎈 The robot is in the corner, feeling great! 🎈\n");
    } else if (bot->x == GRID_SIZE - 1 && bot->y == GRID_SIZE - 1) {
        printf("🌟 The robot reaches the far corner! What an adventure! 🌟\n");
    } else {
        printf("🌈 Keep guiding the happy robot on its journey! 🌈\n");
    }
}