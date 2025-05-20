//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <math.h>
#include <time.h>

/* Function to calculate the uptime percentage */
double calculateUptime(double upTime, double downTime)
{
    double total = upTime + downTime;
    double percent = (upTime / total) * 100;
    return percent;
}

/* Function to check website status and return 1 for up, 0 for down */
int checkWebsiteStatus(char *url)
{
    CURL *curl;
    CURLcode res;
 
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_cleanup(curl);
            return 1;
        } else {
            curl_easy_cleanup(curl);
            return 0;
        }
    }
    return 0;
}

/* Main function */
int main()
{
    char *website = "www.google.com";
    double upTime = 0, downTime = 0;
    time_t startTime, endTime;
    int status, iterations;

    printf("Starting website uptime monitor for %s...\n", website);

    iterations = 0; /* Counter for number of iterations */
    while(iterations < 10) /* Monitor website status for 10 iterations */
    {
        startTime = time(NULL); /* Record start time for this iteration */
        status = checkWebsiteStatus(website); /* Check website status */
        endTime = time(NULL); /* Record end time for this iteration */

        if(status == 1) /* Website is up */
        {
            upTime += difftime(endTime, startTime);
            printf("Website is up for %.2f seconds.\n", difftime(endTime, startTime));
        }
        else /* Website is down */
        {
            downTime += difftime(endTime, startTime);
            printf("Website is down for %.2f seconds.\n", difftime(endTime, startTime));
        }

        iterations++; /* Increment iteration counter */
        sleep(5); /* Wait for 5 seconds before checking website status again */
    }

    double uptimePercent = calculateUptime(upTime, downTime);
    printf("\nWebsite uptime for %s over the past 50 seconds is: %.2f%%\n", website, uptimePercent);

    return 0;
}