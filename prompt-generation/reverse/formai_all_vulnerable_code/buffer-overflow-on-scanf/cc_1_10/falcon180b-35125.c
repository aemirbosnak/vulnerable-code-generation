//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URLS 10

struct url_info {
    char *url;
    int is_up;
};

void *check_url_status(void *arg) {
    struct url_info *url_info = (struct url_info *) arg;
    CURL *curl;
    CURLcode res;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        char *effective_url = url_info->url;
        res = curl_easy_setopt(curl, CURLOPT_URL, effective_url);
        if(res!= CURLE_OK) {
            fprintf(stderr, "Failed to set URL: %s\n", curl_easy_strerror(res));
        } else {
            res = curl_easy_perform(curl);
            if(res!= CURLE_OK) {
                fprintf(stderr, "Failed to perform request: %s\n", curl_easy_strerror(res));
            } else {
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                
                if(response_code >= 200 && response_code < 400) {
                    url_info->is_up = 1;
                } else {
                    url_info->is_up = 0;
                }
            }
        }
        
        curl_easy_cleanup(curl);
    }
    
    return NULL;
}

int main() {
    pthread_t threads[MAX_URLS];
    struct url_info urls[MAX_URLS];
    int i;
    
    printf("Enter URLs to monitor (max %d):\n", MAX_URLS);
    for(i = 0; i < MAX_URLS; i++) {
        scanf("%s", urls[i].url);
    }
    
    for(i = 0; i < MAX_URLS; i++) {
        pthread_create(&threads[i], NULL, check_url_status, (void *) &urls[i]);
    }
    
    for(i = 0; i < MAX_URLS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}