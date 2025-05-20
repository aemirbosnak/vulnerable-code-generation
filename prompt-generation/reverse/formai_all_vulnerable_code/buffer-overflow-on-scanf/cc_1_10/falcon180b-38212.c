//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

// Function to check if website is up or down
void *website_check(void *arg) {
    char *url = (char *) arg;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    int count = 0;
    char url[100];

    // Get user input for website URL
    printf("Enter website URL: ");
    scanf("%s", url);

    // Check if website is up or down
    while(1) {
        pthread_create(&thread_id, NULL, website_check, (void *) url);
        pthread_join(thread_id, NULL);

        if(count == 3) {
            printf("\nWebsite is down.\n");
            break;
        }

        count++;
        sleep(10);
    }

    return 0;
}