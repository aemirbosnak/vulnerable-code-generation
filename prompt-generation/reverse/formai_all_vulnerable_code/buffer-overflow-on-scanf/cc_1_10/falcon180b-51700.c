//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *ptr = (char *)malloc(realsize + 1);
    if (ptr == NULL) {
        return 0;
    }
    memcpy(ptr, contents, realsize);
    ptr[realsize] = '\0';
    *(char **)userp = ptr;
    return realsize;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    char url[100];
    char *response = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        printf("Enter the URL: ");
        scanf("%s", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}