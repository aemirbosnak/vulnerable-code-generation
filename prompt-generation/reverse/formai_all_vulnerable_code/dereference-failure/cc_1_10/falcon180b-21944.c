//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024 * 10

struct url_data {
    char *url;
    time_t last_check;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *buffer = (char*)malloc(size * nmemb);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    free(buffer);
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    char filename[MAX_URL_LEN];
    struct url_data *urls = NULL;
    int num_urls = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s urls_file\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fscanf(fp, "%s", filename)!= EOF) {
        urls = realloc(urls, sizeof(struct url_data) * ++num_urls);
        urls[num_urls - 1].url = strdup(filename);
        urls[num_urls - 1].last_check = 0;
    }

    fclose(fp);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        for (i = 0; i < num_urls; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_perform(curl);
            time_t now = time(NULL);
            if (difftime(now, urls[i].last_check) > 60) {
                printf("URL %s is down\n", urls[i].url);
            }
            urls[i].last_check = now;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}