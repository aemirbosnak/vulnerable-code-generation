//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*1024
#define CHECK_INTERVAL 60 // in seconds

typedef struct {
    char url[MAX_URL_LEN];
    char last_response[MAX_RESPONSE_LEN];
    time_t last_check;
} website_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    website_t *website = (website_t*)userp;
    if (size * nmemb + strlen(website->last_response) >= MAX_RESPONSE_LEN) {
        return 0;
    }
    strncat(website->last_response, (char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    FILE *fp;
    char filename[64];
    time_t current_time;
    website_t websites[10]; // max 10 websites

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        for (int i = 0; i < 10; i++) {
            sprintf(filename, "website%d.txt", i+1);
            fp = fopen(filename, "r");
            if (fp) {
                fscanf(fp, "%s", websites[i].url);
                fclose(fp);
            } else {
                websites[i].url[0] = '\0';
            }
        }

        while (1) {
            current_time = time(NULL);

            for (int i = 0; i < 10; i++) {
                if (websites[i].url[0]!= '\0') {
                    if (difftime(current_time, websites[i].last_check) >= CHECK_INTERVAL) {
                        curl_easy_setopt(curl, CURLOPT_URL, websites[i].url);
                        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &websites[i]);
                        curl_easy_perform(curl);
                        websites[i].last_check = current_time;
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