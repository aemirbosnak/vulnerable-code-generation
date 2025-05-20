//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_FLOOR 10
#define MIN_FLOOR 1

int current_floor = 1;
int elevator_direction;
bool door_open = false;
void open_door();
void close_door();
void move_elevator(int);

int main()
{
    int floor_num;
    printf("Welcome to the Elevator Simulator!\n");
    while (true)
    {
        printf("\nYou are currently on floor %d\n", current_floor);
        printf("Where would you like to go?\n");
        printf("Enter floor number: ");
        scanf("%d", &floor_num);
        if (floor_num < MIN_FLOOR || floor_num > MAX_FLOOR)
        {
            printf("Invalid floor number!\n");
            continue;
        }
        printf("Going to floor %d...\n", floor_num);
        move_elevator(floor_num);
        open_door();
        printf("Welcome to floor %d!\n", floor_num);
        close_door();
    }
    return 0;
}

void open_door()
{
    door_open = true;
    printf("Elevator door opening...\n");
    printf("Elevator door opened!\n");
}

void close_door()
{
    door_open = false;
    printf("Elevator door closing...\n");
    printf("Elevator door closed!\n");
}

void move_elevator(int floor_num)
{
    elevator_direction = (current_floor < floor_num) ? 1 : -1;
    printf("Elevator moving %s...\n", (elevator_direction == 1) ? "up" : "down");
    while (current_floor != floor_num)
    {
        printf("Elevator is now at floor %d\n", current_floor);
        current_floor = current_floor + elevator_direction;
    }
    printf("Elevator has arrived at floor %d\n", current_floor);
}