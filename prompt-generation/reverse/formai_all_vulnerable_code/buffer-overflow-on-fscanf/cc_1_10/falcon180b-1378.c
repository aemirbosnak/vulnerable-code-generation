//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define MAX_URL_LEN 512

struct url_info {
    char url[MAX_URL_LEN];
    int interval;
    time_t last_check;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[size*nmemb] = '\0';
    return size*nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    char buffer[1024];
    struct url_info urls[10];
    int num_urls = 0;
    time_t current_time;

    if (argc < 3) {
        printf("Usage: %s <config_file> <log_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening config file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d\n", urls[num_urls].url, &urls[num_urls].interval)!= EOF) {
        num_urls++;
        if (num_urls >= 10) {
            break;
        }
    }

    fclose(fp);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        while (1) {
            current_time = time(NULL);

            for (int i = 0; i < num_urls; i++) {
                if (difftime(current_time, urls[i].last_check) >= urls[i].interval) {
                    sprintf(buffer, "Checking %s...\n", urls[i].url);
                    fwrite(buffer, strlen(buffer), 1, stdout);

                    curl_easy_setopt(curl, CURLOPT_URL, urls[i].url);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

                    curl_easy_perform(curl);

                    if (buffer[0] == '2') {
                        printf("Website is up.\n");
                    } else {
                        printf("Website is down.\n");
                    }

                    urls[i].last_check = current_time;
                }
            }

            sleep(5);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}