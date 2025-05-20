//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototype
void travel();

int main()
{
    int choice;

    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are a lone astronaut on a mission to explore the galaxy.\n");
    printf("You have the option of traveling through various planets in the galaxy.\n\n");

    while(1)
    {
        printf("Choose a planet to travel to: \n\n");
        printf("1. Zorin\n");
        printf("2. Xandar\n");
        printf("3. Omicron\n");
        printf("4. Exit Galaxy\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: travel("Zorin");
                    break;
            case 2: travel("Xandar");
                    break;
            case 3: travel("Omicron");
                    break;
            case 4: printf("Thank you for exploring the galaxy!\n");
                    exit(0);
            default:printf("Invalid choice!\n");
        }
    }
    return 0;
}

void travel(char* planet)
{
    int distance, fuel;
    int travel_time;
    int encounter;

    printf("\n\nTraveling to planet %s...\n\n", planet);
    srand(time(NULL));
    distance = rand() % 5000 + 1000;
    fuel = rand() % 500 + 100;

    printf("Distance to planet %s: %d light years\n", planet, distance);
    printf("Initial fuel: %d gallons\n\n", fuel);

    travel_time = distance / 10;
    printf("Estimated travel time: %d months\n\n", travel_time);

    //chance of encountering a space anomaly
    encounter = rand() % 10;
    if(encounter < 2)
    {
        printf("Warning! Space anomaly detected.\n");
        printf("Your ship is damaged and will require repairs before continuing.\n\n");
        return;
    }

    //fuel usage
    fuel -= distance/100;
    if(fuel <= 0)
    {
        printf("You have run out of fuel!\n");
        printf("Your ship is adrift in space...\n\n");
        return;
    }

    printf("Arrived at planet %s safely!\n", planet);
    printf("Remaining fuel: %d gallons\n\n", fuel);
}