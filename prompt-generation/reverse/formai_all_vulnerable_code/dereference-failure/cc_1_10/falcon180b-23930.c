//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    char* buffer = (char*)userp;
    size_t buffer_size = BUFFER_SIZE;
    strncat(buffer, (char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <http://example.com> <output.txt>\n", argv[0]);
        return 1;
    }

    char* url = argv[1];
    char* output_file = argv[2];

    FILE* fp = fopen(output_file, "wb");
    if (!fp) {
        printf("Error opening output file.\n");
        return 1;
    }

    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Error performing request: %s\n", curl_easy_strerror(res));
        } else {
            printf("Request completed successfully.\n");
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }

    curl_global_cleanup();
    return 0;
}