//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVELS 10
#define MAX_TIME_DELTA 10000

typedef struct {
    int id;
    time_t start_time;
    time_t end_time;
    time_t delta;
} time_travel;

void print_travel(time_travel travel) {
    printf("ID: %d\n", travel.id);
    printf("Start Time: %s\n", ctime(&travel.start_time));
    printf("End Time: %s\n", ctime(&travel.end_time));
    printf("Delta: %ld seconds\n", travel.delta);
}

int main() {
    time_travel travels[MAX_TIME_TRAVELS];
    int num_travels = 0;
    time_t current_time;
    int choice;

    do {
        printf("\nTime Travel Simulator\n");
        printf("1. Start New Time Travel\n");
        printf("2. View Time Travels\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_travels >= MAX_TIME_TRAVELS) {
                    printf("Maximum number of time travels reached.\n");
                } else {
                    printf("Enter ID for this time travel: ");
                    scanf("%d", &travels[num_travels].id);
                    time(&current_time);
                    travels[num_travels].start_time = current_time;
                    printf("Enter duration of time travel in seconds: ");
                    scanf("%ld", &travels[num_travels].delta);
                    travels[num_travels].end_time = current_time + travels[num_travels].delta;
                    num_travels++;
                }
                break;
            case 2:
                for (int i = 0; i < num_travels; i++) {
                    print_travel(travels[i]);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}