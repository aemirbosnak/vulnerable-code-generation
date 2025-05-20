//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Robot movement control example program
//This program allows the user to control a robot using keyboard input.
//The robot can move forward, backward, left, right, and stop.

//Define the robot's starting position
int x = 0;
int y = 0;

//Define the robot's speed
int speed = 1;

//Define the robot's direction
int direction = 0; //0: forward, 1: backward, 2: left, 3: right

//Define the keyboard input keys
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_STOP 'q'

//Function to get keyboard input
char get_keyboard_input()
{
    char input;
    scanf("%c", &input);
    return input;
}

//Function to move the robot forward
void move_forward()
{
    if (direction == 0)
    {
        y += speed;
    }
    else if (direction == 1)
    {
        y -= speed;
    }
    else if (direction == 2)
    {
        x -= speed;
    }
    else if (direction == 3)
    {
        x += speed;
    }
}

//Function to move the robot backward
void move_backward()
{
    if (direction == 0)
    {
        y -= speed;
    }
    else if (direction == 1)
    {
        y += speed;
    }
    else if (direction == 2)
    {
        x += speed;
    }
    else if (direction == 3)
    {
        x -= speed;
    }
}

//Function to move the robot left
void move_left()
{
    if (direction == 0)
    {
        x -= speed;
    }
    else if (direction == 1)
    {
        x += speed;
    }
    else if (direction == 2)
    {
        y -= speed;
    }
    else if (direction == 3)
    {
        y += speed;
    }
}

//Function to move the robot right
void move_right()
{
    if (direction == 0)
    {
        x += speed;
    }
    else if (direction == 1)
    {
        x -= speed;
    }
    else if (direction == 2)
    {
        y += speed;
    }
    else if (direction == 3)
    {
        y -= speed;
    }
}

//Function to stop the robot
void stop()
{
    speed = 0;
}

//Function to print the robot's position
void print_position()
{
    printf("Robot position: (%d, %d)\n", x, y);
}

//Main function
int main()
{
    //Print the robot's starting position
    print_position();

    //Loop until the user presses the stop key
    while (1)
    {
        //Get keyboard input
        char input = get_keyboard_input();

        //Process keyboard input
        switch (input)
        {
        case KEY_UP:
            move_forward();
            break;
        case KEY_DOWN:
            move_backward();
            break;
        case KEY_LEFT:
            move_left();
            break;
        case KEY_RIGHT:
            move_right();
            break;
        case KEY_STOP:
            stop();
            break;
        }

        //Print the robot's position
        print_position();
    }

    return 0;
}