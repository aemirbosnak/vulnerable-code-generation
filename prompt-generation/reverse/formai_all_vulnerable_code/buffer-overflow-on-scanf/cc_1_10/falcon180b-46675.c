//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVEL_YEARS 100
#define TIME_TRAVEL_SPEED_LIMIT 88
#define TIME_TRAVEL_DISTANCE_LIMIT 1.21

typedef struct {
    int year;
    double position;
} TimeTravelData;

void timeTravel(TimeTravelData* data) {
    int currentYear = 2022;
    int destinationYear = data->year;
    double distance = fabs(currentYear - destinationYear);

    if (distance > TIME_TRAVEL_DISTANCE_LIMIT) {
        printf("Error: Destination year is too far away.\n");
        return;
    }

    if (destinationYear < currentYear) {
        printf("Warning: Traveling to the past.\n");
    }

    printf("Starting time travel to the year %d...\n", destinationYear);
    for (int i = currentYear; i!= destinationYear; i++) {
        if (i < destinationYear) {
            printf("Traveling back in time to the year %d...\n", i);
        } else {
            printf("Traveling forward in time to the year %d...\n", i);
        }
        double speed = (double)i / (double)MAX_TIME_TRAVEL_YEARS;
        double allowedSpeed = TIME_TRAVEL_SPEED_LIMIT - ((double)fabs(destinationYear - currentYear) / (double)distance);
        if (speed > allowedSpeed) {
            printf("Error: Time travel speed limit exceeded. Adjusting speed.\n");
            speed = allowedSpeed;
        }
        double time = distance / speed;
        double seconds = 365.25 * 24 * 60 * 60 * time;
        printf("Time travel will take %.2f seconds.\n", seconds);
        sleep(1);
    }

    printf("Arriving at the year %d.\n", destinationYear);
}

int main() {
    TimeTravelData data;
    printf("Enter the destination year (between %d and %d): ", 2022, 2122);
    scanf("%d", &data.year);
    timeTravel(&data);
    return 0;
}