//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 512
#define TIMEOUT 10

char *url = NULL;
long response_code = 0;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *buffer = (char*)malloc(realsize + 1);
    if (buffer) {
        memcpy(buffer, contents, realsize);
        buffer[realsize] = '\0';
        printf("%s", buffer);
        free(buffer);
    }
    return realsize;
}

int main()
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        printf("Enter the URL to monitor: ");
        scanf("%s", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}