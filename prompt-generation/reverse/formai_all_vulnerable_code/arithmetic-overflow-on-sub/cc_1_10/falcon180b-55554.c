//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define SERVER_URL "https://www.example.com"
#define CHECK_INTERVAL 60 // seconds

bool is_server_up(char *url)
{
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK) {
            return true;
        }
    }

    return false;
}

void *check_server_status(void *arg)
{
    char *url = (char *) arg;
    time_t last_check = time(NULL);

    while(true) {
        sleep(CHECK_INTERVAL);
        time_t current_time = time(NULL);

        if(current_time - last_check >= CHECK_INTERVAL) {
            if(is_server_up(url)) {
                printf("Server is up and running\n");
            } else {
                printf("Server is down\n");
            }

            last_check = current_time;
        }
    }
}

int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, check_server_status, SERVER_URL);

    while(true) {
        sleep(5);
    }

    return 0;
}