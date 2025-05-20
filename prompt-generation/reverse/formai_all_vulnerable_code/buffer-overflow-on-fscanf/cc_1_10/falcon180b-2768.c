//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/time.h>

#define MAX_URL_LEN 512
#define MAX_RESPONSE_LEN 1024
#define TIMEOUT 10
#define RETRY_INTERVAL 60

struct url_info {
    char *url;
    char *last_response;
    time_t last_check;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    struct url_info *info = (struct url_info *) userp;
    if (info->last_response == NULL) {
        info->last_response = malloc(MAX_RESPONSE_LEN);
        memset(info->last_response, 0, MAX_RESPONSE_LEN);
    }
    strncat(info->last_response, (char *) contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char *filename = "urls.txt";
    struct url_info urls[100];
    int num_urls = 0;
    int i;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        fp = fopen(filename, "r");
        if (fp!= NULL) {
            while (fscanf(fp, "%s\n", urls[num_urls].url)!= EOF) {
                num_urls++;
            }
            fclose(fp);
        }

        for (i = 0; i < num_urls; i++) {
            urls[i].last_response = NULL;
            urls[i].last_check = 0;
        }

        while (1) {
            time_t current_time = time(NULL);

            for (i = 0; i < num_urls; i++) {
                if (current_time - urls[i].last_check >= RETRY_INTERVAL) {
                    curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &urls[i]);
                    res = curl_easy_perform(curl);

                    if (res!= CURLE_OK) {
                        printf("Failed to check %s: %s\n", urls[i].url, curl_easy_strerror(res));
                    } else {
                        urls[i].last_check = current_time;
                    }
                }
            }

            sleep(1);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}