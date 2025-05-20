//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#define MAX_URL_LENGTH 1024
#define DEFAULT_TIMEOUT 10

struct url_data {
    char *url;
    int timeout;
};

int ping_url(const char *url, int timeout) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, timeout * 1000);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, timeout * 1000);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return res == CURLE_OK;
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_URL_LENGTH];
    struct url_data data;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error opening config file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_URL_LENGTH, fp)) {
        if (sscanf(line, "%s %d", data.url, &data.timeout)!= 2) {
            fprintf(stderr, "Invalid line in config file: %s\n", line);
            continue;
        }

        if (ping_url(data.url, data.timeout)) {
            printf("URL '%s' is up.\n", data.url);
        } else {
            printf("URL '%s' is down.\n", data.url);
        }
    }

    fclose(fp);
    return 0;
}