//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URLS 10
#define CHECK_INTERVAL 60 // seconds

struct url_info {
    char *url;
    int status_code;
    time_t last_check;
};

void *monitor_urls(void *arg) {
    int i;
    struct url_info *urls = (struct url_info *) arg;

    for (i = 0; i < MAX_URLS; i++) {
        if (urls[i].url!= NULL) {
            CURL *curl;
            CURLcode res;
            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();

            if (curl) {
                char *effective_url = urls[i].url; // use effective URL if redirects occurred
                res = curl_easy_setopt(curl, CURLOPT_URL, effective_url);
                if (res!= CURLE_OK) {
                    fprintf(stderr, "curl_easy_setopt(CURLOPT_URL) failed: %s\n",
                            curl_easy_strerror(res));
                } else {
                    res = curl_easy_perform(curl);
                    if (res!= CURLE_OK) {
                        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                                curl_easy_strerror(res));
                    } else {
                        long response_code;
                        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                        urls[i].status_code = response_code;
                        urls[i].last_check = time(NULL);
                    }
                }

                curl_easy_cleanup(curl);
            }
        }

        sleep(CHECK_INTERVAL);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_URLS];
    struct url_info urls[MAX_URLS];
    int i, num_urls;

    printf("Enter number of URLs to monitor (up to %d): ", MAX_URLS);
    scanf("%d", &num_urls);

    printf("Enter URLs:\n");
    for (i = 0; i < num_urls; i++) {
        urls[i].url = malloc(1024);
        scanf("%s", urls[i].url);
    }

    for (i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, monitor_urls, &urls[i]);
    }

    for (i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}