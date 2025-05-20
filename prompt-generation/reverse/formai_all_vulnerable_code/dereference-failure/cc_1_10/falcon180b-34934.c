//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

struct Status {
    char *url;
    int response_code;
    time_t last_check;
};

void check_status(struct Status *status, char *url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        status->response_code = res;
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void report_status(struct Status *status) {
    time_t now = time(NULL);
    if(now - status->last_check > 60) {
        check_status(status, status->url);
    }
    if(status->response_code == 200) {
        printf("%s is up\n", status->url);
    } else {
        printf("%s is down (response code %d)\n", status->url, status->response_code);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }
    char *url = argv[1];
    struct Status status = {.url = strdup(url),.response_code = 0,.last_check = 0};
    report_status(&status);
    while(1) {
        sleep(60);
        report_status(&status);
    }
    return 0;
}