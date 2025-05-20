//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096

struct url_data {
    char *url;
    char *response;
    int response_code;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    struct url_data *data = (struct url_data *)userp;
    size_t realsize = size * nmemb;
    if (data->response == NULL) {
        data->response = malloc(realsize + 1);
        if (data->response == NULL) {
            return 0;
        }
        data->response[0] = '\0';
    } else {
        data->response = realloc(data->response, strlen(data->response) + realsize + 1);
        if (data->response == NULL) {
            return 0;
        }
    }
    memcpy(&data->response[strlen(data->response)], ptr, realsize);
    data->response[strlen(data->response) + realsize] = '\0';
    return realsize;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    char *url;
    struct url_data urldata;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    url = argv[1];
    urldata.url = strdup(url);
    urldata.response = NULL;
    urldata.response_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl == NULL) {
        fprintf(stderr, "Failed to initialize curl\n");
        exit(1);
    }

    curl_easy_setopt(curl, CURLOPT_URL, urldata.url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urldata);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    fp = fopen("response.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open response file\n");
        exit(1);
    }

    fprintf(fp, "URL: %s\n", urldata.url);
    fprintf(fp, "Response Code: %d\n", urldata.response_code);
    fprintf(fp, "Response:\n%s", urldata.response);

    fclose(fp);

    curl_global_cleanup();

    return 0;
}