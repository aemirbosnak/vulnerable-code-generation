//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    int year, month, day, hour, minute, second;
    char day_of_week[3];

    printf("Enter the year (1900-2023): ");
    scanf("%d", &year);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printf("Enter the day (1-31): ");
    scanf("%d", &day);

    printf("Enter the hour (0-23): ");
    scanf("%d", &hour);

    printf("Enter the minute (0-59): ");
    scanf("%d", &minute);

    printf("Enter the second (0-59): ");
    scanf("%d", &second);

    // Calculate the day of the week
    switch (month) {
        case 1:
            day_of_week[0] = 'M';
            break;
        case 2:
            day_of_week[0] = 'T';
            break;
        case 3:
            day_of_week[0] = 'W';
            break;
        case 4:
            day_of_week[0] = 'T';
            break;
        case 5:
            day_of_week[0] = 'F';
            break;
        case 6:
            day_of_week[0] = 'S';
            break;
        case 7:
            day_of_week[0] = 'M';
            break;
        case 8:
            day_of_week[0] = 'T';
            break;
        case 9:
            day_of_week[0] = 'W';
            break;
        case 10:
            day_of_week[0] = 'T';
            break;
        case 11:
            day_of_week[0] = 'F';
            break;
        case 12:
            day_of_week[0] = 'S';
            break;
    }

    // Print the time travel information
    printf("Time Travel Simulation:\n");
    printf("Year: %d\n", year);
    printf("Month: %d\n", month);
    printf("Day: %d\n", day);
    printf("Hour: %d\n", hour);
    printf("Minute: %d\n", minute);
    printf("Second: %d\n", second);
    printf("Day of the week: %c\n", day_of_week[0]);

    return 0;
}