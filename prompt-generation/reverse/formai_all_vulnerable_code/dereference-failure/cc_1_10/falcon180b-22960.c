//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024
#define CHECK_INTERVAL_SECONDS 60

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    char* buffer = (char*)malloc(size * nmemb);
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    free(buffer);
    return size * nmemb;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN];
    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();

    if (!curl) {
        printf("Error initializing curl\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    while (1) {
        CURLcode res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Error performing curl request: %s\n", curl_easy_strerror(res));
            break;
        }

        int response_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        if (response_code!= 200) {
            printf("Website is down (response code %d)\n", response_code);
        }

        time_t now = time(NULL);
        struct tm* tm = localtime(&now);
        printf("Current time: %s\n", asctime(tm));

        sleep(CHECK_INTERVAL_SECONDS);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}