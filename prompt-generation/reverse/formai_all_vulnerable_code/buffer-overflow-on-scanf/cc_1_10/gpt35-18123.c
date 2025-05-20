//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
// Medieval Baggage Handling Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare variables
int num_of_luggage, num_of_workers;
int arrival_time[100], process_time[100], departure_time[100];
int worker_busy[10] = {0}, luggage_handled[100] = {0};

// Function to generate random luggage and process time
void generate_luggage_time() {
    srand(time(0));
    for(int i=0; i<num_of_luggage; i++) {
        arrival_time[i] = rand()%60;    // Random arrival time from 0 to 59 minutes
        process_time[i] = rand()%10+1;  // Random process time from 1 to 10 minutes
    }
}

int main() {
    // Get input from user
    printf("Medieval Baggage Handling Simulation Program\n");
    printf("Enter the number of luggage: ");
    scanf("%d", &num_of_luggage);
    printf("Enter the number of workers: ");
    scanf("%d", &num_of_workers);
    
    // Generate random luggage and process time
    generate_luggage_time();
    
    // Simulation starts
    printf("Simulation starts:\n");
    for(int i=0; i<num_of_luggage; i++) {
        int min_busy_time = 1000, min_busy_worker = 0;
        // Find the worker with minimum busy time
        for(int j=0; j<num_of_workers; j++) {
            if(worker_busy[j] < min_busy_time) {
                min_busy_time = worker_busy[j];
                min_busy_worker = j;
            }
        }
        // Assign luggage to the worker with minimum busy time
        if(arrival_time[i] >= min_busy_time) {
            departure_time[i] = arrival_time[i] + process_time[i];
            worker_busy[min_busy_worker] = departure_time[i];
        }
        else {
            departure_time[i] = min_busy_time + process_time[i];
            worker_busy[min_busy_worker] = departure_time[i];
        }
        luggage_handled[i] = 1;
        
        // Print the details of the luggage
        printf("Luggage %d assigned to worker %d at time %d\n", i+1, min_busy_worker+1, departure_time[i]);
    }
    
    // Display the summary
    printf("Simulation ends\n");
    printf("Summary:\n");
    int total_time = 0;
    for(int i=0; i<num_of_luggage; i++) {
        if(luggage_handled[i]) {
            printf("Luggage %d handled by worker at time %d\n", i+1, departure_time[i]);
            total_time += departure_time[i] - arrival_time[i];
        }
        else {
            printf("Luggage %d not handled\n", i+1);
        }
    }
    printf("Average processing time per luggage: %.2f minutes\n", (float)total_time/num_of_luggage);
    
    return 0;
}