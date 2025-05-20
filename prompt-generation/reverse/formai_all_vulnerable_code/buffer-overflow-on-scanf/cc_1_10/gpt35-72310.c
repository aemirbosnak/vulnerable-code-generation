//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Function to generate random numbers
double rand_range(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

// Function to calculate alien invasion probability
void *aliens(void *arg)
{
    int years = *((int*) arg);
    double probability = 0.0;
    srand(time(NULL));
    
    for(int i = 0; i < years; i++)
    {
        double r = rand_range(0.0, 1.0);
        
        if(r > probability)
        {
            probability = r;
        }
        
        printf("Year %d: Alien invasion probability: %lf\n", i+1, probability);
        
        sleep(1);
    }
}

int main()
{
    int years;
    printf("Enter the number of years to calculate: ");
    scanf("%d", &years);
    
    pthread_t thread;
    
    if(pthread_create(&thread, NULL, aliens, &years))
    {
        printf("Error creating thread");
        return 1;
    }
    
    if(pthread_join(thread, NULL))
    {
        printf("Error joining thread");
        return 1;
    }
    
    return 0;
}