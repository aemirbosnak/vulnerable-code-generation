//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048
#define MAX_RESPONSE_LENGTH 1024*1024

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*)contents;
    FILE* fp = (FILE*)userp;
    return fwrite(data, realsize, 1, fp);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <method> <url> <output_file>\n", argv[0]);
        return 1;
    }

    CURL* curl;
    CURLcode res;
    FILE* fp;
    char url[MAX_URL_LENGTH];
    char method[10];

    strcpy(method, argv[1]);
    strcpy(url, argv[2]);

    fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error initializing curl.\n");
        return 1;
    }

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, method);
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Error performing curl request: %s\n", curl_easy_strerror(res));
        return 1;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    fclose(fp);
    return 0;
}