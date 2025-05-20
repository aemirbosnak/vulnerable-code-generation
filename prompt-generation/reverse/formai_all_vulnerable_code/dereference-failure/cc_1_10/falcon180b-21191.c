//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL 100
#define MAX_URL_LEN 512

typedef struct {
    char *url;
    char *response;
    int status;
    time_t timestamp;
} url_data_t;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    url_data_t *data = (url_data_t *)userp;
    data->response = realloc(data->response, data->response? strlen(data->response) + size * nmemb + 1 : size * nmemb + 1);
    if (!data->response) {
        return 0;
    }
    memcpy(&data->response[strlen(data->response)], contents, size * nmemb);
    data->response[strlen(data->response)] = '\0';
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    return 0;
}

int main(int argc, char **argv) {
    CURL *curl;
    FILE *fp;
    char buffer[MAX_URL_LEN];
    char *url = NULL;
    int i, j;
    url_data_t data;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error opening config file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(buffer, MAX_URL_LEN, fp)) {
        if (url) {
            free(url);
        }
        url = strdup(buffer);
        data.url = url;
        data.response = NULL;
        data.status = 0;
        data.timestamp = time(NULL);

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
            curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
            curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        printf("%s - %d - %s\n", url, data.status, data.response? data.response : "");
        free(data.response);
        free(url);
    }

    fclose(fp);
    curl_global_cleanup();

    return 0;
}