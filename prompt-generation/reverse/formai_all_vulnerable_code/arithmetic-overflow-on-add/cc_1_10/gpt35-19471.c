//FormAI DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Function to be executed after specified time
void taskOne()
{
    printf("This is task one executing after specified time\n");
}

// Function to be executed after another specified time
void taskTwo()
{
    printf("This is task two executing after another specified time\n");
}

// Function to be executed after a third specified time
void taskThree()
{
    printf("This is task three executing after a third specified time\n");
}

int main() 
{
    // Define the time intervals for each task
    int interval1 = 5, interval2 = 10, interval3 = 15;

    // Define the start time for the scheduler
    time_t start_time = time(NULL);

    // Define the initial time that each task should execute, relative to the start_time
    time_t task1_start = start_time + interval1;
    time_t task2_start = start_time + interval2;
    time_t task3_start = start_time + interval3;

    // Infinite loop to continuously check the time and execute the appropriate function
    while(1) 
    {
        // Get the current time
        time_t current_time = time(NULL);

        // Check if it's time to execute task one
        if(current_time >= task1_start) 
        {
            taskOne();
            // Update the task start time to be the next interval
            task1_start += interval1;
        }

        // Check if it's time to execute task two
        if(current_time >= task2_start) 
        {
            taskTwo();
            // Update the task start time to be the next interval
            task2_start += interval2;
        }

        // Check if it's time to execute task three
        if(current_time >= task3_start) 
        {
            taskThree();
            // Update the task start time to be the next interval
            task3_start += interval3;
        }

        // Sleep for a second before checking the time again
        sleep(1);
    }

    return 0;
}