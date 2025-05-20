//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *current_time_info;
    int choice, year, month, day, hour, minute, second;
    char buffer[20];

    // Get current time
    time(&current_time);
    current_time_info = localtime(&current_time);

    printf("Welcome to the Time Travel Simulator!\n\n");

    // Simulation loop
    while (1) {
        printf("Current Date and Time: %s\n", asctime(current_time_info));
        printf("Where would you like to travel?\n");
        printf("1. Past\n");
        printf("2. Future\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            printf("Enter the desired date and time to travel to (yyyy-mm-dd hh:mm:ss): ");
            scanf("%s", buffer);
            sscanf(buffer, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

            // Create time structure for desired time
            struct tm desired_time_info = {0};
            desired_time_info.tm_year = year - 1900;
            desired_time_info.tm_mon = month - 1;
            desired_time_info.tm_mday = day;
            desired_time_info.tm_hour = hour;
            desired_time_info.tm_min = minute;
            desired_time_info.tm_sec = second;

            // Get time in seconds for desired time
            time_t desired_time = mktime(&desired_time_info);
            if (desired_time == -1) {
                printf("Invalid date and time entered.\n\n");
            } else if (desired_time > current_time) {
                printf("You cannot travel to the future using this program.\n\n");
            } else {
                // Set current time to desired time
                current_time = desired_time;
                current_time_info = localtime(&current_time);
            }
        } else if (choice == 2) {
            printf("Enter the desired date and time to travel to (yyyy-mm-dd hh:mm:ss): ");
            scanf("%s", buffer);
            sscanf(buffer, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

            // Create time structure for desired time
            struct tm desired_time_info = {0};
            desired_time_info.tm_year = year - 1900;
            desired_time_info.tm_mon = month - 1;
            desired_time_info.tm_mday = day;
            desired_time_info.tm_hour = hour;
            desired_time_info.tm_min = minute;
            desired_time_info.tm_sec = second;

            // Get time in seconds for desired time
            time_t desired_time = mktime(&desired_time_info);
            if (desired_time == -1) {
                printf("Invalid date and time entered.\n\n");
            } else if (desired_time < current_time) {
                printf("You cannot travel to the past using this program.\n\n");
            } else {
                // Set current time to desired time
                current_time = desired_time;
                current_time_info = localtime(&current_time);
            }
        } else if (choice == 3) {
            printf("Exiting time travel simulator...\n");
            exit(0);
        } else {
            printf("Invalid choice. Please choose again.\n\n");
        }
    }

    return 0;
}