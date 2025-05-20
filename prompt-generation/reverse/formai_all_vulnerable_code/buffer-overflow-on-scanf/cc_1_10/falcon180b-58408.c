//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 10
#define TIME_TRAVEL_YEAR 100

struct time_travel {
    int year;
    int month;
    int day;
};

void time_travel(struct time_travel *travel, int num_travels) {
    for (int i = 0; i < num_travels; i++) {
        printf("Enter year for time travel %d: ", i+1);
        scanf("%d", &travel[i].year);
        if (travel[i].year < TIME_TRAVEL_YEAR) {
            printf("Error: Time travel before %d is not allowed.\n", TIME_TRAVEL_YEAR);
            exit(1);
        }
        printf("Enter month for time travel %d: ", i+1);
        scanf("%d", &travel[i].month);
        if (travel[i].month < 1 || travel[i].month > 12) {
            printf("Error: Invalid month.\n");
            exit(1);
        }
        printf("Enter day for time travel %d: ", i+1);
        scanf("%d", &travel[i].day);
        if (travel[i].day < 1 || travel[i].day > 31) {
            printf("Error: Invalid day.\n");
            exit(1);
        }
    }
}

void print_time_travel(struct time_travel *travel, int num_travels) {
    for (int i = 0; i < num_travels; i++) {
        printf("Time travel %d: %d-%d-%d\n", i+1, travel[i].year, travel[i].month, travel[i].day);
    }
}

int main() {
    int num_travels;
    printf("Enter number of time travels (max %d): ", MAX_TIME_TRAVEL);
    scanf("%d", &num_travels);
    if (num_travels > MAX_TIME_TRAVEL) {
        printf("Error: Too many time travels.\n");
        exit(1);
    }

    struct time_travel travel[MAX_TIME_TRAVEL];
    time_travel(travel, num_travels);
    print_time_travel(travel, num_travels);

    return 0;
}