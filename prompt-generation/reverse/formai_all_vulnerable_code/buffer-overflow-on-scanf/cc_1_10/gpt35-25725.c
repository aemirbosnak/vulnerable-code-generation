//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Seeding random number generator
    srand(time(0));
    
    //Defining variables
    int num_bags, time_interval, i;
    char bag_type;
    
    //Printing introduction message
    printf("Welcome to the Medieval Baggage Handling Simulation!\n\n");
    printf("Our system will generate random numbers of bags and their types, and will simulate the time it takes to handle them.\n");
    
    //Taking user input for time interval
    printf("\nPlease enter the time interval (in seconds) between each run of the simulation: ");
    scanf("%d", &time_interval);
    
    //Generating and handling bags
    while(1) {
        //Generating random number of bags and their types
        num_bags = rand() % 10 + 1;
        printf("%d bags arrived at the baggage handling area! They are:\n", num_bags);
        for(i = 0; i < num_bags; i++) {
            if(rand() % 2 == 0) {
                bag_type = 'H'; //Heavy bag
            } else {
                bag_type = 'L'; //Light bag
            }
            printf("%c ", bag_type);
        }
        printf("\n");
        
        //Simulating time taken to handle bags
        for(i = 0; i < num_bags; i++) {
            if(bag_type == 'H') {
                printf("Bag %d is a heavy bag. It will take longer to handle.\n", i+1);
                //Simulating time taken to handle heavy bags (30-60 seconds)
                printf("Handling Bag %d...\n", i+1);
                printf("Time taken to handle Bag %d: %d seconds\n\n", i+1, (rand() % 31) + 30);
            } else {
                printf("Bag %d is a light bag. It will take less time to handle.\n", i+1);
                //Simulating time taken to handle light bags (10-30 seconds)
                printf("Handling Bag %d...\n", i+1);
                printf("Time taken to handle Bag %d: %d seconds\n\n", i+1, (rand() % 21) + 10);
            }
        }
        
        //Waiting for the next run
        printf("Waiting for %d seconds...\n\n", time_interval);
        sleep(time_interval);
    }
    
    return 0;
}