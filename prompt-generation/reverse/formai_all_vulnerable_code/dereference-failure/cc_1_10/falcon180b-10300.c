//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*1024*10 // 10MB

int is_up(const char* url);
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN];
    strcpy(url, argv[1]);

    int is_up_result = is_up(url);

    if (is_up_result == 0) {
        printf("Website is up.\n");
    } else {
        printf("Website is down.\n");
    }

    return 0;
}

int is_up(const char* url) {
    CURL* curl;
    CURLcode res;
    char response[MAX_RESPONSE_LEN];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    if (res == CURLE_OK) {
        if (strstr(response, "200 OK")!= NULL) {
            return 0; // website is up
        } else {
            return 1; // website is down
        }
    } else {
        return 1; // curl failed
    }
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* response = (char*)userp;

    strncat(response, (char*)contents, realsize);

    return realsize;
}