//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

#define BUFLEN 1024

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        fprintf(stderr, "Failed to reallocate memory\n");
        return 0;
    }
    
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';
    
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    char *url = "https://jsonplaceholder.typicode.com/posts";
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Failed to initialize curl\n");
        return 1;
    }
    
    chunk.memory = malloc(BUFLEN);
    if (chunk.memory == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }
    
    chunk.size = 0;
    
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
    
    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "Failed to perform curl request: %s\n", curl_easy_strerror(res));
        return 1;
    }
    
    printf("Response:\n%s\n", chunk.memory);
    
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    
    free(chunk.memory);
    
    return 0;
}