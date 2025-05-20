//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
// C Remote Control Vehicle Simulation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SPEED 100
#define NUM_WHEELS 4

typedef struct vehicle {
    int speed;
    int direction;
    bool is_on;
    int wheel_rotation[NUM_WHEELS];
} vehicle;

int main(void)
{
    srand(time(NULL)); // Seed for random number generation
    
    vehicle my_car = {0, 0, false, {0}}; // Initialize vehicle struct
    
    // Menu for controlling the car
    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("1. Turn on/off the car\n");
    printf("2. Accelerate\n");
    printf("3. Brake\n");
    printf("4. Turn left\n");
    printf("5. Turn right\n");
    printf("6. Quit\n");
    
    int option;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                if (my_car.is_on) {
                    printf("Turning off the car...\n");
                    my_car.is_on = false;
                } else {
                    printf("Turning on the car...\n");
                    my_car.is_on = true;
                }
                break;
                
            case 2:
                if (my_car.is_on) {
                    int acceleration = rand() % (MAX_SPEED - my_car.speed + 1);
                    printf("Accelerating by %d mph...\n", acceleration);
                    my_car.speed += acceleration;
                    
                    // Rotate wheels based on speed
                    for (int i = 0; i < NUM_WHEELS; i++) {
                        my_car.wheel_rotation[i] += my_car.speed;
                    }
                } else {
                    printf("The car is off. Please turn it on before accelerating.\n");
                }
                break;
                
            case 3:
                if (my_car.is_on) {
                    int deceleration = rand() % (my_car.speed + 1);
                    printf("Decelerating by %d mph...\n", deceleration);
                    my_car.speed -= deceleration;
                    
                    // Rotate wheels based on speed
                    for (int i = 0; i < NUM_WHEELS; i++) {
                        my_car.wheel_rotation[i] += my_car.speed;
                    }
                } else {
                    printf("The car is off. Please turn it on before braking.\n");
                }
                break;
                
            case 4:
                if (my_car.is_on) {
                    printf("Turning left...\n");
                    my_car.direction--;
                } else {
                    printf("The car is off. Please turn it on before turning.\n");
                }
                break;
                
            case 5:
                if (my_car.is_on) {
                    printf("Turning right...\n");
                    my_car.direction++;
                } else {
                    printf("The car is off. Please turn it on before turning.\n");
                }
                break;
                
            case 6:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
        
        // Print car status
        printf("\nCar Status:\n");
        printf("Speed: %d mph\n", my_car.speed);
        printf("Direction: %d degrees\n", my_car.direction);
        printf("Wheel Rotations:\n");
        for (int i = 0; i < NUM_WHEELS; i++) {
            printf("Wheel %d: %d degrees\n", i+1, my_car.wheel_rotation[i]);
        }
    } while (option != 6);
    
    return 0;
}