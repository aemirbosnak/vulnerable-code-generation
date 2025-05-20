//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/timeb.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *data = (char *)contents;
    printf("%s", data);
    return realsize;
}

void check_website_status(char *url)
{
    CURL *curl;
    CURLcode res;
    long response_code;
    char *response_body;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "HEAD");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if (response_code == 200) {
                printf("Website is up and running.\n");
            } else {
                printf("Website is down. Response code: %ld.\n", response_code);
            }
        }

        curl_easy_cleanup(curl);
    } else {
        printf("curl_easy_init() failed.\n");
    }

    curl_global_cleanup();
}

int main()
{
    char url[100];

    printf("Enter website URL: ");
    scanf("%s", url);

    check_website_status(url);

    return 0;
}