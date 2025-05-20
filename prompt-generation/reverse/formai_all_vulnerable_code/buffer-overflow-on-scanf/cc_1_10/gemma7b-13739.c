//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cosmic_toast(int num_aliens);
int alien_invasion_probability(int num_aliens, float distance);

int main()
{
    int num_aliens = 0;
    float distance = 0.0f;

    printf("Greetings, mortal! Prepare for the cosmic crunch...\n");

    // Get the number of aliens and distance from the sun
    printf("How many aliens are invading? ");
    scanf("%d", &num_aliens);

    printf("What is the distance of the invasion in light-years? ");
    scanf("%f", &distance);

    // Calculate the invasion probability
    int probability = alien_invasion_probability(num_aliens, distance);

    // Display the probability of invasion
    printf("The probability of alien invasion is: %d%%", probability);

    // Toast the planet
    cosmic_toast(num_aliens);

    return 0;
}

void cosmic_toast(int num_aliens)
{
    for (int i = 0; i < num_aliens; i++)
    {
        printf("Boo hoo hoo! You're toast, mortal!\n");
    }
}

int alien_invasion_probability(int num_aliens, float distance)
{
    float probability = 0.0f;

    // The probability of alien invasion increases with the number of aliens and decreases with distance
    probability = (num_aliens * 0.05f) / distance;

    return (int) probability;
}