//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function Prototypes */
bool validate_command(char command);
void move_forward(int *x_pos, int *y_pos);
void move_backward(int *x_pos, int *y_pos);
void move_left(int *x_pos, int *y_pos);
void move_right(int *x_pos, int *y_pos);

/* Main Function */
int main()
{
    int x_pos = 0; // initial x position
    int y_pos = 0; // initial y position
    char input;

    printf("Welcome to C Drone Remote Control!\n\n");
    printf("Commands: \n f -> move forward \n b -> move backward \n l -> move left \n r -> move right \n q -> quit program\n");

    while (true) // loop until quit entered
    {
        printf("\nEnter a command: ");
        scanf("%c", &input); // read user input

        if (!validate_command(input)) // check if valid input
        {
            printf("Invalid command!");
            continue;
        }

        switch (input)
        {
            case 'f':
                move_forward(&x_pos, &y_pos);
                break;
            case 'b':
                move_backward(&x_pos, &y_pos);
                break;
            case 'l':
                move_left(&x_pos, &y_pos);
                break;
            case 'r':
                move_right(&x_pos, &y_pos);
                break;
            case 'q':
                printf("Exiting program...");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid command!");
                break;
        }

        printf("\nCurrent Position: (%d, %d)\n", x_pos, y_pos); // output current position
        getchar(); // clear input buffer
    }

    return 0;
}

/* Functions */
bool validate_command(char command)
{
    if (command == 'f' || command == 'b' || command == 'l' || command == 'r' || command == 'q')
        return true;
    else
        return false;
}

void move_forward(int *x_pos, int *y_pos)
{
    (*y_pos)++; // increment y position
}

void move_backward(int *x_pos, int *y_pos)
{
    (*y_pos)--; // decrement y position
}

void move_left(int *x_pos, int *y_pos)
{
    (*x_pos)--; // decrement x position
}

void move_right(int *x_pos, int *y_pos)
{
    (*x_pos)++; // increment x position
}