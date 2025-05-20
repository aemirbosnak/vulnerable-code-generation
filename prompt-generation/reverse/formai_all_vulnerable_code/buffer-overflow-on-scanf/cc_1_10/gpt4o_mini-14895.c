//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Struct for response data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write response data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL).\n");
        return 0;
    }

    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;

    return realsize;
}

// Function to perform GET request
void http_get(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        printf("Received data (GET request):\n%s\n", chunk.memory);

        curl_easy_cleanup(curl);
    }

    free(chunk.memory);
    curl_global_cleanup();
}

// Function to perform POST request
void http_post(const char *url, const char *post_fields) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        printf("Received data (POST request):\n%s\n", chunk.memory);

        curl_easy_cleanup(curl);
    }

    free(chunk.memory);
    curl_global_cleanup();
}

// Main function to demonstrate GET and POST
int main() {
    char option;
    char url[256];
    char post_fields[256];

    printf("Simple HTTP Client\n");
    printf("Please choose an option:\n");
    printf("1. GET\n");
    printf("2. POST\n");
    printf("Enter your choice (1/2): ");
    scanf(" %c", &option);

    switch (option) {
        case '1':
            printf("Enter URL for GET request: ");
            scanf("%s", url);
            http_get(url);
            break;

        case '2':
            printf("Enter URL for POST request: ");
            scanf("%s", url);
            printf("Enter post fields (key=value): ");
            scanf("%s", post_fields);
            http_post(url, post_fields);
            break;

        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}