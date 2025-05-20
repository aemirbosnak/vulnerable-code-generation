//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048
#define MAX_RESPONSE_LENGTH (10 * 1024 * 1024)

struct UrlData {
    char *url;
    size_t url_len;
    char *response;
    size_t response_len;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    struct UrlData *data = (struct UrlData *)userp;
    size_t new_len = data->response_len + size * nmemb;
    if (new_len > MAX_RESPONSE_LENGTH) {
        fprintf(stderr, "Response is too large.\n");
        exit(1);
    }
    data->response = realloc(data->response, new_len + 1);
    if (data->response == NULL) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    memcpy(&data->response[data->response_len], contents, size * nmemb);
    data->response_len = new_len;
    data->response[new_len] = '\0';
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    fprintf(stderr, "Download progress: %lu/%lu bytes\n", dlnow, dltotal);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s URL\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl == NULL) {
        fprintf(stderr, "Failed to initialize curl.\n");
        return 1;
    }

    struct UrlData data;
    data.url = strdup(argv[1]);
    data.url_len = strlen(data.url);
    data.response = malloc(1);
    data.response_len = 0;

    curl_easy_setopt(curl, CURLOPT_URL, data.url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    } else {
        fprintf(stdout, "Response:\n%s\n", data.response);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    free(data.url);
    free(data.response);

    return 0;
}