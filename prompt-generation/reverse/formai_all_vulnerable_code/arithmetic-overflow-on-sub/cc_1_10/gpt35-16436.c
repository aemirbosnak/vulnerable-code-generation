//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

// Define server URLs to monitor
const char *SERVERS[] = {"https://www.example.com", "https://www.google.com", "https://www.github.com"};

// Define the maximum amount of time we allow one server to be down before alerting
#define MAXIMUM_DOWNTIME 60

// Define a struct to represent a server's status
typedef struct {
    const char *url;
    bool is_up;
    time_t last_up_time;
} ServerStatus;

// Define function to check if a server is online
bool is_server_up(const char *url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if(res == CURLE_OK)
            return true;
    }
    return false;
}

int main(void) {
    // Define an array to hold the status of all monitored servers
    ServerStatus server_statuses[sizeof(SERVERS)/sizeof(char *)];
    int num_servers = sizeof(SERVERS)/sizeof(char *);
    for (int i = 0; i < num_servers; i++) {
        server_statuses[i].url = SERVERS[i];
        server_statuses[i].is_up = false;
        server_statuses[i].last_up_time = time(NULL);
    }

    while (true) {
        for (int i = 0; i < num_servers; i++) {
            bool is_up = is_server_up(server_statuses[i].url);
            if (is_up) {
                if (!server_statuses[i].is_up) {
                    printf("Server %s is back up!\n", server_statuses[i].url);
                    server_statuses[i].is_up = true;
                    server_statuses[i].last_up_time = time(NULL);
                }
            } else {
                if (server_statuses[i].is_up) {
                    printf("Server %s is down!\n", server_statuses[i].url);
                    server_statuses[i].is_up = false;
                } else {
                    time_t current_time = time(NULL);
                    int uptime = current_time - server_statuses[i].last_up_time;
                    if (uptime >= MAXIMUM_DOWNTIME) {
                        printf("Server %s has been down for too long!\n", server_statuses[i].url);
                        server_statuses[i].last_up_time = current_time;
                    }
                }
            }
        }
        // Wait 10 seconds before checking again
        sleep(10);
    }

    return 0;
}