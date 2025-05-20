//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 100

struct event {
    time_t timestamp;
    char description[MAX_EVENT_LENGTH];
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    char input[MAX_EVENT_LENGTH];
    FILE *fp;

    srand(time(NULL));

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the name of the file containing the timeline:\n");
    scanf("%s", input);

    fp = fopen(input, "r");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %ld\n", input, &events[num_events].timestamp) == 2) {
        strncpy(events[num_events].description, input, MAX_EVENT_LENGTH);
        num_events++;
        if (num_events >= MAX_EVENTS) {
            printf("Error: too many events.\n");
            exit(1);
        }
    }

    fclose(fp);

    printf("The timeline has been loaded.\n");

    int choice;
    do {
        printf("Please choose an option:\n");
        printf("1. View timeline\n");
        printf("2. Travel back in time\n");
        printf("3. Travel forward in time\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Timeline:\n");
                for (int i = 0; i < num_events; i++) {
                    printf("%ld - %s\n", events[i].timestamp, events[i].description);
                }
                break;
            case 2:
                printf("Enter the number of years you want to travel back in time:\n");
                int years;
                scanf("%d", &years);
                time_t new_timestamp = events[num_events - 1].timestamp - (years * 365 * 24 * 60 * 60);
                if (new_timestamp < 0) {
                    printf("Error: cannot travel back in time before the first event.\n");
                } else {
                    for (int i = num_events - 1; i >= 0; i--) {
                        if (events[i].timestamp >= new_timestamp) {
                            printf("You have traveled back in time to %s.\n", events[i].description);
                            break;
                        }
                    }
                }
                break;
            case 3:
                printf("Enter the number of years you want to travel forward in time:\n");
                int years1;
                scanf("%d", &years1);
                time_t new_timestamp1 = events[num_events - 1].timestamp + (years1 * 365 * 24 * 60 * 60);
                if (new_timestamp1 > time(NULL)) {
                    printf("Error: cannot travel forward in time beyond the present.\n");
                } else {
                    for (int i = num_events - 1; i >= 0; i--) {
                        if (events[i].timestamp <= new_timestamp1) {
                            printf("You have traveled forward in time to %s.\n", events[i].description);
                            break;
                        }
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}