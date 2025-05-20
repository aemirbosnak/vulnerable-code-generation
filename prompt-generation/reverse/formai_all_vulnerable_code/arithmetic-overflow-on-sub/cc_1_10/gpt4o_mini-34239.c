//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_YEARS 10000
#define TIME_TRAVELER_NAME_LENGTH 30

typedef struct {
    char name[TIME_TRAVELER_NAME_LENGTH];
    int current_year;
    int destination_year;
} TimeTraveler;

void get_current_year() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Year: %d\n", tm.tm_year + 1900);
}

void input_traveler_info(TimeTraveler* traveler) {
    printf("Enter your time traveler's name: ");
    fgets(traveler->name, sizeof(traveler->name), stdin);
    traveler->name[strcspn(traveler->name, "\n")] = '\0'; // Remove trailing newline

    printf("Hello %s! Please enter the year you would like to travel to (from year 0 to %d): ", traveler->name, MAX_YEARS);
    scanf("%d", &(traveler->destination_year));

    // Update current year as current time for simulation
    time_t t = time(NULL);
    traveler->current_year = localtime(&t)->tm_year + 1900;
}

void time_travel(TimeTraveler traveler) {
    if (traveler.destination_year < 0 || traveler.destination_year > MAX_YEARS) {
        printf("Invalid year! Please select a year between 0 and %d.\n", MAX_YEARS);
        return;
    }

    printf("\n--- Welcome to Time Travel Simulator ---\n");
    printf("%s is traveling from %d to %d... \n", traveler.name, traveler.current_year, traveler.destination_year);
    
    printf("...Time traveling...\n");
    int time_difference = traveler.destination_year - traveler.current_year;

    // Animated time travel simulation
    for (int i = 1; i <= abs(time_difference); i++) {
        if (time_difference > 0) {
            printf("Traveling to the future: %d year(s) left...\n", abs(time_difference - i));
        } else {
            printf("Traveling to the past: %d year(s) left...\n", abs(time_difference + i));
        }
        sleep(1); // Simulate time passing
    }

    printf("You have arrived in the year %d!\n", traveler.destination_year);
}

void display_time_travel_info(TimeTraveler traveler) {
    printf("\nTime Traveler Info\n");
    printf("Traveler Name: %s\n", traveler.name);
    printf("Current Year: %d\n", traveler.current_year);
    printf("Destination Year: %d\n", traveler.destination_year);
}

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    get_current_year();

    TimeTraveler traveler;
    input_traveler_info(&traveler);
    display_time_travel_info(traveler);
    time_travel(traveler);

    printf("\nThanks for using the Time Travel Simulator! Safe travels!\n");
    return 0;
}