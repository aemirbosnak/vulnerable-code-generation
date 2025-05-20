//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LEN 512
#define CHECK_INTERVAL 60 //seconds

//Function prototypes
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
int CheckWebsiteStatus(char* url);

int main() {
    CURL* curl;
    char url[MAX_URL_LEN];
    FILE* logfile;
    time_t last_check_time = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        printf("Enter the URL to monitor: ");
        scanf("%s", url);

        logfile = fopen("website_status.log", "a+");
        if(logfile == NULL) {
            printf("Error opening log file.\n");
            exit(1);
        }

        while(1) {
            if(CheckWebsiteStatus(url)) {
                fprintf(logfile, "%s is down.\n", url);
            } else {
                fprintf(logfile, "%s is up.\n", url);
            }

            last_check_time = time(NULL);
            sleep(CHECK_INTERVAL);
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;
}

int CheckWebsiteStatus(char* url) {
    CURL* curl;
    CURLcode res;
    char response[1024];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            printf("Error checking website status: %s\n", curl_easy_strerror(res));
            return 0;
        }

        if(strstr(response, "HTTP/1.1 200 OK") == NULL) {
            return 0;
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 1;
}