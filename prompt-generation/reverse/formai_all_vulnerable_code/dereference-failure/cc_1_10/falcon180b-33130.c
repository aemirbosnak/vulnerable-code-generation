//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define MAX_URLS 10
#define CHECK_INTERVAL 60 // seconds

typedef struct {
    char *url;
    int status;
    time_t last_check;
} url_t;

url_t urls[MAX_URLS];
int num_urls = 0;

void *check_url(void *arg) {
    int i = (int) arg;
    char buffer[1024];
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        sprintf(buffer, "%s", urls[i].url);
        curl_easy_setopt(curl, CURLOPT_URL, buffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            urls[i].status = (int) response_code;
            urls[i].last_check = time(NULL);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return NULL;
}

int main() {
    pthread_t threads[MAX_URLS];
    int i;

    printf("Enter up to %d URLs (one per line):\n", MAX_URLS - 1);

    for (i = 0; i < MAX_URLS - 1; i++) {
        fgets(urls[i].url, 1024, stdin);
        num_urls++;
    }

    for (i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, check_url, (void *) i);
    }

    for (i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}