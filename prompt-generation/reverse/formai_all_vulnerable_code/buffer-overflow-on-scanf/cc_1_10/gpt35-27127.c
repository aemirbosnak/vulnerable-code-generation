//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH (1024 * 1024)
#define MAX_ERROR_LENGTH 1024

struct MemoryStruct {
    char *memory;
    size_t size;
};

size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)data;

    mem->memory = (char *)realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        /* out of memory! */
        printf("Not enough memory to store website response.");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

int CheckWebsiteAvailability(char *url, char *error) {
    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;

    chunk.memory = (char *)malloc(1);
    chunk.size = 0;

    curl = curl_easy_init();
    if (curl) {
        /* set the URL */
        curl_easy_setopt(curl, CURLOPT_URL, url);

        /* follow redirects (301, 302) */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* set timeout */
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

        /* send all data to this function  */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

        /* we pass our 'chunk' struct to the callback function */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        /* some servers don't like requests that are made without a user-agent
         * field, so we provide one */
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

        /* cleanup curl stuff */
        curl_easy_cleanup(curl);

        /* Check for errors */
        if (res != CURLE_OK) {
            snprintf(error, MAX_ERROR_LENGTH, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return 0;
        }
        else {
            return 1;
        }
    }

    snprintf(error, MAX_ERROR_LENGTH, "Unable to initialize CURL");
    return 0;
}

int main(void) {
    char website_url[MAX_URL_LENGTH];
    char error[MAX_ERROR_LENGTH];

    while (1) {
        printf("Enter website URL to monitor: ");
        scanf("%s", website_url);

        if (strlen(website_url) == 0) {
            break;
        }

        if (CheckWebsiteAvailability(website_url, error)) {
            printf("Website is up.\n");
        }
        else {
            printf("Error: %s\n", error);
        }

        printf("\n");
    }

    return 0;
}