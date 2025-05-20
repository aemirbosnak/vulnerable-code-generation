//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define BUFFER_SIZE 100

typedef struct _floor
{
    int floor;
    int occupants;
} Floor;

typedef struct _elevator
{
    int current_floor;
    int current_direction;
    Floor floors[MAX_FLOORS];
} Elevator;

void print_floor(Floor *floor)
{
    printf("%d: %d\n", floor->floor, floor->occupants);
}

void print_elevator(Elevator *elevator)
{
    printf("Current floor: %d\n", elevator->current_floor);
    printf("Current direction: %d\n", elevator->current_direction);
}

void move_up(Elevator *elevator)
{
    if (elevator->current_floor < MAX_FLOORS - 1)
    {
        elevator->current_floor++;
    }
    else
    {
        elevator->current_direction = -elevator->current_direction;
    }
}

void move_down(Elevator *elevator)
{
    if (elevator->current_floor > 0)
    {
        elevator->current_floor--;
    }
    else
    {
        elevator->current_direction = -elevator->current_direction;
    }
}

void add_occupant(Elevator *elevator)
{
    int i;
    for (i = 0; i < MAX_FLOORS; i++)
    {
        if (elevator->floors[i].occupants < 10)
        {
            elevator->floors[i].occupants++;
            break;
        }
    }
}

void remove_occupant(Elevator *elevator)
{
    int i;
    for (i = 0; i < MAX_FLOORS; i++)
    {
        if (elevator->floors[i].occupants > 0)
        {
            elevator->floors[i].occupants--;
            break;
        }
    }
}

int main()
{
    Elevator elevator;
    elevator.current_floor = 0;
    elevator.current_direction = 0;

    for (int i = 0; i < MAX_FLOORS; i++)
    {
        elevator.floors[i].floor = i;
        elevator.floors[i].occupants = 0;
    }

    int choice, floor, direction;
    while (1)
    {
        printf("1. Move up\n");
        printf("2. Move down\n");
        printf("3. Add occupant\n");
        printf("4. Remove occupant\n");
        printf("5. Print floor\n");
        printf("6. Print elevator\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                move_up(&elevator);
                break;
            case 2:
                move_down(&elevator);
                break;
            case 3:
                add_occupant(&elevator);
                break;
            case 4:
                remove_occupant(&elevator);
                break;
            case 5:
                print_floor(&elevator.floors[elevator.current_floor]);
                break;
            case 6:
                print_elevator(&elevator);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}