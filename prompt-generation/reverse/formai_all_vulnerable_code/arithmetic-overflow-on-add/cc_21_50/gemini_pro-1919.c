//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program simulates time travel by generating random dates and times.
// The user can specify the range of dates and times to be generated, and the number of events to be generated.

int main() {
    // Get the user's input.
    int startYear, startMonth, startDay, startHour, startMinute;
    int endYear, endMonth, endDay, endHour, endMinute;
    int numEvents;
    printf("Enter the start year: ");
    scanf("%d", &startYear);
    printf("Enter the start month: ");
    scanf("%d", &startMonth);
    printf("Enter the start day: ");
    scanf("%d", &startDay);
    printf("Enter the start hour: ");
    scanf("%d", &startHour);
    printf("Enter the start minute: ");
    scanf("%d", &startMinute);
    printf("Enter the end year: ");
    scanf("%d", &endYear);
    printf("Enter the end month: ");
    scanf("%d", &endMonth);
    printf("Enter the end day: ");
    scanf("%d", &endDay);
    printf("Enter the end hour: ");
    scanf("%d", &endHour);
    printf("Enter the end minute: ");
    scanf("%d", &endMinute);
    printf("Enter the number of events to be generated: ");
    scanf("%d", &numEvents);

    // Check if the user's input is valid.
    if (startYear<1970 || startYear>2030 || startMonth<1 || startMonth>12 || startDay<1 || startDay>31 || startHour<0 || startHour>23 || startMinute<0 || startMinute>59 || endYear<1970 || endYear>2030 || endMonth<1 || endMonth>12 || endDay<1 || endDay>31 || endHour<0 || endHour>23 || endMinute<0 || endMinute>59 || numEvents<1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Set the random seed.
    srand((unsigned) time(NULL));

    // Generate the events.
    for (int i = 0; i < numEvents; i++) {
        // Generate a random date and time.
        int year = (rand() % (endYear - startYear + 1)) + startYear;
        int month = (rand() % (endMonth - startMonth + 1)) + startMonth;
        int day = (rand() % (endDay - startDay + 1)) + startDay;
        int hour = (rand() % (endHour - startHour + 1)) + startHour;
        int minute = (rand() % (endMinute - startMinute + 1)) + startMinute;

        // Print the event.
        printf("%d-%02d-%02d %02d:%02d\n", year, month, day, hour, minute);
    }

    return 0;
}