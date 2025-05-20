//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define URL_SIZE 256 // maximum size of URL
#define WAIT_TIME 30 // number of seconds between checks
#define MAX_FAILURES 3 // number of consecutive failures before alert is sent

int main()
{
    char url[URL_SIZE]; // input URL
    bool status = true; // website status
    int failures = 0; // number of consecutive failures
    time_t last_checked = 0; // time of last check

    printf("Enter URL to monitor: ");
    scanf("%s", url);

    while (true) // loop indefinitely
    {
        time_t now = time(NULL); // get current time
        double seconds_since_last_checked = difftime(now, last_checked);

        if (seconds_since_last_checked >= WAIT_TIME)
        {
            // perform a check
            // in this example, we will assume the website is always up
            status = true;
            if (!status)
            {
                if (failures == MAX_FAILURES)
                {
                    // send alert to administrator
                    printf("Website is down! Alert sent to administrator.\n");
                    failures = 0; // reset failures
                }
                else
                {
                    failures++;
                }
            }
            else
            {
                failures = 0; // reset failures
            }
            last_checked = now; // update last checked time
        }
    }

    return 0; // program never reaches this point
}