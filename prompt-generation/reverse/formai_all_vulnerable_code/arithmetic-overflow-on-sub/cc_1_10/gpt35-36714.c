//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <time.h>

#define URL "https://example.com"
#define TIMEOUT_SECS 5

int main()
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT_SECS);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        double total_time;
        struct timespec start, end;
        clock_gettime(CLOCK_REALTIME, &start);

        res = curl_easy_perform(curl);

        clock_gettime(CLOCK_REALTIME, &end);
        total_time = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec) / 1000000000.0);

        if(res == CURLE_OK)
        {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code == 200)
            {
                printf("Congrats! Website '%s' is up and running. Response time: %.3f seconds\n", URL, total_time);
            }
            else
            {
                printf("Uh oh! Website '%s' returned HTTP response code %ld. Response time: %.3f seconds\n", URL, response_code, total_time);
            }
        }
        else
        {
            printf("Oops! An error occurred while trying to access '%s': %s. Response time: %.3f seconds\n", URL, curl_easy_strerror(res), total_time);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}