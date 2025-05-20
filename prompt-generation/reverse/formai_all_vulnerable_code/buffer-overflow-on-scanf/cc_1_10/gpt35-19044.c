//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10

// Function to randomly generate the number of bags
int generate_num_bags()
{
    srand(time(NULL));
    return rand() % MAX_BAGS + 1;
}

// Function to handle the baggage of a passenger
void handle_baggage(int passenger_num, int num_bags)
{
    printf("Passenger %d checked in with %d bags.\n", passenger_num, num_bags);

    // Simulate baggage handling time for each bag
    for (int i = 1; i <= num_bags; i++)
    {
        int bag_handling_time = rand() % 10 + 1; // Random handling time between 1-10 seconds
        printf("Bag %d is being processed. It will take %d seconds.\n", i, bag_handling_time);
        sleep(bag_handling_time);
        printf("Bag %d has been processed.\n", i);
    }

    printf("Passenger %d's baggage has been handled.\n\n", passenger_num);
}

int main()
{
    int total_passengers = 0;
    int total_bags = 0;
    int current_passenger = 1;

    // Get the number of passengers
    printf("How many passengers are checking in? ");
    scanf("%d", &total_passengers);

    // Handle the baggage of each passenger
    while (current_passenger <= total_passengers)
    {
        int num_bags = generate_num_bags();
        total_bags += num_bags;
        handle_baggage(current_passenger, num_bags);
        current_passenger++;
    }

    printf("All passengers' baggage has been handled. Total bags: %d\n", total_bags);

    return 0;
}