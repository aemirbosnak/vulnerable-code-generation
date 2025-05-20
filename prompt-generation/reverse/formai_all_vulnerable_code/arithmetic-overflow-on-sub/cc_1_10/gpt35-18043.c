//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define URL "https://www.example.com"
#define MAX_WAIT_TIME 300
#define MAX_ATTEMPTS 3
#define CHECK_FREQUENCY 60

int attempts = 0;

void handle_alarm(int sig) {
    printf("Website is taking too long to respond. Trying again...\n");
    alarm(1);
}

void handle_success() {
    printf("Website is up. Waiting for next check...\n");
    attempts = 0;
}

void handle_failure() {
    printf("Website is down.\n");
    attempts++;
    if (attempts == MAX_ATTEMPTS) {
        printf("Max attempts reached. Exiting program.\n");
        exit(1);
    } else {
        printf("Trying again in %d seconds...\n", CHECK_FREQUENCY);
        sleep(CHECK_FREQUENCY);
    }
}

int main() {
    CURL *curl;
    CURLcode res;
    struct timespec start_time, end_time;
    double elapsed_time;
    
    signal(SIGALRM, handle_alarm);
    alarm(MAX_WAIT_TIME);
    
    while(1) {
        curl = curl_easy_init();
        if(curl) {
            clock_gettime(CLOCK_REALTIME, &start_time);

            curl_easy_setopt(curl, CURLOPT_URL, URL);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            clock_gettime(CLOCK_REALTIME, &end_time);
            elapsed_time = (end_time.tv_sec-start_time.tv_sec) + (double)(end_time.tv_nsec-start_time.tv_nsec)/1000000000.0;

            if (res == CURLE_OK) {
                handle_success();
            } else {
                handle_failure();
            }
        } else {
            printf("Could not initialize curl.\n");
            exit(1);
        }
    }

    return 0;
}