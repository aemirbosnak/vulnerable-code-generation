//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

int main() {
    Time currentTime = {0, 0, 0, 0, 0, 0, 0};

    while (1) {
        int action;
        printf("What do you want to do?\n");
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Return to the present\n");
        scanf("%d", &action);

        if (action == 1) {
            int timeToTravel = 100; // Travel back in time by 100 years
            currentTime.year = currentTime.year - timeToTravel;
            currentTime.month = currentTime.month - timeToTravel / 12;
            currentTime.day = currentTime.day - timeToTravel / 365;
            currentTime.hour = currentTime.hour - timeToTravel / (24 * 60 * 60);
            currentTime.minute = currentTime.minute - timeToTravel / (60 * 60);
            currentTime.second = currentTime.second - timeToTravel / (60);
        } else if (action == 2) {
            int timeToTravel = 100; // Travel forward in time by 100 years
            currentTime.year = currentTime.year + timeToTravel;
            currentTime.month = currentTime.month + timeToTravel / 12;
            currentTime.day = currentTime.day + timeToTravel / 365;
            currentTime.hour = currentTime.hour + timeToTravel / (24 * 60 * 60);
            currentTime.minute = currentTime.minute + timeToTravel / (60 * 60);
            currentTime.second = currentTime.second + timeToTravel / (60);
        } else if (action == 3) {
            printf("Returning to the present...\n");
            break;
        } else {
            printf("Invalid action\n");
        }
    }

    printf("Current time: %02d:%02d:%02d %s %02d %s %02d\n",
           currentTime.hour, currentTime.minute, currentTime.second,
           currentTime.day < 10? "0" : "", currentTime.day,
           currentTime.month < 10? "0" : "", currentTime.month,
           currentTime.year < 10? "0" : "");

    return 0;
}