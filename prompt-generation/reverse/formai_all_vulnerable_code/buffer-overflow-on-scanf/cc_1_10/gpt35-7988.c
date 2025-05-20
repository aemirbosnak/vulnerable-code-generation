//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed based on current time
    
    printf("Welcome to the Time Travel Simulator!\n");
    
    int current_year = 2022; // set current year as 2022
    int target_year = 0;
    
    // get target year from user input
    printf("Enter the year you want to travel to:\n");
    scanf("%d", &target_year);
    
    // time travel logic
    if (target_year > current_year) {
        printf("Sorry, time travel to the future is not possible.\n");
        return 0;
    } else if (target_year < 1900) {
        printf("Sorry, time travel to the past before 1900 is not possible.\n");
        return 0;
    } else if (target_year == 2022) {
        printf("You're already here, no need for time travel!\n");
        return 0;
    }
    
    int years_travelled = abs(current_year - target_year); // calculate years of travel
    printf("You will be travelling %d years into the %s.\n", years_travelled, target_year < current_year ? "past" : "future");
    
    printf("Starting time travel sequence...\n");
    printf("3...\n");
    sleep(1); // wait for 1 second
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Blast off!\n");
    
    for (int i = 0; i < years_travelled; i++) {
        // simulate time passing by generating random events
        int event = rand() % 3; // 0 = nothing happened, 1 = good event, 2 = bad event
        
        if (event == 1) {
            printf("You met your great-great-great-grandfather and he gave you a treasure map!\n");
        } else if (event == 2) {
            printf("You accidentally stepped on a butterfly and changed the course of history!\n");
        }
        
        printf("Year %d...\n", current_year + (i * (target_year < current_year ? -1 : 1))); // print current year after each event
        sleep(1); // wait for 1 second
    }
    
    printf("Arrived at the destination year %d!\n", target_year);
    
    return 0;
}