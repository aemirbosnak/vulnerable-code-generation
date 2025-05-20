//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    //Initializing variables
    int num_bags, num_flights, total_bags = 0;
    int max_bags_per_flight = 10;
    int time_per_bag = 1;
    int total_time = 0;

    printf("Welcome to the Airport Baggage Handling Simulation!\n");

    //Getting number of bags and flights from the user
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);
    printf("Enter the number of flights: ");
    scanf("%d", &num_flights);

    //Calculating total number of bags
    total_bags = num_bags * num_flights;

    //Calculating average time taken to handle one bag
    float avg_time_per_bag = (float)time_per_bag * num_bags / total_bags;

    //Printing output
    printf("\nTotal bags: %d\n", total_bags);
    printf("Max bags per flight: %d\n", max_bags_per_flight);
    printf("Average time per bag: %.2f seconds\n\n", avg_time_per_bag);

    //Simulating baggage handling process
    while(total_bags > 0)
    {
        //Calculating number of bags for current flight
        int bags_for_flight = rand() % max_bags_per_flight + 1;

        //Printing the number of bags for current flight
        printf("%d bags loaded onto the plane.\n", bags_for_flight);

        //Calculating time taken to handle the bags for current flight
        int time_for_flight = bags_for_flight * time_per_bag;

        //Updating total time and number of bags left
        total_time += time_for_flight;
        total_bags -= bags_for_flight;

        //Printing the time taken for current flight and the remaining number of bags
        printf("Time taken for this flight: %d seconds\n", time_for_flight);
        printf("%d bags remaining.\n\n", total_bags);
    }

    //Printing the total time taken to handle all bags
    printf("***Baggage handling complete! Total time taken: %d seconds.***\n", total_time);

    return 0;
}