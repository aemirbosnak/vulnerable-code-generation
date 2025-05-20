//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define TIMEOUT 5L
#define MAX_URL_LEN 2048

struct url_data {
    char *url;
    time_t last_check;
    int status_code;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *data = (char*)malloc(size * nmemb);
    memcpy(data, contents, size * nmemb);
    printf("%s", data);
    free(data);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    FILE *config_file;
    char line[MAX_URL_LEN];
    struct url_data *urls = NULL;
    int num_urls = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        config_file = fopen("config.txt", "r");
        if (config_file) {
            while (fgets(line, MAX_URL_LEN, config_file)!= NULL) {
                if (num_urls >= MAX_URL_LEN) {
                    printf("Error: Too many URLs in config file.\n");
                    exit(1);
                }
                urls = realloc(urls, sizeof(struct url_data) * ++num_urls);
                urls[num_urls - 1].url = strdup(line);
                urls[num_urls - 1].last_check = 0;
                urls[num_urls - 1].status_code = 0;
            }
            fclose(config_file);
        } else {
            printf("Error: Could not open config file.\n");
            exit(1);
        }

        while (1) {
            time_t current_time = time(NULL);
            for (int i = 0; i < num_urls; i++) {
                if (current_time - urls[i].last_check >= TIMEOUT) {
                    curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
                    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                    curl_easy_perform(curl);

                    int response_code = 0;
                    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                    urls[i].status_code = response_code;
                    urls[i].last_check = current_time;
                }
            }

            sleep(60);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}