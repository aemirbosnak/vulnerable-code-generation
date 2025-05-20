//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

// Callback function to handle response data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[strlen((char *)userp)] = '\0';
    return size * nmemb;
}

// Callback function to handle response headers
size_t HeaderCallback(char *buffer, size_t size, size_t nmemb, void *userp)
{
    char *header = (char *)malloc(size * nmemb);
    strncpy(header, buffer, size * nmemb);
    printf("HTTP/1.1 %s\r\n", header);
    free(header);
    return size * nmemb;
}

// Function to check if a website is up
int CheckWebsite(char *url)
{
    CURL *curl;
    CURLcode res;
    char response[5000];
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, HeaderCallback);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    if(strcmp(response, "OK") == 0)
        return 1;
    else
        return 0;
}

int main()
{
    char url[100];
    printf("Enter the URL to check: ");
    scanf("%s", url);

    if(CheckWebsite(url) == 1)
        printf("%s is up\n", url);
    else
        printf("%s is down\n", url);

    return 0;
}