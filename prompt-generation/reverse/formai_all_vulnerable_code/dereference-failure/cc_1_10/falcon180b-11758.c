//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*1024

struct url_data {
    char *url;
    time_t last_check;
    int status_code;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char*)malloc(size * nmemb);
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *file;
    char *file_contents = NULL;
    size_t file_size = 0;
    struct url_data *urls = NULL;
    int num_urls = 0;
    char *line = NULL;
    size_t line_size = 0;
    ssize_t read_count;
    int i;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        file = fopen("urls.txt", "r");
        if (!file) {
            fprintf(stderr, "Failed to open urls.txt\n");
            exit(1);
        }

        while ((read_count = getline(&line, &line_size, file))!= -1) {
            urls = realloc(urls, sizeof(struct url_data) * ++num_urls);
            urls[num_urls - 1].url = strdup(line);
            urls[num_urls - 1].last_check = 0;
            urls[num_urls - 1].status_code = 0;
        }

        fclose(file);

        for (i = 0; i < num_urls; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_perform(curl);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &urls[i].status_code);
            urls[i].last_check = time(NULL);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}