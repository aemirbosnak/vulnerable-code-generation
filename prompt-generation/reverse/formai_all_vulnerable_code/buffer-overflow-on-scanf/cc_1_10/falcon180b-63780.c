//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 2048
#define MAX_RESPONSE_LEN 2048

// Callback function for writing response data to a buffer
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* buffer = (char*)malloc(realsize + 1);
    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, contents, realsize);
    buffer[realsize] = '\0';
    *(char**)userp = buffer;
    return realsize;
}

// Function to check if a URL is reachable
int CheckURL(char* url) {
    CURL* curl;
    CURLcode res;
    char response[MAX_RESPONSE_LEN];
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    if (strstr(response, "200 OK")!= NULL) {
        return 1;
    }
    return 0;
}

// Main function
int main() {
    char url[MAX_URL_LEN];
    while (1) {
        printf("Enter URL to monitor (leave blank to exit): ");
        scanf("%s", url);
        if (strcmp(url, "") == 0) {
            break;
        }
        if (CheckURL(url)) {
            printf("%s is reachable.\n", url);
        } else {
            printf("%s is not reachable.\n", url);
        }
        sleep(60); // Wait for 60 seconds before checking again
    }
    return 0;
}