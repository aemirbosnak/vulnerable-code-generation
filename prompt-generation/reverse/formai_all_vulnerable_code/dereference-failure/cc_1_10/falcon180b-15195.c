//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 10240
#define CHECK_INTERVAL 60

struct url_data {
    char *url;
    char *last_response;
    time_t last_check;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char*)malloc(size * nmemb);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, size * nmemb);
    struct url_data *data = (struct url_data*)userp;
    if (data->last_response!= NULL) {
        free(data->last_response);
    }
    data->last_response = buffer;
    return nmemb;
}

int main() {
    CURL *curl;
    FILE *config_file;
    char line[MAX_URL_LEN];
    struct url_data *urls = NULL;
    int num_urls = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if ((config_file = fopen("config.txt", "r")) == NULL) {
        printf("Error opening config file\n");
        exit(1);
    }

    while (fgets(line, MAX_URL_LEN, config_file)!= NULL) {
        char *url = strtok(line, " ");
        if (url == NULL) {
            continue;
        }
        struct url_data *data = (struct url_data*)malloc(sizeof(struct url_data));
        data->url = strdup(url);
        data->last_response = NULL;
        data->last_check = 0;
        urls = realloc(urls, sizeof(struct url_data) * ++num_urls);
        urls[num_urls - 1] = *data;
        free(data);
    }

    fclose(config_file);

    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < num_urls; i++) {
            if (current_time - urls[i].last_check >= CHECK_INTERVAL) {
                curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urls[i]);
                curl_easy_perform(curl);
                urls[i].last_check = current_time;
            }
        }
        sleep(1);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}