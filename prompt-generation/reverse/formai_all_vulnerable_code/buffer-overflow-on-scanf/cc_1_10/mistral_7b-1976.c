//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <curl/curl.h>

#define MAX_RETRIES 3
#define SLEEP_TIME 60
#define CHECK_INTERVAL 5
#define FILE_NAME "website_status.txt"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    FILE *fp = (FILE *)userp;
    fwrite(contents, size, realsize, fp);
    fflush(fp);
    return realsize;
}

void check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *file;
    int retries = 0;

    curl = curl_easy_init();
    if(curl) {
        file = fopen(FILE_NAME, "ab");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        do {
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "Failed to connect to %s: %s\n", url, curl_easy_strerror(res));
                if(++retries > MAX_RETRIES) {
                    fprintf(stderr, "Giving up after %d retries\n", MAX_RETRIES);
                    break;
                }
                sleep(SLEEP_TIME);
            }
        } while(res != CURLE_OK);

        curl_easy_cleanup(curl);
        fclose(file);
    }
}

void signal_handler(int signal) {
    printf("Received signal %d, stopping the program...\n", signal);
    exit(0);
}

int main() {
    char url[100];
    int i;

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    printf("Enter the URL to monitor: ");
    scanf("%s", url);

    while(1) {
        check_website(url);
        printf("Checking %s...\n", url);
        sleep(CHECK_INTERVAL);
    }

    return 0;
}