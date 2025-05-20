//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>

int main()
{
    // Set the initial position of the vehicle
    int x = 0, y = 0;

    // Set the initial direction of the vehicle
    char direction = 'N';

    // Set the speed of the vehicle
    int speed = 10;

    // Set the maximum distance the vehicle can travel
    int max_distance = 100;

    // Set the maximum fuel level of the vehicle
    int max_fuel = 100;

    // Set the initial fuel level of the vehicle
    int fuel = 50;

    // Set the distance traveled by the vehicle
    int distance = 0;

    // Set the time taken by the vehicle to travel a distance
    float time_taken = 0.0;

    // Set the acceleration of the vehicle
    float acceleration = 5.0;

    // Set the brake of the vehicle
    float brake = 2.0;

    // Set the random seed for the random number generator
    srand(time(NULL));

    // Initialize the program
    printf("C Remote Control Vehicle Simulation\n\n");
    printf("Commands:\n");
    printf("  f <distance>   Move the vehicle forward\n");
    printf("  b <distance>   Move the vehicle backward\n");
    printf("  l              Turn the vehicle left\n");
    printf("  r              Turn the vehicle right\n");
    printf("  s <speed>      Set the speed of the vehicle\n");
    printf("  q              Quit the program\n\n");

    // Start the simulation loop
    while(1)
    {
        // Print the current position and direction of the vehicle
        printf("Current position: (%d, %d)\n", x, y);
        printf("Current direction: %c\n", direction);

        // Get the user input
        char input[100];
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%c %d", &input[0], &input[2]);

        // Process the user input
        switch(input[0])
        {
            case 'f':
                // Move the vehicle forward
                if(fuel > 0)
                {
                    if(input[2] > max_distance - distance)
                    {
                        printf("The vehicle can't move forward that far.\n");
                        input[2] = max_distance - distance;
                    }
                    distance += input[2];
                    fuel -= input[2] / acceleration;
                    time_taken += input[2] / (float)speed;
                    switch(direction)
                    {
                        case 'N':
                            y += input[2];
                            break;
                        case 'S':
                            y -= input[2];
                            break;
                        case 'E':
                            x += input[2];
                            break;
                        case 'W':
                            x -= input[2];
                            break;
                    }
                }
                else
                {
                    printf("The vehicle is out of fuel.\n");
                }
                break;
            case 'b':
                // Move the vehicle backward
                if(input[2] > distance)
                {
                    printf("The vehicle can't move backward that far.\n");
                    input[2] = distance;
                }
                distance -= input[2];
                time_taken += input[2] / (float)speed;
                switch(direction)
                {
                    case 'N':
                        y -= input[2];
                        break;
                    case 'S':
                        y += input[2];
                        break;
                    case 'E':
                        x -= input[2];
                        break;
                    case 'W':
                        x += input[2];
                        break;
                }
                break;
            case 'l':
                // Turn the vehicle left
                switch(direction)
                {
                    case 'N':
                        direction = 'W';
                        break;
                    case 'S':
                        direction = 'E';
                        break;
                    case 'E':
                        direction = 'N';
                        break;
                    case 'W':
                        direction = 'S';
                        break;
                }
                break;
            case 'r':
                // Turn the vehicle right
                switch(direction)
                {
                    case 'N':
                        direction = 'E';
                        break;
                    case 'S':
                        direction = 'W';
                        break;
                    case 'E':
                        direction = 'S';
                        break;
                    case 'W':
                        direction = 'N';
                        break;
                }
                break;
            case 's':
                // Set the speed of the vehicle
                if(input[2] > 0 && input[2] <= 100)
                {
                    speed = input[2];
                }
                else
                {
                    printf("Invalid speed input.\n");
                }
                break;
            case 'q':
                // Quit the program
                printf("Quitting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Reduce the fuel level randomly
        fuel -= rand() % 5;

        // Refuel the vehicle if the fuel level is too low
        if(fuel < 20)
        {
            printf("WARNING: The vehicle is running low on fuel.\n");
            int refuel_amount = max_fuel - fuel;
            fuel = max_fuel;
            printf("Refueling the vehicle with %d units of fuel.\n", refuel_amount);
        }

        // Print the distance traveled and time taken by the vehicle
        printf("Distance traveled: %d\n", distance);
        printf("Time taken: %.2f seconds\n\n", time_taken);
    }

    return 0;
}