//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define TIMEOUT 10
#define INTERVAL 60

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *buffer = (char*)malloc(size * nmemb);
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[1024];
        time_t last_check = 0;

        while(1) {
            time_t current_time = time(NULL);

            if(current_time - last_check >= INTERVAL) {
                last_check = current_time;

                sprintf(url, "http://%s", "example.com");

                curl_easy_setopt(curl, CURLOPT_URL, url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

                res = curl_easy_perform(curl);

                if(res!= CURLE_OK)
                    fprintf(stderr, "curl_easy_perform() failed: %s\n",
                            curl_easy_strerror(res));

                curl_easy_cleanup(curl);
            }

            sleep(1);
        }
    }

    curl_global_cleanup();
    return 0;
}