//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int year, month, day, hour, minute, second;
    struct tm time_struct;
    time_t current_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter your desired time and date:\n");
    printf("1. Year\n2. Month\n3. Day\n4. Hour\n5. Minute\n6. Second\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the year: ");
            scanf("%d", &year);
            break;
        case 2:
            printf("Enter the month: ");
            scanf("%d", &month);
            break;
        case 3:
            printf("Enter the day: ");
            scanf("%d", &day);
            break;
        case 4:
            printf("Enter the hour: ");
            scanf("%d", &hour);
            break;
        case 5:
            printf("Enter the minute: ");
            scanf("%d", &minute);
            break;
        case 6:
            printf("Enter the second: ");
            scanf("%d", &second);
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            exit(1);
    }

    time_struct.tm_year = year - 1900;
    time_struct.tm_mon = month - 1;
    time_struct.tm_mday = day;
    time_struct.tm_hour = hour;
    time_struct.tm_min = minute;
    time_struct.tm_sec = second;

    current_time = mktime(&time_struct);
    printf("Current time: %s", ctime(&current_time));

    return 0;
}