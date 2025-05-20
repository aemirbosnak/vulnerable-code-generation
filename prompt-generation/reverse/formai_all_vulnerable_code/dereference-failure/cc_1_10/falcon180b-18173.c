//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*10

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *response = (char*)userp;
    size_t response_len = strlen(response);
    strncat(response, (char*)contents, size*nmemb);
    return size*nmemb;
}

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN];
    strcpy(url, argv[1]);

    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)url);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK){
            printf("Error: %s\n", curl_easy_strerror(res));
        }else{
            printf("Response: %s\n", url);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }else{
        printf("Error: Failed to initialize curl\n");
    }

    return 0;
}