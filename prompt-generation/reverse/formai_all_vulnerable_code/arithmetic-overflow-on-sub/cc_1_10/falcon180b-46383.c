//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define CHECK_INTERVAL 60 // Check website every 60 seconds

typedef struct {
    char *url;
    time_t last_checked;
} website_t;

void log_error(const char *message) {
    fprintf(stderr, "ERROR: %s\n", message);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    char *data = (char *)ptr;
    size_t len = size * nmemb;
    if (len > 0) {
        printf("%s", data);
    }
    return len;
}

int check_website(website_t *website) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            log_error(curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    } else {
        log_error("Failed to initialize curl");
    }
    
    return res == CURLE_OK;
}

void check_websites(website_t websites[], int num_websites) {
    time_t current_time = time(NULL);
    for (int i = 0; i < num_websites; i++) {
        if (current_time - websites[i].last_checked >= CHECK_INTERVAL) {
            if (check_website(&websites[i])) {
                websites[i].last_checked = current_time;
            } else {
                printf("Website %s is down\n", websites[i].url);
            }
        }
    }
}

int main() {
    website_t websites[] = {
        {"https://example.com", 0},
        {"https://google.com", 0},
        {"https://yahoo.com", 0}
    };
    int num_websites = sizeof(websites) / sizeof(website_t);
    
    while (1) {
        check_websites(websites, num_websites);
        sleep(CHECK_INTERVAL);
    }
    
    return 0;
}