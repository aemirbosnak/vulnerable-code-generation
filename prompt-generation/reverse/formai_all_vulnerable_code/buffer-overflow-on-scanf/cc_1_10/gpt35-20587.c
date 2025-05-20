//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\n\n*******************************************\n");
    printf("*** Welcome to Airport Baggage Handling! ***\n");
    printf("*******************************************\n\n");

    // initialize random seed
    srand(time(NULL));

    // define variables
    int num_flights, num_terminals, max_capacity;
    printf("Enter number of flights: ");
    scanf("%d", &num_flights);
    printf("Enter number of terminals: ");
    scanf("%d", &num_terminals);
    printf("Enter maximum capacity of each terminal: ");
    scanf("%d", &max_capacity);

    // calculate total capacity of the airport
    int total_capacity = num_terminals * max_capacity;

    // initialize counters and arrays
    int i, j, k, current_capacity, num_bags;
    int total_bags_handled = 0, total_delay_time = 0;
    int bags_per_flight[num_flights], delay_times[num_flights];
    int terminal_capacity[num_terminals];

    for (i = 0; i < num_flights; i++) {
        // generate random number of bags per flight (between 100 and 300)
        bags_per_flight[i] = rand() % 201 + 100;
        total_bags_handled += bags_per_flight[i];
        // generate random delay time for each flight (between 0 and 60)
        delay_times[i] = rand() % 61;
        total_delay_time += delay_times[i];
    }

    printf("\n\n===========================================\n");
    printf("        Airport Baggage Handling Report     \n");
    printf("===========================================\n\n");

    printf("Number of flights: %d\n", num_flights);
    printf("Number of terminals: %d\n", num_terminals);
    printf("Maximum capacity of each terminal: %d\n", max_capacity);
    printf("Total capacity of the airport: %d\n", total_capacity);
    printf("Total number of bags handled: %d\n", total_bags_handled);
    printf("Total delay time: %d minutes\n", total_delay_time);

    // initialize terminal_capacity array to 0
    for (i = 0; i < num_terminals; i++) {
        terminal_capacity[i] = 0;
    }

    // handle each flight's baggage
    for (i = 0; i < num_flights; i++) {
        printf("\n\nFlight %d: %d bags, %d minute delay", i+1, bags_per_flight[i], delay_times[i]);
        // randomly assign terminal number for the flight
        int terminal_num = rand() % num_terminals;
        printf("\nAssigned to Terminal %d", terminal_num+1);
        // check if there is enough capacity in the terminal
        if (terminal_capacity[terminal_num] + bags_per_flight[i] <= max_capacity) {
            // update terminal capacity
            terminal_capacity[terminal_num] += bags_per_flight[i];
            printf("\nLuggage loaded successfully!");
        }
        else {
            // calculate delay time due to lack of capacity
            int delay_time = (terminal_capacity[terminal_num] + bags_per_flight[i] - max_capacity) / max_capacity * 10;
            printf("\nLuggage could not be loaded due to lack of capacity.");
            printf("\nPlease wait %d minutes before loading luggage.", delay_time);
            // update delay times array
            delay_times[i] += delay_time;
            total_delay_time += delay_time;
        }
    }

    printf("\n\n====================================================\n");
    printf("         Terminal Capacity Report                        \n");
    printf("====================================================\n\n");

    // print capacity report for each terminal
    for (i = 0; i < num_terminals; i++) {
        printf("Terminal %d capacity: %d/%d\n", i+1, terminal_capacity[i], max_capacity);
    }

    printf("\n\n====================================================\n");
    printf("         Baggage Delay Report                        \n");
    printf("====================================================\n\n");

    // print delay report for each flight
    for (i = 0; i < num_flights; i++) {
        printf("Flight %d delay time: %d minutes\n", i+1, delay_times[i]);
    }

    return 0;
}