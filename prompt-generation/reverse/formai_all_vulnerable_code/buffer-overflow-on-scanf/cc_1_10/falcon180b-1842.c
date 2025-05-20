//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROBOT_NUM 10
#define MAX_ROBOT_SPEED 10
#define MAX_ROBOT_POS 100
#define RANDOM_SEED (unsigned int)time(NULL)

// Robot structure
typedef struct {
    int id;
    int pos;
    int speed;
} Robot;

// Function prototypes
void init_robot(Robot *robot, int id);
void move_robot(Robot *robot);
void print_robot_state(Robot *robot);

int main() {
    srand(RANDOM_SEED);

    int num_robots;
    printf("Enter the number of robots: ");
    scanf("%d", &num_robots);

    Robot robots[MAX_ROBOT_NUM];

    for (int i = 0; i < num_robots; i++) {
        int id = i + 1;
        init_robot(&robots[i], id);
    }

    while (1) {
        for (int i = 0; i < num_robots; i++) {
            move_robot(&robots[i]);
        }

        printf("\n");
        for (int i = 0; i < num_robots; i++) {
            print_robot_state(&robots[i]);
        }

        usleep(500000); // Sleep for 0.5 second
    }

    return 0;
}

void init_robot(Robot *robot, int id) {
    robot->id = id;
    robot->pos = 0;
    robot->speed = rand() % MAX_ROBOT_SPEED + 1;
}

void move_robot(Robot *robot) {
    if (robot->pos >= MAX_ROBOT_POS) {
        robot->pos = 0;
    } else if (robot->pos <= 0) {
        robot->pos = MAX_ROBOT_POS;
    } else {
        robot->pos += robot->speed;
    }
}

void print_robot_state(Robot *robot) {
    printf("Robot %d is at position %d\n", robot->id, robot->pos);
}