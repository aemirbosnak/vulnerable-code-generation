//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include<stdio.h>

/* Function prototypes */
void move_forward(int distance);
void move_backward(int distance);
void turn_left(int angle);
void turn_right(int angle);

/* Main function */
int main()
{
    int distance, angle;

    /* Get user input */
    printf("Enter distance to move forward (in cm): ");
    scanf("%d", &distance);
    printf("Moving robot forward %d cm...\n", distance);
    move_forward(distance);

    /* Get user input */
    printf("Enter distance to move backward (in cm): ");
    scanf("%d", &distance);
    printf("Moving robot backward %d cm...\n", distance);
    move_backward(distance);

    /* Get user input */
    printf("Enter angle to turn left (in degrees): ");
    scanf("%d", &angle);
    printf("Turning robot left %d degrees...\n", angle);
    turn_left(angle);

    /* Get user input */
    printf("Enter angle to turn right (in degrees): ");
    scanf("%d", &angle);
    printf("Turning robot right %d degrees...\n", angle);
    turn_right(angle);

    return 0;
}

/* Function definitions */

/* Moves robot forward by the specified distance (in cm) */
void move_forward(int distance)
{
    /* Code to move robot forward */
    printf("Robot moved forward %d cm\n", distance);
}

/* Moves robot backward by the specified distance (in cm) */
void move_backward(int distance)
{
    /* Code to move robot backward */
    printf("Robot moved backward %d cm\n", distance);
}

/* Turns robot left by the specified angle (in degrees) */
void turn_left(int angle)
{
    /* Code to turn robot left */
    printf("Robot turned left %d degrees\n", angle);
}

/* Turns robot right by the specified angle (in degrees) */
void turn_right(int angle)
{
    /* Code to turn robot right */
    printf("Robot turned right %d degrees\n", angle);
}