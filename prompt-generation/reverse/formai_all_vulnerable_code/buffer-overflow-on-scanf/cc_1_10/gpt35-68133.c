//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// function to calculate the probability of alien invasion
double probAlienInvasion(int n)
{
    double prob = 0;
    int aliens = 0;
    srand(time(NULL)); // seed the rand function with current time

    for(int i=0; i<n; i++) // loop n times
    {
        int rand_num = rand() % 100; // generate random number between 0 and 99
        if(rand_num > 95) // if the random number is greater than 95
        {
            aliens++; // increment the number of alien invasions
        }
    }

    prob = (double)aliens/n * 100; // calculate the probability of alien invasion

    return prob;
}

int main()
{
    int num_tests = 0; // number of test cases
    printf("Enter the number of test cases: ");
    scanf("%d", &num_tests); // read in the number of test cases

    if(num_tests <= 0) // validate user input
    {
        printf("Invalid input. Please enter a positive integer.\n");
        exit(1);
    }

    printf("\n");

    for(int i=0; i<num_tests; i++) // loop through each test case
    {
        int n = 0; // number of times to run the test
        printf("Enter the number of times to run the test: ");
        scanf("%d", &n); // read in the number of times to run the test

        if(n <= 0) // validate user input
        {
            printf("Invalid input. Please enter a positive integer.\n");
            exit(1);
        }

        double prob = probAlienInvasion(n); // calculate the probability of alien invasion
        printf("Probability of Alien Invasion: %.2lf%%\n", prob); // print the probability
        if(prob >= 50) // if probability is greater than or equal to 50%
        {
            printf("RUN FOR YOUR LIVES!\n\n");
        }
        else
        {
            printf("Relax, it's unlikely to happen.\n\n");
        }
    }

    return 0;
}