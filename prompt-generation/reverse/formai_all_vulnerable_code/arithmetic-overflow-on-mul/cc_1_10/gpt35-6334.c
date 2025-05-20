//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main() {
    // Set initial time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // Randomize time before the time machine
    srand(time(NULL));

    // Ask user for time travel input
    int year, month, day;
    printf("Welcome to the Time Machine Simulator\n\n");
    printf("Enter a date to travel to (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &year, &month, &day);

    // Convert input into a time value
    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900; // Year since 1900
    travel_time.tm_mon = month - 1; // Month from 0 to 11
    travel_time.tm_mday = day;

    // Subtract current time from travel time
    double diff = difftime(mktime(&travel_time), mktime(current_time));

    // Determine if time travel is possible
    bool is_possible = fabs(diff) <= 60*60*24*365*100; // Within 100 years

    if (is_possible) {
        // Print time travel details
        printf("\nPreparing to travel to %d-%02d-%02d...\n", year, month, day);
        printf("Time machine initiated...\n\n");
        printf("3... 2... 1...\n\n");
        printf("POOF! You have arrived on %d-%02d-%02d\n\n", year, month, day);

        // Simulate some events from the past
        int random_events = rand() % 5;
        switch (random_events) {
            case 0:
                printf("You witness the construction of the Great Pyramid of Giza.\n");
                break;
            case 1:
                printf("You meet Leonardo da Vinci and discuss his inventions.\n");
                break;
            case 2:
                printf("You attend Shakespeare's premiere of Hamlet.\n");
                break;
            case 3:
                printf("You witness the fall of the Berlin Wall.\n");
                break;
            case 4:
                printf("You witness Neil Armstrong's first steps on the moon.\n");
                break;
        }
    } else {
        // Print error message
        printf("\nSorry, time travel to %d-%02d-%02d is not possible with our current technology.\n", year, month, day);
    }

    return 0;
}