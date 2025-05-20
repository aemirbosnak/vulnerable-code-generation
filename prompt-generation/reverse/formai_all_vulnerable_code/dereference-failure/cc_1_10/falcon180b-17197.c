//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <regex.h>

#define MAX_URL_LENGTH 2048
#define MAX_RESPONSE_LENGTH 2048

typedef struct {
    char *url;
    char *response;
    int response_code;
} request_t;

void print_request(request_t *req) {
    printf("URL: %s\n", req->url);
    printf("Response: %s\n", req->response);
    printf("Response Code: %d\n", req->response_code);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    request_t *req = (request_t *) userp;
    size_t realsize = size * nmemb;
    if (realsize > MAX_RESPONSE_LENGTH - strlen(req->response)) {
        req->response[MAX_RESPONSE_LENGTH - 1] = '\0';
    }
    strncat(req->response, (char *) ptr, realsize);
    return realsize;
}

int check_response_code(int response_code) {
    if (response_code >= 200 && response_code < 300) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    CURL *curl;
    CURLcode res;
    char *url = "https://example.com";
    request_t req;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        req.url = strdup(url);
        req.response = malloc(MAX_RESPONSE_LENGTH);
        req.response[0] = '\0';
        req.response_code = 0;

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &req);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            if (check_response_code(req.response_code)) {
                printf("The website is up and running!\n");
            } else {
                printf("The website is down!\n");
            }
        }

        free(req.url);
        free(req.response);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}