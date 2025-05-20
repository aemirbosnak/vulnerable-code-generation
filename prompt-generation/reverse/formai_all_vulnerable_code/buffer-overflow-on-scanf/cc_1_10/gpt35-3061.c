//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random number between 0 and 1
double rand_number()
{
    double num = (double)rand() / RAND_MAX;
    return num;
}

// Function to calculate the probability of alien invasion
double alien_invasion_prob(int year)
{
    double prob = 0.0;
    
    if(year < 2022)
    {
        prob = 0.0;
    }
    else if(year >= 2022 && year < 2042)
    {
        prob = 0.001 * rand_number();
    }
    else if(year >= 2042 && year < 2062)
    {
        prob = 0.005 * rand_number();
    }
    else if(year >= 2062 && year < 2082)
    {
        prob = 0.01 * rand_number();
    }
    else
    {
        prob = 0.02 * rand_number();
    }
    
    return prob;
}

// Main function to execute the program
int main()
{
    int year;
    double prob;
    time_t t;
    
    // Intialize random number generator
    srand((unsigned) time(&t));
    
    // Get the current year
    printf("Enter the current year:\n");
    scanf("%d", &year);
    
    // Calculate the probability of alien invasion
    prob = alien_invasion_prob(year);
    
    // Output the probability of alien invasion
    printf("The probability of alien invasion in %d is %lf\n", year, prob);
    
    return 0;
}