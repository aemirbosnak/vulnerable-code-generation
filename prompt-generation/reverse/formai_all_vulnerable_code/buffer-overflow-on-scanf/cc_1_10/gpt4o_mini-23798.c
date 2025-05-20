//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEAR 3000
#define MIN_YEAR 1900

void display_menu();
void time_travel(int year);
int calculate_time_difference(int year);
void surprise_event();

int main() {
    int year;
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Prepare yourself for the unknown... or maybe just a trip to the past!\n");

    while(1) {
        display_menu();
        printf("Enter the year you want to travel to (1900 - 3000, or -1 to exit): ");
        scanf("%d", &year);

        if (year == -1) {
            printf("Leaving the time travel portal...\n");
            break;
        } else if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("ALERT! Year out of range! Try again...\n");
            continue;
        }

        time_travel(year);
    }

    printf("Thank you for using the Time Travel Simulator! Stay curious...\n");
    return 0;
}

void display_menu() {
    printf("\n*** Time Travel Menu ***\n");
    printf("1. Travel to a Different Time!\n");
    printf("2. Receive a Surprise Event!\n");
    printf("********************************\n");
}

void time_travel(int year) {
    int current_year = 2023; // This can be dynamically fetched with time()
    int time_diff = calculate_time_difference(year);
    printf("Traveling %d years %s...\n", abs(time_diff), (time_diff > 0) ? "into the future!" : "into the past!");

    if (time_diff > 0) {
        printf("Welcome to the year %d...!\n", year);
        printf("Technology has advanced significantly, but so have the challenges!\n");
    } else {
        printf("You've arrived in the year %d...!\n", year);
        printf("History is alive, but beware - it's not always easy to navigate!\n");
    }

    surprise_event();
}

int calculate_time_difference(int year) {
    int current_year = 2023; // This can be dynamically fetched with time()
    return year - current_year;
}

void surprise_event() {
    const char *events[] = {
        "You discovered a hidden treasure!",
        "A sudden earthquake shakes the land!",
        "You meet a historical figure!",
        "Oops! Someone recognizes you from the future!",
        "A meteor shower lights up the night sky!",
        "You found a time capsule buried with secrets of the world!",
        "An alien ship lands nearby, and they need your help!",
        "You accidentally get involved in a historical battle!"
    };
    
    srand(time(NULL)); // Seed for random number generation
    int random_index = rand() % (sizeof(events) / sizeof(events[0]));
    
    printf("SURPRISE! %s\n", events[random_index]);
}