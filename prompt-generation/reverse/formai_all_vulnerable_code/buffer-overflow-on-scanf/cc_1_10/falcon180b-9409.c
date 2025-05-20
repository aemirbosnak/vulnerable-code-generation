//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10
#define MAX_TIME_DELTA 1000

struct time_travel {
    time_t timestamp;
    int delta;
};

int main() {
    struct time_travel time_travels[MAX_TIME_TRAVELS];
    int num_time_travels = 0;
    time_t current_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel back in time by entering a negative number of seconds,\n");
    printf("or forward in time by entering a positive number of seconds.\n");

    while(1) {
        printf("Enter the number of seconds you want to travel (0 to quit): ");
        scanf("%d", &time_travels[num_time_travels].delta);

        if(time_travels[num_time_travels].delta == 0) {
            break;
        }

        if(time_travels[num_time_travels].delta > MAX_TIME_DELTA) {
            printf("Error: Time travel distance too far.\n");
            continue;
        }

        time(&current_time);
        time_travels[num_time_travels].timestamp = current_time + time_travels[num_time_travels].delta;
        num_time_travels++;

        if(num_time_travels >= MAX_TIME_TRAVELS) {
            printf("Error: Too many time travels.\n");
            continue;
        }
    }

    printf("\nYour time travel itinerary:\n");
    for(int i=0; i<num_time_travels; i++) {
        printf("%d seconds into the %s at %s\n",
               time_travels[i].delta,
               time_travels[i].delta < 0? "past" : "future",
               ctime(&time_travels[i].timestamp));
    }

    return 0;
}