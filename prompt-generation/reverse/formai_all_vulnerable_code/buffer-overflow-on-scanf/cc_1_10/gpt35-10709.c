//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void move_forward(int steps);
void move_backward(int steps);
void turn_left();
void turn_right();

/* Main function */
int main()
{
    char input;
    int steps;

    printf("\nWelcome to Retro Robot Control Panel!\n");

    while (1) {
        printf("\nEnter a command (f=forward, b=backward, l=left, r=right, q=quit): ");
        scanf(" %c", &input);

        switch (input) {
            case 'f':
                printf("\nHow many steps would you like to move forward? ");
                scanf("%d", &steps);
                move_forward(steps);
                break;
            case 'b':
                printf("\nHow many steps would you like to move backward? ");
                scanf("%d", &steps);
                move_backward(steps);
                break;
            case 'l':
                turn_left();
                break;
            case 'r':
                turn_right();
                break;
            case 'q':
                printf("\nGoodbye! Retro Robot has been shutdown.\n\n");
                exit(0);
                break;
            default:
                printf("\nInvalid command. Please enter a valid command.\n");
        }
    }

    return 0;
}

/* Function definitions */

void move_forward(int steps)
{
    int i;
    printf("\nMoving forward %d steps...\n", steps);
    for (i = 0; i < steps; i++) {
        printf("*");
    }
    printf("\n");
}

void move_backward(int steps)
{
    int i;
    printf("\nMoving backward %d steps...\n", steps);
    for (i = 0; i < steps; i++) {
        printf("*");
    }
    printf("\n");
}

void turn_left()
{
    printf("\nTurning left...\n");
    printf("<\n");
}

void turn_right()
{
    printf("\nTurning right...\n");
    printf(">\n");
}