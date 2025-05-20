//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 2048
#define MAX_RESPONSE_LENGTH 10240

struct url_data {
    char url[MAX_URL_LENGTH];
    time_t last_checked;
    int is_up;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char*)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

int check_url(const char *url)
{
    CURL *curl;
    CURLcode res;
    char response[MAX_RESPONSE_LENGTH];
    struct url_data *data;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        data = malloc(sizeof(struct url_data));
        strcpy(data->url, url);
        data->last_checked = time(NULL);
        data->is_up = 1;

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        if(data->is_up && strstr(response, "404")) {
            data->is_up = 0;
        }

        free(data);
        curl_easy_cleanup(curl);
    }

    return data->is_up;
}

int main(int argc, char *argv[])
{
    FILE *file;
    char line[MAX_URL_LENGTH];
    struct url_data data;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if(!file) {
        fprintf(stderr, "Error opening config file.\n");
        return 1;
    }

    while(fgets(line, MAX_URL_LENGTH, file)) {
        if(line[0]!= '#' && line[0]!= '\n') {
            strtok(line, " ");
            strcpy(data.url, line);
            data.last_checked = time(NULL);
            data.is_up = 1;

            check_url(data.url);
        }
    }

    fclose(file);

    return 0;
}