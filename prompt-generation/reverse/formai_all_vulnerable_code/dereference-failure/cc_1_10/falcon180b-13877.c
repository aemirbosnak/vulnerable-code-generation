//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

struct website {
    char* name;
    char* url;
    int interval;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int CheckWebsite(struct website* w)
{
    CURL* curl;
    CURLcode res;
    char* response;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, w->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }
    else {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 1;
    }
    if (response && strstr(response, "OK")) {
        printf("%s is up\n", w->name);
        free(response);
        return 0;
    }
    else {
        printf("%s is down\n", w->name);
        free(response);
        return 1;
    }
}

void* MonitorWebsite(void* arg)
{
    struct website* w = (struct website*) arg;
    while (1) {
        sleep(w->interval);
        CheckWebsite(w);
    }
    return NULL;
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <website_name> <website_url> <check_interval_seconds>\n", argv[0]);
        return 1;
    }
    struct website w;
    w.name = argv[1];
    w.url = argv[2];
    w.interval = atoi(argv[3]);
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, MonitorWebsite, &w);
    while (1) {
        sleep(1);
    }
    return 0;
}