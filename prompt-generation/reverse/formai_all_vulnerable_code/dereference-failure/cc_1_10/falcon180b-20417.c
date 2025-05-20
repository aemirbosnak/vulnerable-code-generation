//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 512
#define TIMEOUT 10
#define INTERVAL 60

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[(size_t)size*nmemb] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    char url[MAX_URL_SIZE];
    char response[MAX_URL_SIZE];
    FILE* logfile;

    // Open log file
    logfile = fopen("website_uptime.log", "w");

    // Check if log file was opened successfully
    if (logfile == NULL)
    {
        printf("Failed to open log file.\n");
        exit(1);
    }

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    // Check if curl was initialized successfully
    if (curl == NULL)
    {
        printf("Failed to initialize curl.\n");
        exit(1);
    }

    // Set curl options
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

    // Perform first request
    res = curl_easy_perform(curl);

    // Check if first request was successful
    if (res!= CURLE_OK)
    {
        fprintf(logfile, "Initial request failed: %s\n", curl_easy_strerror(res));
        fclose(logfile);
        exit(1);
    }

    // Loop and perform requests at specified interval
    while (1)
    {
        // Sleep for specified interval
        sleep(INTERVAL);

        // Perform request
        res = curl_easy_perform(curl);

        // Check if request was successful
        if (res!= CURLE_OK)
        {
            fprintf(logfile, "Request failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            fprintf(logfile, "Request successful.\n");
        }
    }

    // Cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    fclose(logfile);

    return 0;
}