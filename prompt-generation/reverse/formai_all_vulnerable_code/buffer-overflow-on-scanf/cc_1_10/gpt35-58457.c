//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    time_t current_time;
    struct tm * time_info;
    char datetime[50];

    // random number generator
    srand((unsigned) time(&current_time));

    // time traveler prompt
    printf("Welcome to the Time Travel Simulator\n");
    printf("Enter a year between 1900-2021 you want to travel to: ");

    // user input
    int year = 0;
    scanf("%d", &year);

    // validate year range
    if (year < 1900 || year > 2021) {
        printf("Invalid year! Exiting...\n");
        exit(0);
    }

    // simulate time travel
    printf("Setting time coordinates for year %d...\n\n", year);

    // wait for 3 seconds
    sleep(3);

    // randomly generate time travel date and time
    int month = (rand() % 12) + 1;
    int day = (rand() % 30) + 1;
    int hour = (rand() % 24);
    int minute = (rand() % 60);

    // set time travel date and time
    time_info = localtime(&current_time);
    time_info->tm_year = year - 1900;
    time_info->tm_mon = month - 1;
    time_info->tm_mday = day;
    time_info->tm_hour = hour;
    time_info->tm_min = minute;
    time_info->tm_sec = 0;

    // convert time to string format
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", time_info);

    // output time travel destination
    printf("You have successfully traveled to the year %d!\n", year);
    printf("Time coordinates: %s\n", datetime);

    // wait for 2 seconds
    sleep(2);

    // time travel simulation
    printf("Do you want to experience time travel simulation? [Y/N]: ");
    char response;
    scanf(" %c", &response); // do not forget the space before %c!

    if (response == 'Y' || response == 'y') {
        // travel 1 year per 1 second
        printf("Initiating time travel simulation...\n\n");
        for (int i = 1; i <= year - 1900; i++) {
            printf("%d years have passed.\n", i);
            sleep(1);
        }
        printf("\nYou have arrived at year %d!\n", year);
    } else {
        printf("Maybe next time then. Have a nice day!\n");
    }

    return 0;
}