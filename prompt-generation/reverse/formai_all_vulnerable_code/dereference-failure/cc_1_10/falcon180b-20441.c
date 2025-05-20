//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_WEBSITES 10

typedef struct {
    char *url;
    char *name;
} website_t;

website_t websites[MAX_WEBSITES];
int num_websites;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char *)ptr;
    int len = size * nmemb;
    printf("%s", buffer);
    return len;
}

int main() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        printf("Enter the number of websites you want to monitor:\n");
        scanf("%d", &num_websites);

        printf("Enter the URLs and names of the websites (format: URL name):\n");
        for (int i = 0; i < num_websites; i++) {
            char url[100], name[100];
            scanf("%s %s", url, name);
            strcpy(websites[i].url, url);
            strcpy(websites[i].name, name);
        }

        for (int i = 0; i < num_websites; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, websites[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            res = curl_easy_perform(curl);

            if (res!= CURLE_OK) {
                printf("%s is down!\n", websites[i].name);
            } else {
                printf("%s is up and running!\n", websites[i].name);
            }
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}