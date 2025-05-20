//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define URL "https://example.com/"
#define TIMEOUT 5
#define INTERVAL 60

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    return size * nmemb;
}

int main(void)
{
    CURL *curl;
    CURLcode res;
    struct timeval start, end;
    double elapsed;

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

    while (1) {
        gettimeofday(&start, NULL);
        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return EXIT_FAILURE;
        } else {
            printf("Website %s is up (%.2f ms)\n", URL, elapsed);
        }

        sleep(INTERVAL);
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}