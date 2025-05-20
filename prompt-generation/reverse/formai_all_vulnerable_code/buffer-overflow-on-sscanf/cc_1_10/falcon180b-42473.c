//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIMESTAMPS 100

struct timestamp {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

int main() {
    struct timestamp timestamps[MAX_TIMESTAMPS];
    int num_timestamps = 0;
    int current_timestamp_index = 0;
    char input[80];
    int year, month, day, hour, minute, second;
    int choice;

    do {
        printf("Enter a date and time (YYYY-MM-DD HH:MM:SS): ");
        fgets(input, 80, stdin);
        sscanf(input, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

        if (num_timestamps == MAX_TIMESTAMPS) {
            printf("Error: Maximum number of timestamps reached.\n");
        } else {
            timestamps[num_timestamps].year = year;
            timestamps[num_timestamps].month = month;
            timestamps[num_timestamps].day = day;
            timestamps[num_timestamps].hour = hour;
            timestamps[num_timestamps].minute = minute;
            timestamps[num_timestamps].second = second;
            num_timestamps++;
        }

        printf("Current timestamps:\n");
        for (int i = 0; i < num_timestamps; i++) {
            printf("Timestamp %d: %d-%d-%d %d:%d:%d\n", i+1, timestamps[i].year, timestamps[i].month, timestamps[i].day, timestamps[i].hour, timestamps[i].minute, timestamps[i].second);
        }

        printf("Enter 1 to travel to a previous timestamp, 2 to travel to a future timestamp, or 0 to exit:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (current_timestamp_index > 0) {
                current_timestamp_index--;
            } else {
                printf("Error: Cannot travel to a previous timestamp.\n");
            }
        } else if (choice == 2) {
            if (current_timestamp_index < num_timestamps - 1) {
                current_timestamp_index++;
            } else {
                printf("Error: Cannot travel to a future timestamp.\n");
            }
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }

    } while (choice!= 0);

    return 0;
}