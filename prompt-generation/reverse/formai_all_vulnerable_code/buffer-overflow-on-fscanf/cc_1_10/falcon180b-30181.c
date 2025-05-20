//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024

struct url_info {
    char url[MAX_URL_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int status_code;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    struct url_info *url_info = (struct url_info *)userp;

    if (size * nmemb > MAX_RESPONSE_LENGTH - strlen(url_info->response)) {
        return 0;
    }

    strncat(url_info->response, (char *)contents, size * nmemb);

    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *file;
    struct url_info urls[10];
    int num_urls = 0;

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fscanf(file, "%s", urls[num_urls].url)!= EOF) {
        num_urls++;

        if (num_urls >= 10) {
            break;
        }
    }

    fclose(file);

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl == NULL) {
        printf("Error initializing curl\n");
        return 1;
    }

    for (int i = 0; i < num_urls; i++) {
        curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urls[i]);

        curl_easy_perform(curl);

        printf("URL: %s\nStatus Code: %d\nResponse:\n%s\n\n", urls[i].url, urls[i].status_code, urls[i].response);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}