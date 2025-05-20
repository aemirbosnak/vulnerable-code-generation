//FormAI DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Global variables to store the current position of the robot
int x = 0;
int y = 0;

// Function to move the robot in the forward direction
void move_forward(int distance)
{
    printf("Moving forward %d units...\n", distance);
    y += distance;
}

// Function to move the robot in the backward direction
void move_backward(int distance)
{
    printf("Moving backward %d units...\n", distance);
    y -= distance;
}

// Function to turn the robot left
void turn_left()
{
    printf("Turning left...\n");
    x -= 1;
}

// Function to turn the robot right
void turn_right()
{
    printf("Turning right...\n");
    x += 1;
}

// Function to print the current position of the robot
void print_position()
{
    printf("Current position: (%d, %d)\n", x, y);
}

// Main function to control the movement of the robot
int main()
{
    int choice, distance;
    
    while(1) {
        printf("\n1. Move forward\n2. Move backward\n3. Turn left\n4. Turn right\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter distance to move forward: ");
                scanf("%d", &distance);
                move_forward(distance);
                break;
            
            case 2:
                printf("Enter distance to move backward: ");
                scanf("%d", &distance);
                move_backward(distance);
                break;
            
            case 3:
                turn_left();
                break;
            
            case 4:
                turn_right();
                break;
                
            case 5:
                exit(0);
            
            default:
                printf("Invalid choice!\n");
                break;
        }
        
        print_position();
    }
    
    return 0;
}