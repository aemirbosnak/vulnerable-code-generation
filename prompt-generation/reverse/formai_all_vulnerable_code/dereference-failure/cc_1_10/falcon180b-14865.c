//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    int interval;
    char *recipient;
} website_t;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *data = (char*)malloc(realsize + 1);
    if(data == NULL) return 0;
    memcpy(data, ptr, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

int main(int argc, char **argv)
{
    if(argc!= 4) {
        printf("Usage: %s <url> <interval> <recipient>\n", argv[0]);
        return 1;
    }

    website_t website = {
       .url = argv[1],
       .interval = atoi(argv[2]),
       .recipient = argv[3]
    };

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        while(1) {
            res = curl_easy_perform(curl);
            if(res!= CURLE_OK) {
                printf("curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));
            }

            sleep(website.interval);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}