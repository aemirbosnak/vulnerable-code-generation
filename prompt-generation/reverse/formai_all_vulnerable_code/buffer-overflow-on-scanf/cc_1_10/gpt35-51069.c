//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void travel(int start, int end, int step)
{
    // Check if the end was reached
    if (start >= end) {
        printf("You have arrived at your destination in the year %d\n", start);
        return;
    }
    
    // Move to the next year
    start += step;
    
    // Print the current year
    printf("You are now in the year %d\n", start);
    
    // Delay for 1 second
    sleep(1);
    
    // Recursively call the travel function
    travel(start, end, step);
}

int main()
{
    int start_year, end_year;
    
    // Prompt user for starting and ending year
    printf("Enter the year you wish to start: ");
    scanf("%d", &start_year);
    printf("Enter the year you wish to end: ");
    scanf("%d", &end_year);
    
    // Confirm user input
    printf("Starting year: %d\n", start_year);
    printf("Ending year: %d\n", end_year);
    
    // Define step as positive or negative
    int step = 1;
    if (start_year > end_year) {
        step = -1;
    }
    
    // Begin time travel simulation
    printf("Initiating time travel sequence...\n");
    travel(start_year, end_year, step);
    
    return 0;
}