//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int alien_invasion_probability = 0;
    float alien_ship_size = 0.0f;
    char alien_weapon_type = 'a';

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please provide the size of the alien ship in square meters:");
    scanf("%f", &alien_ship_size);

    printf("Please select the type of alien weapon (a for atomic, b for plasma, c for laser):");
    scanf(" %c", &alien_weapon_type);

    if (alien_ship_size >= 1000)
    {
        alien_invasion_probability = 90;
    }
    else if (alien_ship_size >= 500)
    {
        alien_invasion_probability = 75;
    }
    else if (alien_ship_size >= 250)
    {
        alien_invasion_probability = 50;
    }
    else
    {
        alien_invasion_probability = 25;
    }

    switch (alien_weapon_type)
    {
        case 'a':
            alien_invasion_probability += 10;
            break;
        case 'b':
            alien_invasion_probability += 5;
            break;
        case 'c':
            alien_invasion_probability += 2;
            break;
    }

    printf("The alien invasion probability is: %d%%", alien_invasion_probability);

    return 0;
}