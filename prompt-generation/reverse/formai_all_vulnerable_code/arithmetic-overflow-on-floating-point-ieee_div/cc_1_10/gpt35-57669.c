//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define TEST_URL "https://speedtest.net/speedtest/random350x350.jpg"

static size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main()
{
    CURL *curl_handle;
    CURLcode res;
    double download_speed = 0;
    time_t start, end;
    bool success = false;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    if(curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, TEST_URL);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0L);

        time(&start);
        res = curl_easy_perform(curl_handle);
        time(&end);

        if(res == CURLE_OK)
        {
            double duration = difftime(end, start);
            double size = 350 * 350;
            download_speed = size / duration / 1024 / 1024;
            success = true;
        }

        curl_easy_cleanup(curl_handle);
    }

    curl_global_cleanup();

    if(success)
    {
        printf("Download speed: %.2f Mbps\n", download_speed);
    }
    else
    {
        printf("Failed to test download speed\n");
    }

    return 0;
}