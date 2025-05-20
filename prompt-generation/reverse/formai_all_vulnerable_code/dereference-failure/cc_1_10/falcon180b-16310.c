//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Callback function to handle response data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *data = malloc(realsize + 1);
    memcpy(data, contents, realsize);
    data[realsize] = '\0';
    printf("%s", data);
    free(data);
    return realsize;
}

// Recursive function to make HTTP request
void HttpRequest(char *url, int depth) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    } else {
        fprintf(stderr, "curl_easy_init() failed\n");
    }
}

// Main function to start HTTP request
int main(int argc, char **argv) {
    char url[100];
    int depth = 1;

    // Check if URL is provided as command-line argument
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Copy URL from command-line argument
    strcpy(url, argv[1]);

    // Make HTTP request
    HttpRequest(url, depth);

    return 0;
}