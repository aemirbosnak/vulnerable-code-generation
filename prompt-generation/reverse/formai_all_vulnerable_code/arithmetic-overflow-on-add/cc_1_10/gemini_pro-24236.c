//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years you can travel
#define MAX_YEARS 100

// Create a struct to store the current time
typedef struct {
    int year;
    int month;
    int day;
} Time;

// Create a function to generate a random time
Time generate_random_time() {
    Time time;
    
    // Generate a random year
    time.year = rand() % MAX_YEARS + 1;
    
    // Generate a random month
    time.month = rand() % 12 + 1;
    
    // Generate a random day
    time.day = rand() % 31 + 1;
    
    return time;
}

// Create a function to print a time
void print_time(Time time) {
    printf("The current time is: %d-%d-%d\n", time.year, time.month, time.day);
}

// Create a function to travel through time
void travel_through_time(Time *time, int years) {
    // Add the number of years to the current year
    time->year += years;
    
    // If the year is greater than the maximum year, set it to the maximum year
    if (time->year > MAX_YEARS) {
        time->year = MAX_YEARS;
    }
    
    // If the year is less than 1, set it to 1
    if (time->year < 1) {
        time->year = 1;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random time
    Time time = generate_random_time();
    
    // Print the current time
    print_time(time);
    
    // Get the number of years to travel
    int years;
    printf("Enter the number of years to travel: ");
    scanf("%d", &years);
    
    // Travel through time
    travel_through_time(&time, years);
    
    // Print the new time
    print_time(time);
    
    return 0;
}