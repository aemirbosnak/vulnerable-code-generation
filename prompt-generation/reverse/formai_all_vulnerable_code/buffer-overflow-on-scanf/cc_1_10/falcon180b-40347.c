//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100
#define MAX_TIME_TRAVELLERS 10
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE 1

struct time_travel_record {
    int traveller_id;
    int destination_time;
    int result;
};

int main() {
    int num_time_travels, num_time_travellers, i, j, choice, result;
    struct time_travel_record time_travel_records[MAX_TIME_TRAVELS];
    char names[MAX_TIME_TRAVELLERS][20];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter the number of time travellers: ");
    scanf("%d", &num_time_travellers);

    for (i = 0; i < num_time_travellers; i++) {
        printf("Enter the name of time traveller %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    for (i = 0; i < num_time_travels; i++) {
        printf("Enter the details for time travel %d:\n", i + 1);
        printf("Enter the time traveller ID: ");
        scanf("%d", &time_travel_records[i].traveller_id);
        printf("Enter the destination time (in seconds since 1970-01-01 00:00:00): ");
        scanf("%d", &time_travel_records[i].destination_time);
    }

    printf("Time Travel Simulation Results:\n");
    for (i = 0; i < num_time_travels; i++) {
        result = TIME_TRAVEL_FAILURE;
        for (j = 0; j < num_time_travellers; j++) {
            if (time_travel_records[i].traveller_id == j + 1) {
                result = TIME_TRAVEL_SUCCESS;
                break;
            }
        }
        printf("Time travel %d by %s: %s\n", i + 1, names[time_travel_records[i].traveller_id - 1], result == TIME_TRAVEL_SUCCESS? "Success" : "Failure");
    }

    return 0;
}