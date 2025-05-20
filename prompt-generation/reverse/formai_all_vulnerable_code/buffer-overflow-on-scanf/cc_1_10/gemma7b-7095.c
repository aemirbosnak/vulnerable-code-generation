//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house()
{
    int choice;
    char answer;
    time_t start_time, end_time;

    // Set the start time
    start_time = time(NULL);

    // Print the haunted house scenario
    printf("You find yourself in a dimly lit haunted house. The only sound is your own breathing and the echoes of your footsteps. You hear a sudden noise and your heart skips a beat. Do you want to:\n");

    // Display the options
    printf("1. Explore the house.\n");
    printf("2. Leave the house.\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Check the user's choice
    switch (choice)
    {
        case 1:
            // Go exploring the house
            printf("You cautiously explore the house, but find nothing. You hear a rustling sound and turn around, but there is nothing there.\n");
            break;
        case 2:
            // Leave the house
            printf("You flee the house, but the sound of footsteps follows you. You turn around and see a ghostly figure standing behind you.\n");
            break;
        default:
            // Invalid choice
            printf("Invalid choice.\n");
    }

    // Get the end time
    end_time = time(NULL);

    // Calculate the time spent in the haunted house
    int time_spent = end_time - start_time;

    // Print the time spent in the haunted house
    printf("You spent %d seconds in the haunted house.\n", time_spent);

    // Play again?
    printf("Do you want to play again? (Y/N): ");

    // Get the user's answer
    scanf(" %c", &answer);

    // Check if the user wants to play again
    if (answer == 'Y')
    {
        play_haunted_house();
    }
}

int main()
{
    play_haunted_house();

    return 0;
}