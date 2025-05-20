//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: inquisitive
/*
 * Robotisimo - A whimsical journey into the realm of robot control
 */

#include <stdio.h>
#include <stdlib.h>

// Our intrepid robot, poised for adventure
typedef struct {
    int x;
    int y;
    int direction; // 0: North, 1: East, 2: South, 3: West
} Robot;

// The wondrous world our robot navigates, filled with obstacles and rewards
typedef struct {
    int width;
    int height;
    int** grid; // 0: Empty, 1: Obstacle, 2: Reward
} World;

// Initializes our robot in the center of the world, facing north
Robot* create_robot(World* world) {
    Robot* robot = malloc(sizeof(Robot));
    robot->x = world->width / 2;
    robot->y = world->height / 2;
    robot->direction = 0;
    return robot;
}

// Creates a world with width 'w' and height 'h'
World* create_world(int w, int h) {
    World* world = malloc(sizeof(World));
    world->width = w;
    world->height = h;
    world->grid = malloc(sizeof(int*) * h);
    for (int i = 0; i < h; i++) {
        world->grid[i] = malloc(sizeof(int) * w);
        for (int j = 0; j < w; j++) {
            world->grid[i][j] = 0;
        }
    }
    return world;
}

// Utility function to print the world
void print_world(World* world) {
    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            switch (world->grid[i][j]) {
                case 0:
                    printf("□");
                    break;
                case 1:
                    printf("■");
                    break;
                case 2:
                    printf("☆");
                    break;
            }
        }
        printf("\n");
    }
}

// Moves the robot forward one step in the current direction
void move_forward(Robot* robot, World* world) {
    switch (robot->direction) {
        case 0: // North
            if (robot->y > 0 && world->grid[robot->y - 1][robot->x] != 1) {
                robot->y--;
            }
            break;
        case 1: // East
            if (robot->x < world->width - 1 && world->grid[robot->y][robot->x + 1] != 1) {
                robot->x++;
            }
            break;
        case 2: // South
            if (robot->y < world->height - 1 && world->grid[robot->y + 1][robot->x] != 1) {
                robot->y++;
            }
            break;
        case 3: // West
            if (robot->x > 0 && world->grid[robot->y][robot->x - 1] != 1) {
                robot->x--;
            }
            break;
    }
}

// Turns the robot left (counterclockwise)
void turn_left(Robot* robot) {
    robot->direction = (robot->direction + 3) % 4;
}

// Turns the robot right (clockwise)
void turn_right(Robot* robot) {
    robot->direction = (robot->direction + 1) % 4;
}

// Main function - where the adventure begins
int main() {
    // Let's create a small world for our robot to explore
    printf("Welcome to Robotisimo! Let's define our world:\n");
    int world_width, world_height;
    printf("Enter the width of the world: ");
    scanf("%d", &world_width);
    printf("Enter the height of the world: ");
    scanf("%d", &world_height);
    World* world = create_world(world_width, world_height);

    // Now, let's position some obstacles and rewards
    printf("\nLet's add some obstacles and rewards to the world:\n");
    int num_obstacles, num_rewards;
    printf("Enter the number of obstacles: ");
    scanf("%d", &num_obstacles);
    for (int i = 0; i < num_obstacles; i++) {
        int x, y;
        printf("Enter the x-coordinate of obstacle %d: ", i + 1);
        scanf("%d", &x);
        printf("Enter the y-coordinate of obstacle %d: ", i + 1);
        scanf("%d", &y);
        world->grid[y][x] = 1;
    }
    printf("Enter the number of rewards: ");
    scanf("%d", &num_rewards);
    for (int i = 0; i < num_rewards; i++) {
        int x, y;
        printf("Enter the x-coordinate of reward %d: ", i + 1);
        scanf("%d", &x);
        printf("Enter the y-coordinate of reward %d: ", i + 1);
        scanf("%d", &y);
        world->grid[y][x] = 2;
    }

    // Time to introduce our intrepid robot!
    printf("\nMeet our robot! Let's set its starting position:\n");
    Robot* robot = create_robot(world);
    int start_x, start_y;
    printf("Enter the x-coordinate of the robot's starting position: ");
    scanf("%d", &start_x);
    printf("Enter the y-coordinate of the robot's starting position: ");
    scanf("%d", &start_y);
    robot->x = start_x;
    robot->y = start_y;

    // Let's see our world and the robot's starting position
    printf("\nBehold, the world and the robot's starting position:\n");
    print_world(world);
    printf("Robot is at (%d, %d)\n\n", robot->x, robot->y);

    // Now, let's control the robot!
    printf("Enter a sequence of commands (F for forward, L for left, R for right, Q to quit): ");
    char command;
    while ((command = getchar()) != 'Q') {
        switch (command) {
            case 'F':
                move_forward(robot, world);
                break;
            case 'L':
                turn_left(robot);
                break;
            case 'R':
                turn_right(robot);
                break;
            default:
                printf("Invalid command. Please enter F, L, R, or Q.\n");
                break;
        }
        printf("Robot is now at (%d, %d)\n", robot->x, robot->y);
        print_world(world);
    }

    // Farewell message
    printf("\nThank you for playing Robotisimo! Until next time!\n");

    // Cleanup
    for (int i = 0; i < world->height; i++) {
        free(world->grid[i]);
    }
    free(world->grid);
    free(world);
    free(robot);

    return 0;
}