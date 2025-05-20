//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    time_t present_time, future_time;
    struct tm *timeinfo;

    time(&present_time); // present time

    timeinfo = localtime(&present_time);

    printf("The present time is: %s", asctime(timeinfo)); 

    // Future time 

    timeinfo->tm_year += 50; // Add 50 years to present year 

    future_time = mktime(timeinfo);

    // Set the system time to future_time

    if (settimeofday(&future_time, NULL) != 0) {
        printf("Error setting time.\n");
        exit(1);
    }

    printf("The time machine has been activated!\n");
    printf("Traveling 50 years into the future...\n");

    // pause for 3 seconds to simulate time travel
    sleep(3);

    // Present time after time travel 
    time(&present_time); 

    timeinfo = localtime(&present_time);

    printf("\nThe new present time is: %s", asctime(timeinfo));

    // Reset system time back to present time

    if (settimeofday(&present_time, NULL) != 0) {
        printf("Error setting time.\n");
        exit(1);
    }

    printf("\nThe time machine has returned you to the present!\n");

    return 0;
}