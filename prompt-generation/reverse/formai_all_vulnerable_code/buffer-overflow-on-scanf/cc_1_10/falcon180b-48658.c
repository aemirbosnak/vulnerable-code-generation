//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 1024

typedef struct {
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    int response_code;
} website_t;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    website_t *website = (website_t*)userp;
    size_t realsize = size * nmemb;
    if (realsize > MAX_RESPONSE_LEN - strlen(website->response)) {
        realsize = MAX_RESPONSE_LEN - strlen(website->response);
    }
    strncat(website->response, (char*)ptr, realsize);
    return realsize;
}

int check_website_status(website_t *website) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, website);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    return website->response_code;
}

int main() {
    website_t website;
    int status;

    printf("Enter the URL: ");
    scanf("%s", website.url);

    status = check_website_status(&website);

    if (status == 200) {
        printf("%s is up and running!\n", website.url);
    } else {
        printf("%s is down!\n", website.url);
    }

    return 0;
}