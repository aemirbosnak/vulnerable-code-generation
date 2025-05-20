//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define TIMEOUT_VALUE 30L
#define RETRY_COUNT 3
#define RETRY_INTERVAL 10L

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[(size_t)nmemb - 1] = '\0';
    return size * nmemb;
}

static int TimeoutCallback(CURL* curl, curl_off_t timeout)
{
    if (timeout == 0)
        return 0;

    return 1;
}

int main(int argc, char** argv)
{
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN] = {0};
    strncpy(url, argv[1], MAX_URL_LEN - 1);

    CURL* curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "Failed to initialize curl\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, TIMEOUT_VALUE);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEHEADER, stdout);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);
    if (res!= CURLE_OK)
    {
        fprintf(stderr, "Failed to perform request: %s\n", curl_easy_strerror(res));
        return 1;
    }

    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    if (http_code < 200 || http_code >= 300)
    {
        fprintf(stderr, "Failed to get response: HTTP code %ld\n", http_code);
        return 1;
    }

    curl_easy_cleanup(curl);
    return 0;
}