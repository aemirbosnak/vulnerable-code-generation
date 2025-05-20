//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds) // Function to create a delay
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void intro() // Function to display the intro
{
    printf("Welcome to Space Adventure!\n\n");
    delay(2);
    printf("You have been chosen to explore the outer space and find a new planet for humanity to inhabit.\n");
    delay(5);
    printf("Are you ready to begin your adventure?\n\n");
}

void travel() // Function to travel in space
{
    printf("Preparing for interstellar travel...\n");
    delay(3);

    int destination = rand() % 4 + 1; // Randomly generates a destination

    switch (destination)
    {
    case 1:
        printf("You have arrived at Planet Zeta!\n");
        break;
    case 2:
        printf("You have arrived at Planet Nova!\n");
        break;
    case 3:
        printf("You have arrived at Planet Xenon!\n");
        break;
    case 4:
        printf("You have arrived at Planet Krypton!\n");
        break;
    default:
        printf("Unknown planet detected...\n");
        break;
    }
}

int main()
{
    srand(time(NULL)); // Initializes the random number generator

    intro(); // Displays the intro

    char choice;
    do {
        printf("Choose an option:\n");
        printf("1. Travel to a new planet\n");
        printf("2. Quit\n");

        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            travel();
            break;
        case '2':
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != '2');

    return 0;
}