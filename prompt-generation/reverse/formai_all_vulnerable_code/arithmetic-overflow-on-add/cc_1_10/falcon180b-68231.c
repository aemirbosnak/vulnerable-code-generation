//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <unistd.h>

#define TIMEOUT 5L
#define INTERVAL 60L

struct website {
    char *url;
    char *name;
};

struct website websites[] = {
    {"https://www.google.com", "Google"},
    {"https://www.facebook.com", "Facebook"},
    {"https://www.twitter.com", "Twitter"},
    {"https://www.github.com", "Github"},
    {NULL, NULL}
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char buffer[4096];
    struct website *website;
    time_t last_check, current_time;
    int i;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        for(i = 0; websites[i].url!= NULL; i++) {
            website = &websites[i];

            fp = fopen(website->name, "r");
            if(fp!= NULL) {
                fclose(fp);
                continue;
            }

            curl_easy_setopt(curl, CURLOPT_URL, website->url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
            curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

            res = curl_easy_perform(curl);
            if(res!= CURLE_OK) {
                fprintf(stderr, "Failed to check %s: %s\n", website->url, curl_easy_strerror(res));
                continue;
            }

            last_check = time(NULL);
            current_time = last_check + INTERVAL;

            while(current_time > time(NULL)) {
                sleep(1);
                current_time = last_check + INTERVAL;
            }
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}