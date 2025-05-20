//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_WEBSITES 10
#define CHECK_INTERVAL 60 // seconds

typedef struct {
    char *url;
    char *name;
    CURL *curl;
    int is_up;
} website_t;

website_t websites[MAX_WEBSITES];
int num_websites = 0;

void *check_website(void *arg) {
    int i = (int) arg;
    website_t *website = &websites[i];

    CURLcode res;
    curl_easy_setopt(website->curl, CURLOPT_URL, website->url);
    res = curl_easy_perform(website->curl);

    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to check website '%s': %s\n", website->name, curl_easy_strerror(res));
    } else {
        long response_code;
        curl_easy_getinfo(website->curl, CURLINFO_RESPONSE_CODE, &response_code);

        if (response_code == 200) {
            website->is_up = 1;
        } else {
            website->is_up = 0;
        }
    }

    return NULL;
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    int i;
    for (i = 0; i < MAX_WEBSITES && num_websites < MAX_WEBSITES; i++) {
        website_t *website = &websites[num_websites];
        num_websites++;

        printf("Enter website URL for %d: ", i + 1);
        scanf("%s", website->url);

        printf("Enter website name for %d: ", i + 1);
        scanf("%s", website->name);

        website->curl = curl_easy_init();

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, check_website, (void *) i);
    }

    while (1) {
        sleep(CHECK_INTERVAL);

        printf("\n");
        for (i = 0; i < num_websites; i++) {
            website_t *website = &websites[i];

            if (website->is_up) {
                printf("%s is up\n", website->name);
            } else {
                printf("%s is down\n", website->name);
            }
        }
    }

    curl_global_cleanup();

    return 0;
}