//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Are you ready to see just how likely it is that aliens will take over Earth? (y/n)\n");
    char input;
    scanf("%c", &input);
    if(input == 'y')
    {
        printf("Great, let's get started!\n");
        printf("Here are some factors that will affect the probability of an alien invasion:\n");
        printf("1. The distance between Earth and other inhabited planets\n");
        printf("2. The technology level of the aliens\n");
        printf("3. The probability of alien life existing in the first place\n");
        printf("4. The probability that they would want to invade Earth, rather than coexist peacefully\n");
        printf("5. The preparedness of Earth's defenses\n");
        printf("Now, let's assign each factor a score from 1 to 10, with 1 being the least likely and 10 being the most likely.\n");
        int distance, techLevel, alienLife, invasionProb, defense;
        printf("Factor 1: Distance (1-10) - How likely is it that there are other planets in our galaxy with intelligent life?\n");
        scanf("%d", &distance);
        printf("Factor 2: Technology Level (1-10) - Assuming there is intelligent alien life, how much more advanced than us do you think their technology would be?\n");
        scanf("%d", &techLevel);
        printf("Factor 3: Alien Life Probability (1-10) - How likely do you think it is that life has evolved elsewhere in the universe?\n");
        scanf("%d", &alienLife);
        printf("Factor 4: Invasion Probability (1-10) - Assuming there is intelligent alien life and their technology is more advanced than ours, how likely do you think it is that they would want to invade Earth rather than coexist peacefully?\n");
        scanf("%d", &invasionProb);
        printf("Factor 5: Defense (1-10) - Assuming they did want to invade Earth, how prepared do you think we would be to defend ourselves?\n");
        scanf("%d", &defense);
        int totalScore = distance + techLevel + alienLife + invasionProb + defense;
        float probability = ((float)totalScore / 50) * 100;
        printf("Calculating invasion probability...\n");
        srand(time(NULL));
        int delay = rand() % 3 + 1;
        switch (delay)
        {
            case 1:
                printf("Analyzing data...\n");
                break;
            case 2:
                printf("Processing information...\n");
                break;
            case 3:
                printf("Simulating outcomes...\n");
                break;
        }
        for(int i = 0; i < 3; i++)
        {
            printf(".");
            sleep(1);
        }
        printf("\n");
        printf("The probability of an alien invasion is: %0.2f%%\n", probability);
        printf("Thanks for using the Alien Invasion Probability Calculator! Stay safe out there.\n");
    }
    else if(input == 'n')
    {
        printf("Okay, come back when you're ready!\n");
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
    return 0;
}