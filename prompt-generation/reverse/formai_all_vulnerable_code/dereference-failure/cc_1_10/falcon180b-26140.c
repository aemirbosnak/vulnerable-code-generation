//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_STATUS_CODE_LEN 32
#define MAX_RESPONSE_CODE_LEN 32
#define MAX_RESPONSE_BODY_LEN 1024

struct website_info {
    char url[MAX_URL_LEN];
    char status_code[MAX_STATUS_CODE_LEN];
    char response_code[MAX_RESPONSE_CODE_LEN];
    char response_body[MAX_RESPONSE_BODY_LEN];
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        return 1;
    }

    char website_url[MAX_URL_LEN] = {0};
    strcpy(website_url, argv[1]);

    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct website_info website_info = {0};
        curl_easy_setopt(curl, CURLOPT_URL, website_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &website_info.response_body);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &website_info.response_code);
            snprintf(website_info.status_code, MAX_STATUS_CODE_LEN, "%d", website_info.response_code);
            printf("Website URL: %s\n", website_url);
            printf("Status Code: %s\n", website_info.status_code);
            printf("Response Code: %s\n", website_info.response_code);
            printf("Response Body:\n%s\n", website_info.response_body);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}