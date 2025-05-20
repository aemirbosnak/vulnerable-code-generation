//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // set initial time
    time_t t = time(NULL);

    // display current time
    printf("Starting simulation at %s", ctime(&t));

    // set time parameters
    struct tm futureTime = *localtime(&t);
    futureTime.tm_year = 2050 - 1900;
    futureTime.tm_mon = 0;
    futureTime.tm_mday = 1;
    futureTime.tm_hour = 0;
    futureTime.tm_min = 0;
    futureTime.tm_sec = 0;

    // simulate time travel to future
    printf("\nEntering time warp...\n");
    while (t < mktime(&futureTime))
    {
        t += 60;
        printf("Current time: %s", ctime(&t));
    }

    // set new time parameters for past
    struct tm pastTime = *localtime(&t);
    pastTime.tm_year = 1950 - 1900;
    pastTime.tm_mon = 0;
    pastTime.tm_mday = 1;
    pastTime.tm_hour = 0;
    pastTime.tm_min = 0;
    pastTime.tm_sec = 0;

    // simulate time travel to past
    printf("\nEntering time warp...\n");
    while (t > mktime(&pastTime))
    {
        t -= 60;
        printf("Current time: %s", ctime(&t));
    }

    // display final time
    printf("\nSimulation complete. Final time: %s", ctime(&t));

    return 0;
}