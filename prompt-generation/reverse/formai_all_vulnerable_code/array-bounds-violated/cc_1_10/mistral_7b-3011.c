//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_STEPS 100

typedef struct {
    int seconds;
    char description[80];
} TimeEvent;

TimeEvent events[MAX_TIME_STEPS];
int current_time_step = 0;

void setup_events() {
    events[0].seconds = 0;
    strcpy(events[0].description, "Present");

    events[1].seconds = 10;
    strcpy(events[1].description, "You meet your future self");

    events[2].seconds = -5;
    strcpy(events[2].description, "You prevent an accident");
}

void travel_in_time(int num_seconds) {
    int next_time_step = current_time_step + num_seconds / 5; // travel 5 seconds at a time

    if (next_time_step < 0) { // if traveling back in time
        if (current_time_step > 0) {
            current_time_step--;
            printf("\nYou have traveled back in time by %d seconds.\n", -num_seconds);
        } else {
            printf("\nYou cannot travel back in time further.\n");
            return;
        }
    } else if (next_time_step > MAX_TIME_STEPS) { // if traveling too far in the future
        printf("\nYou cannot travel that far in the future.\n");
        return;
    }

    current_time_step = next_time_step;
    printf("\nYou have traveled %d seconds into the future.\n", num_seconds);
    printf("Current time: %d seconds, %s\n", events[current_time_step].seconds, events[current_time_step].description);
}

int main() {
    srand(time(NULL)); // seed random number generator with current time

    setup_events();

    int user_input;
    while (1) {
        printf("\nCurrent time: %d seconds, %s\n", events[current_time_step].seconds, events[current_time_step].description);
        printf("Enter number of seconds to travel: ");
        scanf("%d", &user_input);

        if (user_input == 0) {
            break;
        }

        travel_in_time(user_input);
    }

    printf("\nEnd of simulation.\n");

    return 0;
}