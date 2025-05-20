//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char* data = (char*)malloc(realsize + 1);
    if (data) {
        memcpy(data, contents, realsize);
        data[realsize] = 0;
        *(char**)userp = data;
    }
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;
    char url[100];
    double speed = 0;
    time_t start_time, end_time;
    char* response = NULL;

    printf("Enter the URL: ");
    scanf("%s", url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        start_time = time(NULL);
        res = curl_easy_perform(curl);
        end_time = time(NULL);

        if(res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            speed = (double)strlen(response) / (double)(end_time - start_time);
            printf("Internet Speed: %.2lf KB/s\n", speed);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}