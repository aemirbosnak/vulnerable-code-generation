//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_WEBSITES 10
#define CHECK_INTERVAL 60 // seconds

typedef struct {
    char *url;
    int status;
} website_t;

website_t websites[MAX_WEBSITES];
int num_websites = 0;

void *check_website(void *arg) {
    website_t *website = (website_t *) arg;

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");

        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "HEAD");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            website->status = response_code;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    pthread_exit(0);
}

int main() {
    int i;

    for(i = 0; i < MAX_WEBSITES; i++) {
        printf("Enter website URL %d: ", i+1);
        scanf("%s", websites[i].url);
        websites[i].status = 0;
        num_websites++;
    }

    pthread_t threads[num_websites];

    time_t last_check = time(NULL);

    while(1) {
        time_t current_time = time(NULL);

        if(current_time - last_check >= CHECK_INTERVAL) {
            last_check = current_time;

            for(i = 0; i < num_websites; i++) {
                pthread_create(&threads[i], NULL, check_website, &websites[i]);
            }

            for(i = 0; i < num_websites; i++) {
                pthread_join(threads[i], NULL);
            }
        }

        sleep(1);
    }

    return 0;
}