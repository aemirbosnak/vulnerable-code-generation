//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *ptr = (char*)malloc(realsize + 1);
    if(ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 0;
    }
    memcpy(ptr, contents, realsize);
    ptr[realsize] = '\0';
    ((char**)userp)[0] = ptr;
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;
    char url[256];
    char *response = NULL;

    printf("Enter the URL: ");
    scanf("%s", url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response);
        }

        curl_easy_cleanup(curl);
        free(response);
    }

    curl_global_cleanup();
    return 0;
}