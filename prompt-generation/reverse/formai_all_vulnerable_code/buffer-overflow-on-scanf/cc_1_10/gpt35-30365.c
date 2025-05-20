//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float calculateProbability(int, int); //function to calculate probability of alien invasion

int main()
{
    int num_of_aliens, num_of_years;
    float probability;

    srand(time(0)); //seed the random number generator with current time

    printf("********** Alien Invasion Probability Calculator **********\n\n");

    printf("Enter the number of aliens on the alien spaceship: ");
    scanf("%d", &num_of_aliens);

    printf("Enter the number of years till the alien spaceship reaches Earth: ");
    scanf("%d", &num_of_years);

    probability = calculateProbability(num_of_aliens, num_of_years); //calculate probability of invasion

    printf("\n\nThe probability of an alien invasion in %d years is %f %%.\n\n", num_of_years, probability);

    return 0;
}

float calculateProbability(int num_of_aliens, int num_of_years)
{
    float probability;

    int i, successful_invasions = 0;

    for(i=0; i<1000; i++) //simulating 1000 attempts
    {
        int num_of_aliens_remaining = num_of_aliens;

        while(num_of_aliens_remaining > 0 && num_of_years > 0) //continue loop till all aliens are killed or all years have passed
        {
            int humans_killed = rand() % num_of_aliens_remaining; //randomly select number of humans killed in an encounter
            num_of_aliens_remaining -= humans_killed; //update the remaining aliens after humans attack

            int aliens_killed = rand() % 100; //randomly select number of aliens killed in an encounter
            num_of_aliens_remaining -= aliens_killed; //update the remaining aliens after aliens attack

            if(num_of_aliens_remaining <= 0) //aliens have invaded earth
            {
                successful_invasions++; 
                break;
            }

            num_of_years--; //update the remaining years
        }
    }

    probability = (float)successful_invasions / 10; //calculate probability of invasion

    return probability;
}