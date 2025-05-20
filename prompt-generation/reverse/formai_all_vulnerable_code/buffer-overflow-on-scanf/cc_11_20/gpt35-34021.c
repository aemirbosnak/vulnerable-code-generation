//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
 * This program takes inputs from the user regarding the location
 * and other factors and calculates the probability of
 * an alien invasion for that particular location using a multivariable style.
 */

int main() 
{
    int threatLevel = 0;
    float distanceFromEarth, numberOfMoons, temperature;
    char planetName[20], hasAtmosphere, isHabitable;

    printf("Enter the name of the planet:");
    scanf("%s",&planetName);

    printf("What is the distance of %s from Earth (in light years)?:", planetName);
    scanf("%f",&distanceFromEarth);

    printf("How many moons does %s have?:", planetName);
    scanf("%f",&numberOfMoons);

    printf("What is the temperature of %s (in Celsius)?:", planetName);
    scanf("%f",&temperature);

    printf("Does %s have an atmosphere? (Y/N):", planetName);
    scanf(" %c",&hasAtmosphere);

    printf("Is %s habitable? (Y/N):", planetName);
    scanf(" %c",&isHabitable);

    // assigning threat level based on the inputs
    if (distanceFromEarth > 20)
        threatLevel += 3;
    else if (distanceFromEarth > 5 && distanceFromEarth <= 20)
        threatLevel += 2;
    else
        threatLevel += 1;

    if (numberOfMoons >= 2 && numberOfMoons <= 4)
        threatLevel += 1;
    else if (numberOfMoons > 4)
        threatLevel += 2;

    if (temperature > 100)
        threatLevel += 3;
    else if (temperature > -50 && temperature <= 100)
        threatLevel += 2;
    else
        threatLevel += 1;

    if (hasAtmosphere == 'Y')
        threatLevel += 1;
    else
        threatLevel += 3;

    if (isHabitable == 'Y')
        threatLevel += 1;
    else
        threatLevel += 3;

    printf("The probability of an alien invasion on %s is %.2f percent\n", planetName, ((float) threatLevel / 15) * 100);

    return 0;
}