//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

struct website_info {
    char *url;
    int http_status;
};

void log_error(const char *error) {
    fprintf(stderr, "Error: %s\n", error);
}

int get_http_status(const char *url) {
    CURL *curl;
    CURLcode res;
    int http_status = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            log_error(curl_easy_strerror(res));
        } else {
            CURLcode http_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            http_status = http_code;
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return http_status;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        log_error("Usage:./program <website_url> <monitoring_interval_in_seconds>");
        return 1;
    }

    char *url = argv[1];
    int monitoring_interval = atoi(argv[2]);

    struct website_info website_info;
    website_info.url = url;

    while (1) {
        int http_status = get_http_status(url);

        if (http_status == 200) {
            printf("Website %s is up and running!\n", url);
        } else {
            printf("Website %s is down. HTTP status code: %d\n", url, http_status);
        }

        sleep(monitoring_interval);
    }

    return 0;
}