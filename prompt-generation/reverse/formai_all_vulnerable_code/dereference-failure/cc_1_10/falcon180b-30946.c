//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define SITE_TO_MONITOR "https://example.com"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[(size_t)size*nmemb] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    char* response;
    long response_code;
    struct tm* current_time;
    time_t now;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, SITE_TO_MONITOR);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");
        curl_easy_perform(curl);

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        printf("Response code: %ld\n", response_code);

        if(response_code == 200)
        {
            current_time = localtime(&now);
            printf("Current time: %s\n", asctime(current_time));
        }
        else
        {
            printf("Website is down!\n");
        }

        free(response);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}