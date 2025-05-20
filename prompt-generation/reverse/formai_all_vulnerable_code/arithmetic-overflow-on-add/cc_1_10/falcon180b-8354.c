//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <time.h>

typedef struct {
    char* url;
    time_t last_check;
    time_t next_check;
    int interval;
    int timeout;
} website_t;

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp) {
    char* data = (char*)buffer;
    size_t len = size * nmemb;
    printf("%s", data);
    return len;
}

int check_website(website_t* website) {
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, website->timeout);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return res;
}

void update_next_check(website_t* website) {
    time_t now = time(NULL);
    website->next_check = now + website->interval;
}

int main() {
    website_t websites[] = {
        {.url = "https://example.com",.interval = 60,.timeout = 10 },
        {.url = "https://another-example.com",.interval = 120,.timeout = 20 }
    };
    int num_websites = sizeof(websites) / sizeof(website_t);
    while(1) {
        time_t now = time(NULL);
        for(int i = 0; i < num_websites; i++) {
            website_t* website = &websites[i];
            if(now >= website->next_check) {
                int res = check_website(website);
                if(res!= CURLE_OK) {
                    printf("Website %s is down\n", website->url);
                }
                update_next_check(website);
            }
        }
        sleep(1);
    }
    return 0;
}