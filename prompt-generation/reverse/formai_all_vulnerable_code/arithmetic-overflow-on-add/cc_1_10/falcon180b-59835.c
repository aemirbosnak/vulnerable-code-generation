//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define CHECK_INTERVAL 60
#define LOG_FILE "check.log"

struct check_data {
    char url[1024];
    time_t last_check;
    time_t next_check;
    FILE *log_file;
};

void log_check(struct check_data *data, const char *msg) {
    time_t now = time(NULL);
    if (data->log_file) {
        fprintf(data->log_file, "%ld: %s\n", now, msg);
        fflush(data->log_file);
    } else {
        printf("%ld: %s\n", now, msg);
    }
}

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int check_url(const char *url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            return 1;
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}

int main() {
    struct check_data data;
    char buf[1024];

    data.log_file = fopen(LOG_FILE, "a");

    while (1) {
        time_t now = time(NULL);
        for (int i = 0; i < 10; i++) {
            sprintf(buf, "url%d", i);
            if (data.next_check <= now && access(buf, F_OK) == 0) {
                log_check(&data, "Checking URL");
                if (check_url(data.url)) {
                    log_check(&data, "URL is up");
                } else {
                    log_check(&data, "URL is down");
                }
                data.next_check = now + CHECK_INTERVAL;
            }
        }
        sleep(1);
    }

    return 0;
}