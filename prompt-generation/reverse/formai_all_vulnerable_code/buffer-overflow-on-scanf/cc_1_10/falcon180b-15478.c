//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TIME_TRAVELS 100
#define MAX_TIME_TRAVEL_LENGTH 100

typedef struct {
    int start_time;
    int end_time;
    int duration;
    int result;
} time_travel;

void print_time(int time) {
    int hours = time / 60;
    int minutes = time % 60;

    if (hours < 10) {
        printf("0");
    }

    printf("%d:", hours);

    if (minutes < 10) {
        printf("0");
    }

    printf("%d", minutes);
}

int main() {
    srand(time(NULL));

    int num_time_travels;
    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    time_travel time_travels[MAX_TIME_TRAVELS];

    for (int i = 0; i < num_time_travels; i++) {
        time_travels[i].start_time = rand() % 24 * 60 + rand() % 60;
        time_travels[i].end_time = rand() % 24 * 60 + rand() % 60;
        time_travels[i].duration = abs(time_travels[i].end_time - time_travels[i].start_time);
    }

    int max_time_travel_length = 0;

    for (int i = 0; i < num_time_travels; i++) {
        if (time_travels[i].duration > max_time_travel_length) {
            max_time_travel_length = time_travels[i].duration;
        }
    }

    int time_travel_length = rand() % max_time_travel_length + 1;

    int start_index = rand() % num_time_travels;
    int end_index = (start_index + time_travel_length - 1) % num_time_travels;

    if (end_index < start_index) {
        end_index += num_time_travels;
    }

    for (int i = start_index; i <= end_index; i++) {
        if (time_travels[i].start_time > time_travels[i].end_time) {
            int temp_start_time = time_travels[i].start_time;
            time_travels[i].start_time = time_travels[i].end_time;
            time_travels[i].end_time = temp_start_time;
        }

        if (time_travels[i].start_time >= time_travels[start_index].start_time &&
            time_travels[i].start_time <= time_travels[start_index].start_time + time_travel_length - 1) {
            time_travels[i].result = 1;
        } else {
            time_travels[i].result = 0;
        }
    }

    printf("\nTime Travel Simulation\n");

    for (int i = start_index; i <= end_index; i++) {
        printf("Time Travel %d:\n", i + 1);
        printf("Start Time: ");
        print_time(time_travels[i].start_time);
        printf("End Time: ");
        print_time(time_travels[i].end_time);

        if (time_travels[i].result == 1) {
            printf("Result: Successful\n");
        } else {
            printf("Result: Failed\n");
        }
    }

    return 0;
}