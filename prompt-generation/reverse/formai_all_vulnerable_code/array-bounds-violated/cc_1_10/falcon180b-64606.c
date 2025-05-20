//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN 100
#define MIN_TURN 1
#define MAX_TIME 5
#define MIN_TIME 1

typedef struct {
    int speed;
    int turn;
    int time;
} command_t;

void execute_command(int speed, int turn, int time) {
    printf("Executing command: speed %d, turn %d, time %d\n", speed, turn, time);
}

int main() {
    srand(time(NULL));

    int num_commands;
    printf("Enter number of commands: ");
    scanf("%d", &num_commands);

    command_t commands[num_commands];

    for (int i = 0; i < num_commands; i++) {
        commands[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        commands[i].turn = rand() % (MAX_TURN - MIN_TURN + 1) + MIN_TURN;
        commands[i].time = rand() % (MAX_TIME - MIN_TIME + 1) + MIN_TIME;
    }

    int current_command = 0;

    while (1) {
        if (current_command >= num_commands) {
            current_command = 0;
        }

        execute_command(commands[current_command].speed, commands[current_command].turn, commands[current_command].time);

        current_command++;

        sleep(commands[current_command - 1].time);
    }

    return 0;
}