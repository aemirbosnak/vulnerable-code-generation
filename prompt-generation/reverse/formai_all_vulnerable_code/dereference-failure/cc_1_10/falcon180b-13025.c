//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_SIZE 512
#define MAX_RESPONSE_SIZE 1024

struct url_data {
    char url[MAX_URL_SIZE];
    time_t last_check;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *response = (char*)malloc(size * nmemb);
    memcpy(response, contents, size * nmemb);
    printf("%s", response);
    free(response);
    return size * nmemb;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    struct url_data data;
    strcpy(data.url, argv[1]);
    data.last_check = time(NULL);

    while (1) {
        time_t current_time = time(NULL);
        if (current_time - data.last_check > 60) {
            printf("Checking %s...\n", data.url);
            CURL *curl;
            CURLcode res;

            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();

            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, data.url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                res = curl_easy_perform(curl);
                if(res!= CURLE_OK)
                    fprintf(stderr, "curl_easy_perform() failed: %s\n",
                            curl_easy_strerror(res));

                curl_easy_cleanup(curl);
            }

            data.last_check = current_time;
        }

        sleep(1);
    }

    return 0;
}