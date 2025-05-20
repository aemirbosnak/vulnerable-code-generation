//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256

void getURL(char* url)
{
    printf("Enter the URL to monitor: ");
    scanf("%s", url);
}

int isHostUp(char* url)
{
    CURL *curl;
    CURLcode res;
    long http_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // we don't need the content of the page, only the return code
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // follow any redirects
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L); // wait 5 seconds for connection

        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code); // get the HTTP code returned
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return http_code;
}

int main()
{
    char url[MAX_URL_LENGTH];
    int http_code;

    getURL(url);
    while (1) {
        http_code = isHostUp(url);
        if (http_code == 200) {
            printf("Host is up!\n");
        } else {
            printf("Host is down! HTTP Code: %d\n", http_code);
        }
        sleep(10); // wait 10 seconds before checking again
    }

    return 0;
}