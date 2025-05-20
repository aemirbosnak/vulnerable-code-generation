//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 2048

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *response = (char *)userp;
    size_t response_len = strlen(response);
    strncat(response, (char *)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    time_t start_time, end_time;

    printf("Enter website URL: ");
    scanf("%s", url);

    start_time = time(NULL);
    res = curl_global_init(CURL_GLOBAL_DEFAULT);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_global_init failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    end_time = time(NULL);
    printf("Response:\n%s\n", response);
    printf("Website uptime: %ld seconds\n", end_time - start_time);

    curl_global_cleanup();
    return 0;
}