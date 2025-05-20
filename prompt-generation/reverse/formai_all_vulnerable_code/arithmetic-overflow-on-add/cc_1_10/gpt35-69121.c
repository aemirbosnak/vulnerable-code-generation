//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool check_website_status(char* website_url) {
    // Here we can assume that website url is valid and it always returns a boolean value based on the website status.

    // Generate random number between 0 and 100.
    int random = rand() % 101;

    // If the random number is greater than or equal to 50, then the website is up and running.
    if (random >= 50) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    // Set the website url to monitor.
    char website_url[] = "https://www.example.com";

    // Set the interval to check website status in seconds.
    int interval = 60;

    // Set the start time for the website uptime monitor.
    time_t start_time = time(NULL);

    // Set the end time for the website uptime monitor.
    time_t end_time = start_time + (60 * 60 * 24 * 365);

    // Loop until the end time is reached.
    while (time(NULL) <= end_time) {
        // Check the website status.
        bool website_status = check_website_status(website_url);

        // If website is up, then print the message along with the current time.
        if (website_status == true) {
            printf("Website is up and running! Checked at %s", ctime(&start_time));
        }
        // If website is down, then print the message along with the current time.
        else {
            printf("Website is down! Checked at %s", ctime(&start_time));
        }

        // Delay for the specified interval.
        sleep(interval);
    }

    return 0;
}