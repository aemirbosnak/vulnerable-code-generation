//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define MAX_SITES 10
#define SITE_NAME_LEN 100
#define SITE_URL_LEN 200

struct site {
    char name[SITE_NAME_LEN];
    char url[SITE_URL_LEN];
    CURL *curl;
    int status;
    int response_code;
    int timeout;
};

int is_valid_url(const char *url) {
    int len = strlen(url);
    if (len < 8 || strncmp(url, "http://", 7)!= 0 && strncmp(url, "https://", 8)!= 0) {
        return 0;
    }
    return 1;
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int check_site(struct site *site) {
    CURLcode res;
    long response_time;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    res = curl_easy_perform(site->curl);
    if (res!= CURLE_OK) {
        site->status = 0;
        site->response_code = 0;
        return 1;
    }

    site->response_code = curl_easy_getinfo(site->curl, CURLINFO_HTTP_CODE, NULL);
    if (site->response_code < 200 || site->response_code >= 300) {
        site->status = 0;
        return 1;
    }

    response_time = curl_easy_getinfo(site->curl, CURLINFO_TOTAL_TIME, NULL);
    gettimeofday(&end, NULL);
    site->status = 1;
    site->response_code = response_time;
    site->timeout = (int) ((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000);
    return 0;
}

int main() {
    int i;
    struct site sites[MAX_SITES];

    for (i = 0; i < MAX_SITES; i++) {
        printf("Enter site name: ");
        scanf("%s", sites[i].name);
        printf("Enter site URL: ");
        scanf("%s", sites[i].url);
        if (!is_valid_url(sites[i].url)) {
            printf("Invalid URL.\n");
            i--;
            continue;
        }
        sites[i].curl = curl_easy_init();
        if (!sites[i].curl) {
            printf("Error initializing curl.\n");
            i--;
            continue;
        }
        sites[i].status = 0;
        sites[i].response_code = 0;
        sites[i].timeout = 0;
    }

    while (1) {
        for (i = 0; i < MAX_SITES; i++) {
            check_site(&sites[i]);
        }
        sleep(5);
    }

    return 0;
}