//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
/* 
Alien Invasion Probability Calculator
By: [Your Name]

Description: This program calculates the probability of an alien invasion based on various factors such as distance,
             civilization level, and technology. The user inputs various values to determine the overall probability. 
             The program generates a creative output message based on the final probability.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //seed the random function with the current time
    srand(time(NULL));

    //initialize user input variables
    float distance;
    int level, technology;

    //initialize calculation variables
    float distProb, levelProb, techProb, finalProb;

    //get user input for distance in light years
    printf("Enter the distance from Earth to the alien civilization (in light years): ");
    scanf("%f", &distance);

    //calculate probability based on distance
    if (distance < 10)
        distProb = 0.9;
    else if (distance >= 10 && distance < 100)
        distProb = 0.7;
    else if (distance >= 100 && distance < 1000)
        distProb = 0.5;
    else
        distProb = 0.2;

    //get user input for civilization level
    printf("Enter the level of the alien civilization (1 for primitive, 2 for advanced, 3 for god-like): ");
    scanf("%d", &level);

    //calculate probability based on civilization level
    switch (level)
    {
        case 1:
            levelProb = 0.1;
            break;
        case 2:
            levelProb = 0.5;
            break;
        case 3:
            levelProb = 0.9;
            break;
        default:
            levelProb = 0;
    }

    //get user input for technology level
    printf("Enter the technology level of the alien civilization (1 for primitive, 2 for advanced, 3 for god-like): ");
    scanf("%d", &technology);

    //calculate probability based on technology level
    switch (technology)
    {
        case 1:
            techProb = 0.2;
            break;
        case 2:
            techProb = 0.5;
            break;
        case 3:
            techProb = 0.8;
            break;
        default:
            techProb = 0;
    }

    //calculate final probability
    finalProb = distProb * levelProb * techProb;

    //generate output message based on final probability
    if (finalProb >= 0.9)
        printf("The probability of an alien invasion is extremely high! We must prepare for the worst!");
    else if (finalProb >= 0.6 && finalProb < 0.9)
        printf("The probability of an alien invasion is high. We should be cautious and take necessary precautions.");
    else if (finalProb >= 0.3 && finalProb < 0.6)
        printf("The probability of an alien invasion is moderate. We should keep an eye out for any signs of possible encounter.");
    else if (finalProb >= 0.1 && finalProb < 0.3)
        printf("The probability of an alien invasion is low. We should not worry too much, but still be prepared.");
    else
        printf("The probability of an alien invasion is extremely low. There is nothing to worry about!");
    
    //exit the program
    return 0;
}