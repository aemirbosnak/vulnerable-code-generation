//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 100
#define MAX_RESPONSE_LENGTH 1000

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if(ptr == NULL) {
        printf("Error: Not enough memory to store the server response.\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';

    return realsize;
}

int main()
{
    CURL *curl;
    CURLcode res;

    char url[MAX_URL_LENGTH];
    printf("Enter the URL: ");
    scanf("%s", url);

    struct MemoryStruct server_response;
    server_response.memory = malloc(1);
    server_response.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&server_response);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            printf("Error: Could not connect to the server.\n");
        else {
            printf("Server response:\n%s\n", server_response.memory);
            printf("\nServer is up and running!\n");
        }

        curl_easy_cleanup(curl);
    }

    free(server_response.memory);
    curl_global_cleanup();

    return 0;
}