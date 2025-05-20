//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int current_latitude = rand() % 90;
    int current_longitude = rand() % 180;
    int destination_latitude = rand() % 90;
    int destination_longitude = rand() % 180;

    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Your current location is (%d, %d)\n", current_latitude, current_longitude);

    int distance_to_destination = abs(destination_latitude - current_latitude) + abs(destination_longitude - current_longitude);

    printf("You are %d units away from your destination at (%d, %d)\n\n", distance_to_destination, destination_latitude, destination_longitude);

    printf("Instructions: \n");
    printf("1) Move North: Press 'n' \n");
    printf("2) Move South: Press 's' \n");
    printf("3) Move East: Press 'e' \n");
    printf("4) Move West: Press 'w' \n");
    printf("5) Quit: Press 'q' \n");

    while (1)
    {
        char input;
        printf("\nEnter your choice: ");
        scanf(" %c", &input);

        switch (input)
        {
        case 'n':
            current_latitude++;
            break;
        case 's':
            current_latitude--;
            break;
        case 'e':
            current_longitude++;
            break;
        case 'w':
            current_longitude--;
            break;
        case 'q':
            printf("Quitting GPS Navigation Simulation... Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid input. Try again.\n");
            continue;
        }

        int distance_to_destination_new = abs(destination_latitude - current_latitude) + abs(destination_longitude - current_longitude);

        if (distance_to_destination_new == 0)
        {
            printf("Congratulations! You have reached your destination at (%d, %d)\n", destination_latitude, destination_longitude);
            printf("Exiting GPS Navigation Simulation... Goodbye!\n");
            exit(0);
        }
        else if (distance_to_destination_new < distance_to_destination)
        {
            printf("Getting closer... You are now %d units away from your destination at (%d, %d)\n", distance_to_destination_new, destination_latitude, destination_longitude);
        }
        else
        {
            printf("Going the wrong way... You are %d units away from your destination at (%d, %d)\n", distance_to_destination_new, destination_latitude, destination_longitude);
        }

        distance_to_destination = distance_to_destination_new;
    }

    return 0;
}