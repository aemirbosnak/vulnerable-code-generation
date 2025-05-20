//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 4096

// Structure to hold the response data
struct MemoryStruct {
    char* memory;
    size_t size;
};

// Callback function to write data into the MemoryStruct
size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, struct MemoryStruct* userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;  // Out of memory
    }
    
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;  // Null terminate the string
    
    return realsize;
}

// Function to perform a GET request
void performGetRequest(const char* url) {
    CURL* curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;  // Initial size

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", chunk.memory);
        }
    
        // Cleanup
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }
    curl_global_cleanup();
}

// Function to perform a POST request
void performPostRequest(const char* url, const char* postData) {
    CURL* curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;  // Initial size

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", chunk.memory);
        }
    
        // Cleanup
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }
    curl_global_cleanup();
}

int main(void) {
    char url[BUFFER_SIZE];
    int choice;
    char postData[BUFFER_SIZE];

    printf("Simple HTTP Client\n");
    printf("Choose the type of request:\n");
    printf("1. GET Request\n");
    printf("2. POST Request\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character

    if (choice == 1) {
        printf("Enter URL for GET request: ");
        fgets(url, sizeof(url), stdin);
        // Remove the newline character
        url[strcspn(url, "\n")] = 0;
        performGetRequest(url);
    } else if (choice == 2) {
        printf("Enter URL for POST request: ");
        fgets(url, sizeof(url), stdin);
        // Remove the newline character
        url[strcspn(url, "\n")] = 0;
        printf("Enter data to POST: ");
        fgets(postData, sizeof(postData), stdin);
        // Remove the newline character
        postData[strcspn(postData, "\n")] = 0;
        performPostRequest(url, postData);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}