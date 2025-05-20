//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 2048
#define MAX_DATA_LEN 1024*1024

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*) contents;
    FILE* file = (FILE*) userp;
    return fwrite(data, realsize, 1, file);
}

int main() {
    CURL* curl;
    FILE* file;
    CURLcode res;
    long response_code;
    char url[MAX_URL_LEN];
    char data[MAX_DATA_LEN];

    printf("Enter the URL to test: ");
    scanf("%s", url);

    file = fopen("speedtest.txt", "wb");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();

        fclose(file);

        printf("Speed test complete! Results saved to speedtest.txt\n");
    } else {
        printf("curl_easy_init() failed\n");
    }

    return 0;
}