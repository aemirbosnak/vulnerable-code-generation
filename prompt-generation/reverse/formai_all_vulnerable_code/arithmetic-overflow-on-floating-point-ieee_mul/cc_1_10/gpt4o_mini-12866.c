//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_MOVEMENTS 100

typedef struct {
    double x;
    double y;
} Position;

typedef struct {
    Position path[MAX_MOVEMENTS];
    int step_count;
} Robot;

void initialize_robot(Robot *robot) {
    robot->step_count = 0;
    robot->path[0].x = 0.0;
    robot->path[0].y = 0.0;
    printf("Robot initialized at position (0.0, 0.0).\n");
}

void move_robot(Robot *robot, double angle, double distance) {
    if (robot->step_count >= MAX_MOVEMENTS - 1) {
        printf("Movement limit reached. Cannot move further.\n");
        return;
    }
    
    double radian_angle = angle * (M_PI / 180.0);
    robot->step_count++;
    robot->path[robot->step_count].x = robot->path[robot->step_count - 1].x + distance * cos(radian_angle);
    robot->path[robot->step_count].y = robot->path[robot->step_count - 1].y + distance * sin(radian_angle);
    
    printf("Moved to position (%.2f, %.2f) at step %d with angle %.2f degrees.\n", 
           robot->path[robot->step_count].x, robot->path[robot->step_count].y, robot->step_count, angle);
}

void print_path(Robot *robot) {
    printf("Path of the robot:\n");
    for (int i = 0; i <= robot->step_count; i++) {
        printf("Step %d: (%.2f, %.2f)\n", i, robot->path[i].x, robot->path[i].y);
    }
}

double calculate_distance(Position from, Position to) {
    return sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
}

void execute_commands(Robot *robot, const char *commands) {
    char command;
    double angle, distance;

    const char *pos = commands;
    while (*pos) {
        command = *pos++;
        switch(command) {
            case 'M': // Move command
                sscanf(pos, "%lf,%lf", &angle, &distance);
                move_robot(robot, angle, distance);
                while (*pos != ' ' && *pos != '\0') pos++; // Move pointer to next command
                while (*pos == ' ') pos++; // Skip whitespace
                break;
            case 'P': // Print path command
                print_path(robot);
                break;
            default:
                printf("Unknown command: %c\n", command);
                break;
        }
    }
}

int main() {
    Robot robot;
    initialize_robot(&robot);
    
    const char *commands = "M 45,10 M 90,20 M 135,10 P M 180,5 P";
    
    execute_commands(&robot, commands);
    
    return 0;
}