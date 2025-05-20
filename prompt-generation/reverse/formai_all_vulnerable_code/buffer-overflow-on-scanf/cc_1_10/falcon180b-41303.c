//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 10240

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *response = (char*)malloc(realsize + 1);
    memcpy(response, contents, realsize);
    response[realsize] = '\0';
    printf("Response: %s\n", response);
    free(response);
    return realsize;
}

int main(void) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[MAX_URL_LEN];
        time_t last_check = 0;

        while(1) {
            printf("Enter website URL: ");
            scanf("%s", url);

            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

            res = curl_easy_perform(curl);

            if(res!= CURLE_OK) {
                printf("curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));
            } else {
                time_t current_time = time(NULL);

                if(last_check == 0 || difftime(current_time, last_check) >= 60) {
                    printf("Website is up!\n");
                    last_check = current_time;
                } else {
                    printf("Website was checked recently.\n");
                }
            }

            curl_easy_cleanup(curl);
        }

        curl_global_cleanup();
    }

    return 0;
}